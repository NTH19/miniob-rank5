/* Copyright (c) 2021 Xie Meiyi(xiemeiyi@hust.edu.cn) and OceanBase and/or its affiliates. All rights reserved.
miniob is licensed under Mulan PSL v2.
You can use this software according to the terms and conditions of the Mulan PSL v2.
You may obtain a copy of Mulan PSL v2 at:
         http://license.coscl.org.cn/MulanPSL2
THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
See the Mulan PSL v2 for more details. */

//
// Created by WangYunlai on 2022/07/05.
//

#include <regex>

#include "sql/expr/tuple_cell.h"
#include "storage/common/field.h"
#include "common/log/log.h"
#include "util/comparator.h"
#include "util/util.h"

void TupleCell::to_string(std::ostream &os) const//only text need thistable
{
  switch (attr_type_) {
  case INTS: {
    os << *(int *)data_;
  } break;
  case FLOATS: {
    float v = *(float *)data_;
    os << double2string(v);
  } break;
  case CHARS: {
    for (int i = 0; i < length_; i++) {
      if (data_[i] == '\0') {
        break;
      }
      os << data_[i];
    }
  } break;
  case DATES:{
    std::string s=std::to_string(*(int*)data_);
    os<<s.substr(0,4)<<"-"<<s.substr(4,2)<<"-"<<s.substr(6,2);
  }break;
  case TEXTS:{
    os<<(char*)data_;
  }break;
  default: {
    LOG_WARN("unsupported attr type: %d", attr_type_);
  } break;
  }
}
void memcp_for_max(void* dst,void* cmp,int accro){
  if(accro>0)memcpy(dst,cmp,4);
}
void memcp_for_min(void* dst,void* cmp,int accro){
  if(accro<0)memcpy(dst,cmp,4);
}
void TupleCell::do_aggfun(int &ret,DescribeFun des,int& char_len)const {
  int res=0;
  if(des==COUNT)return;
  switch (this->attr_type_) {
  case INTS: res= compare_int(this->data_, (void*)&ret);break;
  case FLOATS: res= compare_float(this->data_, (void*)&ret);break;
  case DATES: res= compare_int(this->data_, (void*)&ret);break;
  case CHARS: res=compare_string(this->data_, this->length_, (void*)&ret,char_len);
  break;
  }
  //to do :reduce the code
  if(this->attr_type_==CHARS){
    switch (des)
    {
    case MAX:
      ret=res>0?*(int*)this->data_:ret;
      char_len=ret==*(int*)this->data_?this->length_:char_len;
      break;
    case MIN:
      ret=res<0?*(int*)this->data_:ret;
      char_len=ret==*(int*)this->data_?this->length_:char_len;
      break;
    }
    return;
  }
  switch (des)
  {
  case MAX:
    memcp_for_max(&ret,this->data_,res);
    break;
  case MIN:
    memcp_for_min(&ret,this->data_,res);
    break;
  case AVG:
    switch (this->attr_type_)
    {
    case FLOATS:
      *(float*)&ret += *(float*)this->data_;
      break;
    case INTS:
      *(float*)&ret += *(int*)this->data_;
      break;
    }
    break;
  case SUM:
    switch (this->attr_type_)
    {
    case FLOATS:
      *(float*)&ret += *(float*)this->data_;
      break;
    case INTS:
      ret += *(int*)this->data_;
      break;
    }
    break;
  }
}
int TupleCell::compare(const TupleCell &other) const
{
  if (this->attr_type_ == other.attr_type_) {
    switch (this->attr_type_) {
    case INTS: return compare_int(this->data_, other.data_);
    case FLOATS: return compare_float(this->data_, other.data_);
    case CHARS: return compare_string(this->data_, this->length_, other.data_, other.length_);
    case DATES: return compare_int(this->data_, other.data_);
    default: {
      LOG_WARN("unsupported type: %d", this->attr_type_);
    }
    }
  } else if (this->attr_type_ == INTS && other.attr_type_ == FLOATS) {
    float this_data = *(int *)data_;
    return compare_float(&this_data, other.data_);
  } else if (this->attr_type_ == FLOATS && other.attr_type_ == INTS) {
    float other_data = *(int *)other.data_;
    return compare_float(data_, &other_data);
  } else if (this->attr_type_ == CHARS && other.attr_type_ == INTS) {
    std::string num(this->data_, this->length_);
    float this_val = atof(num.c_str());
    float other_val = *(int *)other.data_;
    return compare_float(&this_val, &other_val);
  } else if (this->attr_type_ == INTS && other.attr_type_ == CHARS) {
    float this_val = *(int *)this->data_;
    std::string num(other.data_, other.length_);
    float other_val = atof(num.c_str());
    return compare_float(&this_val, &other_val);
  } else if (this->attr_type_ == CHARS && other.attr_type_ == FLOATS) {
    std::string num(this->data_, this->length_);
    float val = atof(num.c_str());
    return compare_float(&val, other.data_);
  } else if (this->attr_type_ == FLOATS && other.attr_type_ == CHARS) {
    std::string num(other.data_, other.length_);
    float val = atof(num.c_str());
    return compare_float(this->data_, &val);
  } 


  LOG_WARN("not supported");
  return -1; // TODO return rc?
}

// "abc" like "_b%"
bool TupleCell::like(const TupleCell &other) const
{
  if (this->attr_type_ != other.attr_type_ || this->attr_type_ != CHARS) {
    LOG_WARN("not supported");
    return false;
  }

  std::string left = charptr2string(this->data_, this->length_);
  std::string right = charptr2string(other.data_, other.length_);
  // replace '_' -> '.', '%' -> '.*?';
  std::string::size_type pos(0);
  while((pos = right.find('_')) != std::string::npos) {
    right.replace(pos, 1, ".");
  }
  while((pos = right.find('%')) != std::string::npos) {
    right.replace(pos, 1, ".*?");
  }
  std::regex reg(right);
  return std::regex_match(left, reg);
}
