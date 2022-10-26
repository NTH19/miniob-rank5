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
// Created by Meiyi & Longda on 2021/4/13.
//

#include <string>
#include <sstream>

#include "execute_stage.h"

#include "common/io/io.h"
#include "common/log/log.h"
#include "common/lang/defer.h"
#include "common/seda/timer_stage.h"
#include "common/lang/string.h"
#include "session/session.h"
#include "event/storage_event.h"
#include "event/sql_event.h"
#include "event/session_event.h"
#include "sql/expr/tuple.h"
#include "sql/operator/table_scan_operator.h"
#include "sql/operator/index_scan_operator.h"
#include "sql/operator/predicate_operator.h"
#include "sql/operator/delete_operator.h"
#include "sql/operator/project_operator.h"
#include "sql/operator/update_operator.h"
#include "sql/stmt/stmt.h"
#include "sql/stmt/select_stmt.h"
#include "sql/stmt/update_stmt.h"
#include "sql/stmt/delete_stmt.h"
#include "sql/stmt/insert_stmt.h"
#include "sql/stmt/filter_stmt.h"
#include "storage/common/table.h"
#include "storage/common/field.h"
#include "storage/index/index.h"
#include "storage/default/default_handler.h"
#include "storage/common/condition_filter.h"
#include "storage/trx/trx.h"
#include <algorithm>
#include "storage/clog/clog.h"

using namespace common;

// RC create_selection_executor(
//    Trx *trx, const Selects &selects, const char *db, const char *table_name, SelectExeNode &select_node);

//! Constructor
ExecuteStage::ExecuteStage(const char *tag) : Stage(tag)
{}

//! Destructor
ExecuteStage::~ExecuteStage()
{}

//! Parse properties, instantiate a stage object
Stage *ExecuteStage::make_stage(const std::string &tag)
{
  ExecuteStage *stage = new (std::nothrow) ExecuteStage(tag.c_str());
  if (stage == nullptr) {
    LOG_ERROR("new ExecuteStage failed");
    return nullptr;
  }
  stage->set_properties();
  return stage;
}

//! Set properties for this object set in stage specific properties
bool ExecuteStage::set_properties()
{
  //  std::string stageNameStr(stageName);
  //  std::map<std::string, std::string> section = theGlobalProperties()->get(
  //    stageNameStr);
  //
  //  std::map<std::string, std::string>::iterator it;
  //
  //  std::string key;

  return true;
}

//! Initialize stage params and validate outputs
bool ExecuteStage::initialize()
{
  LOG_TRACE("Enter");

  std::list<Stage *>::iterator stgp = next_stage_list_.begin();
  default_storage_stage_ = *(stgp++);
  mem_storage_stage_ = *(stgp++);

  LOG_TRACE("Exit");
  return true;
}

//! Cleanup after disconnection
void ExecuteStage::cleanup()
{
  LOG_TRACE("Enter");

  LOG_TRACE("Exit");
}

void ExecuteStage::handle_event(StageEvent *event)
{
  LOG_TRACE("Enter\n");

  handle_request(event);

  LOG_TRACE("Exit\n");
  return;
}

void ExecuteStage::callback_event(StageEvent *event, CallbackContext *context)
{
  LOG_TRACE("Enter\n");

  // here finish read all data from disk or network, but do nothing here.

  LOG_TRACE("Exit\n");
  return;
}

void ExecuteStage::handle_request(common::StageEvent *event)
{
  SQLStageEvent *sql_event = static_cast<SQLStageEvent *>(event);
  SessionEvent *session_event = sql_event->session_event();
  Stmt *stmt = sql_event->stmt();
  Session *session = session_event->session();
  Query *sql = sql_event->query();

  if (stmt != nullptr) {
    switch (stmt->type()) {
      case StmtType::SELECT: {
        do_select(sql_event);
      } break;
      case StmtType::INSERT: {
        do_insert(sql_event);
      } break;
      case StmtType::UPDATE: {
        do_update((UpdateStmt *)stmt, session_event);
      } break;
      case StmtType::DELETE: {
        do_delete(sql_event);
      } break;
      default: {
        LOG_WARN("should not happen. please implenment");
      } break;
    }
  } else {
    switch (sql->flag) {
      case SCF_HELP: {
        do_help(sql_event);
      } break;
      case SCF_CREATE_TABLE: {
        do_create_table(sql_event);
      } break;
      case SCF_CREATE_INDEX: {
        do_create_index(sql_event);
      } break;
      case SCF_SHOW_TABLES: {
        do_show_tables(sql_event);
      } break;
      case SCF_SHOW_INDEXES: {
        do_show_indexes(sql_event);
      } break;
      case SCF_DESC_TABLE: {
        do_desc_table(sql_event);
      } break;

      case SCF_DROP_TABLE:
        do_drop_table(sql_event);
        break;
      case SCF_DROP_INDEX:
      case SCF_LOAD_DATA: {
        default_storage_stage_->handle_event(event);
      } break;
      case SCF_SYNC: {
        /*
        RC rc = DefaultHandler::get_default().sync();
        session_event->set_response(strrc(rc));
        */
      } break;
      case SCF_BEGIN: {
        do_begin(sql_event);
        /*
        session_event->set_response("SUCCESS\n");
        */
      } break;
      case SCF_COMMIT: {
        do_commit(sql_event);
        /*
        Trx *trx = session->current_trx();
        RC rc = trx->commit();
        session->set_trx_multi_operation_mode(false);
        session_event->set_response(strrc(rc));
        */
      } break;
      case SCF_CLOG_SYNC: {
        do_clog_sync(sql_event);
      }
      case SCF_ROLLBACK: {
        Trx *trx = session_event->get_client()->session->current_trx();
        RC rc = trx->rollback();
        session->set_trx_multi_operation_mode(false);
        session_event->set_response(strrc(rc));
      } break;
      case SCF_EXIT: {
        // do nothing
        const char *response = "Unsupported\n";
        session_event->set_response(response);
      } break;
      default: {
        LOG_ERROR("Unsupported command=%d\n", sql->flag);
      }
    }
  }
}

void end_trx_if_need(Session *session, Trx *trx, bool all_right)
{
  if (!session->is_trx_multi_operation_mode()) {
    if (all_right) {
      trx->commit();
    } else {
      trx->rollback();
    }
  }
}

void print_tuple_header(std::ostream &os, const ProjectOperator &oper)
{
  const int cell_num = oper.tuple_cell_num();
  const TupleCellSpec *cell_spec = nullptr;
  for (int i = 0; i < cell_num; i++) {
    oper.tuple_cell_spec_at(i, cell_spec);
    if (i != 0) {
      os << " | ";
    }

    if (cell_spec->alias()) {
      os << cell_spec->alias();
    }
  }

  if (cell_num > 0) {
    os << '\n';
  }
}
void print_aggfun_header(std::ostream &os, const std::vector<std::pair<DescribeFun, Field>> &funs)
{

  for (int i = 0; i < funs.size(); i++) {
    if (i != 0)
      os << " | ";
    switch (funs[i].first) {
      case MAX:
        os << " MAX(" << funs[i].second.field_name() << ") ";
        break;
      case MIN:
        os << " MIN(" << funs[i].second.field_name() << ") ";
        break;
      case AVG:
        os << " AVG(" << funs[i].second.field_name() << ") ";
        break;
      case SUM:
        os << " SUM(" << funs[i].second.field_name() << ") ";
        break;
      case COUNT:
        os << " COUNT(" << funs[i].second.field_name() << ") ";
        break;
      case COUNT_STAR:
        os << " COUNT(*)";
        break;
    }
  }
  os << '\n';
}

void tuple_to_string(std::ostream &os, const Tuple &tuple)
{
  TupleCell cell;
  RC rc = RC::SUCCESS;
  bool first_field = true;
  for (int i = 0; i < tuple.cell_num(); i++) {
    rc = tuple.cell_at(i, cell);
    if (rc != RC::SUCCESS) {
      LOG_WARN("failed to fetch field of cell. index=%d, rc=%s", i, strrc(rc));
      break;
    }

    if (!first_field) {
      os << " | ";
    } else {
      first_field = false;
    }

    cell.to_string(os);
  }
}

IndexScanOperator *try_to_create_index_scan_operator(FilterStmt *filter_stmt)
{
  const std::vector<FilterUnit *> &filter_units = filter_stmt->filter_units();
  if (filter_units.empty()) {
    return nullptr;
  }

  // 在所有过滤条件中，找到字段与值做比较的条件，然后判断字段是否可以使用索引
  // 如果是多列索引，这里的处理需要更复杂。
  // 这里的查找规则是比较简单的，就是尽量找到使用相等比较的索引
  // 如果没有就找范围比较的，但是直接排除不等比较的索引查询. (你知道为什么?)
  const FilterUnit *better_filter = nullptr;
  for (const FilterUnit *filter_unit : filter_units) {
    if (filter_unit->comp() == NOT_EQUAL) {
      continue;
    }

    Expression *left = filter_unit->left();
    Expression *right = filter_unit->right();
    if (left->type() == ExprType::FIELD && right->type() == ExprType::VALUE) {
    } else if (left->type() == ExprType::VALUE && right->type() == ExprType::FIELD) {
      std::swap(left, right);
    } else {
      continue;
    }

    FieldExpr &left_field_expr = *(FieldExpr *)left;
    const Field &field = left_field_expr.field();
    const Table *table = field.table();
    Index *index = table->find_index_by_field(field.field_name());
    if (index != nullptr) {
      if (better_filter == nullptr) {
        better_filter = filter_unit;
      } else if (filter_unit->comp() == EQUAL_TO) {
        better_filter = filter_unit;
        break;
      }
    }
  }

  if (better_filter == nullptr) {
    return nullptr;
  }

  Expression *left = better_filter->left();
  Expression *right = better_filter->right();
  CompOp comp = better_filter->comp();
  if (left->type() == ExprType::VALUE && right->type() == ExprType::FIELD) {
    std::swap(left, right);
    switch (comp) {
      case EQUAL_TO: {
        comp = EQUAL_TO;
      } break;
      case LESS_EQUAL: {
        comp = GREAT_THAN;
      } break;
      case NOT_EQUAL: {
        comp = NOT_EQUAL;
      } break;
      case LESS_THAN: {
        comp = GREAT_EQUAL;
      } break;
      case GREAT_EQUAL: {
        comp = LESS_THAN;
      } break;
      case GREAT_THAN: {
        comp = LESS_EQUAL;
      } break;
      default: {
        LOG_WARN("should not happen");
      }
    }
  }

  FieldExpr &left_field_expr = *(FieldExpr *)left;
  const Field &field = left_field_expr.field();
  const Table *table = field.table();
  Index *index = table->find_index_by_field(field.field_name());
  assert(index != nullptr);

  ValueExpr &right_value_expr = *(ValueExpr *)right;
  TupleCell value;
  right_value_expr.get_tuple_cell(value);

  const TupleCell *left_cell = nullptr;
  const TupleCell *right_cell = nullptr;
  bool left_inclusive = false;
  bool right_inclusive = false;

  switch (comp) {
    case EQUAL_TO: {
      left_cell = &value;
      right_cell = &value;
      left_inclusive = true;
      right_inclusive = true;
    } break;

    case LESS_EQUAL: {
      left_cell = nullptr;
      left_inclusive = false;
      right_cell = &value;
      right_inclusive = true;
    } break;

    case LESS_THAN: {
      left_cell = nullptr;
      left_inclusive = false;
      right_cell = &value;
      right_inclusive = false;
    } break;

    case GREAT_EQUAL: {
      left_cell = &value;
      left_inclusive = true;
      right_cell = nullptr;
      right_inclusive = false;
    } break;

    case GREAT_THAN: {
      left_cell = &value;
      left_inclusive = false;
      right_cell = nullptr;
      right_inclusive = false;
    } break;

    default: {
      LOG_WARN("should not happen. comp=%d", comp);
    } break;
  }

  IndexScanOperator *oper = new IndexScanOperator(table, index, left_cell, left_inclusive, right_cell, right_inclusive);

  LOG_INFO("use index for scan: %s in table %s", index->index_meta().name(), table->name());
  return oper;
}
void do_aggfun(std::vector<int> &ret, std::vector<int> &char_len, const Tuple &tuple,
    const std::vector<std::pair<DescribeFun, Field>> &funs)
{
  TupleCell cell;
  RC rc = RC::SUCCESS;
  for (int i = 0; i < tuple.cell_num(); i++) {
    rc = tuple.cell_at(i, cell);
    if (rc != RC::SUCCESS) {
      LOG_WARN("failed to fetch field of cell. index=%d, rc=%s", i, strrc(rc));
      break;
    }
    cell.do_aggfun(ret[i], funs[i].first, char_len[i]);
  }
}
void gen_result(std::vector<int> &ret, const std::vector<std::pair<DescribeFun, Field>> &funs, std::ostream &os,
    int cnt, std::vector<int> &char_len)
{
  bool is_first = true;
  for (int i = 0; i < ret.size(); ++i) {
    if (is_first) {
      is_first = false;
    } else
      os << " | ";
    if (funs[i].first == AVG) {
      os << (*(float *)&ret[i]) / cnt;
      continue;
    }
    if (funs[i].first == COUNT || funs[i].first == COUNT_STAR) {
      os << cnt;
      continue;
    }
    switch (funs[i].second.attr_type()) {
      case FLOATS:
        os << *(float *)&ret[i];
        break;
      case INTS:
        os << ret[i];
        break;
      case CHARS:
        os << std::string((char *)&ret[i], char_len[i]);
        break;
    }
  }
  os << "\n";
}
void init_ret_aggfun(
    std::vector<int> &ret, const std::vector<std::pair<DescribeFun, Field>> &funs, std::vector<int> &char_len)
{
  int n = ret.size();
  for (int i = 0; i < n; ++i) {
    if (funs[i].first == MIN) {
      if (funs[i].second.attr_type() == CHARS) {
        memset(&ret[i], 127, 4);
        char_len[i] = 3;
      } else if (funs[i].second.attr_type() == FLOATS) {
        *(float *)&ret[i] = 99999999;
      } else if (funs[i].second.attr_type() == INTS) {
        ret[i] = INT32_MAX;
      }
    } else if (funs[i].first == MAX) {
      if (funs[i].second.attr_type() == CHARS) {
        memset(&ret[i], 0, 4);
        char_len[i] = 3;
      } else if (funs[i].second.attr_type() == FLOATS) {
        *(float *)&ret[i] = 0;
      } else if (funs[i].second.attr_type() == INTS) {
        ret[i] = -100000;
      }
    } else if (funs[i].first == SUM || funs[i].first == AVG) {
      ret[i] = 0;
    }
  }
}
void p_mutiple_table_header(std::ostream &os, std::vector<ProjectOperator> &p, bool need_reverse)
{
  int j = 0;
  int n = p.size();
  if (need_reverse) {
    for (int k = n - 1; k >= 0; --k) {
      const int cell_num = p[k].tuple_cell_num();
      const TupleCellSpec *cell_spec = nullptr;
      if (j) {
        os << " | ";
      }
      j++;
      for (int i = 0; i < cell_num; i++) {
        p[k].tuple_cell_spec_at(i, cell_spec);
        if (i != 0) {
          os << " | ";
        }
        if (cell_spec->alias()) {
          os << cell_spec->alias();
        }
      }
    }
  } else {
    for (int k = 0; k < n; ++k) {
      const int cell_num = p[k].tuple_cell_num();
      const TupleCellSpec *cell_spec = nullptr;
      if (j) {
        os << " | ";
      }
      j++;
      for (int i = 0; i < cell_num; i++) {
        p[k].tuple_cell_spec_at(i, cell_spec);
        if (i != 0) {
          os << " | ";
        }
        if (cell_spec->alias()) {
          os << cell_spec->alias();
        }
      }
    }
  }

  os << "\n";
}
bool gen_compare_res(TupleCell &l, TupleCell &r, CompOp &cmp)
{
  bool canAdd = false;

  const int compare = l.compare(r);
  bool filter_result;
  switch (cmp) {
    case EQUAL_TO: {
      filter_result = (0 == compare);
    } break;
    case LESS_EQUAL: {
      filter_result = (compare <= 0);
    } break;
    case NOT_EQUAL: {
      filter_result = (compare != 0);
    } break;
    case LESS_THAN: {
      filter_result = (compare < 0);
    } break;
    case GREAT_EQUAL: {
      filter_result = (compare >= 0);
    } break;
    case GREAT_THAN: {
      filter_result = (compare > 0);
    } break;
  }
  return filter_result;
}
void dfs(std::vector<Table *> &tables, int step, const std::vector<Field> query_fields, RowTuple *lastTuple,
    std::string lastRes, std::string &res,
    std::map<std::pair<std::string, std::string>, std::vector<std::tuple<FieldExpr *, FieldExpr *, CompOp>>> &mtoF,
    std::map<std::string, ProjectOperator *> &tableToProject, FilterStmt *filter, bool needJoin,
    std::vector<RowTuple *> &tuples)
{
  auto scan_oper = new TableScanOperator(tables[step]);
  auto pred_oper = new PredicateOperator(filter);
  pred_oper->add_child(scan_oper);
  pred_oper->open();
  std::string nowTablename(tables[step]->name());
  while (pred_oper->next() == RC::SUCCESS) {
    RowTuple *tuple = dynamic_cast<RowTuple *>(pred_oper->current_tuple());
    if (nullptr == tuple) {
      LOG_ERROR("DFS empty\n!!!!!");
      break;
    }
    bool canAdd = false;
    if (needJoin) {
      canAdd = true;
      for (int i = 0; i < step; ++i) {
        if (mtoF.count(std::pair<std::string, std::string>(std::string(tables[i]->name()), nowTablename))) {
          auto ve = mtoF[std::pair<std::string, std::string>(std::string(tables[i]->name()), nowTablename)];
          for (auto &x : ve) {
            auto [l, r, cmp] = x;
            TupleCell left_cell;
            TupleCell right_cell;
            if (l->get_value(*tuples[i], left_cell) == RC::NOTFOUND)
              continue;
            if (r->get_value(*tuple, right_cell) == RC::NOTFOUND)
              continue;
            if (!gen_compare_res(left_cell, right_cell, cmp)) {
              canAdd = false;
              break;
            }
          }

        } else if (mtoF.count(std::pair<std::string, std::string>(std::string(nowTablename), tables[i]->name()))) {
          auto ve = mtoF[std::pair<std::string, std::string>(nowTablename, tables[i]->name())];
          for (auto &v : ve) {
            auto [l, r, cmp] = v;
            TupleCell left_cell;
            TupleCell right_cell;
            if (l->get_value(*tuple, left_cell) == RC::NOTFOUND)
              continue;
            if (r->get_value(*tuples[i], right_cell) == RC::NOTFOUND)
              continue;
            if (!gen_compare_res(left_cell, right_cell, cmp)) {
              canAdd = false;
              break;
            }
          }
        }
      }
    } else
      canAdd = true;
    if (canAdd) {
      ProjectTuple *p2;
      std::stringstream kl;
      if (tableToProject.count(nowTablename)) {
        p2 = dynamic_cast<ProjectTuple *>(tableToProject[nowTablename]->for_mu_tables());
        p2->set_tuple(tuple);
        tuple_to_string(kl, *p2);
        std::string temp(kl.str());
        if (step != tables.size() - 1) {
          tuples.push_back(tuple);
          dfs(tables,
              step + 1,
              query_fields,
              tuple,
              lastRes + (step == 0 ? "" : " | ") + temp,
              res,
              mtoF,
              tableToProject,
              filter,
              needJoin,
              tuples);
          tuples.pop_back();
        } else
          res = res + lastRes + ((step == 0 || lastRes.size() == 0) ? "" : " | ") + temp + "\n";
      } else {
        if (step != tables.size() - 1) {
          tuples.push_back(tuple);
          dfs(tables, step + 1, query_fields, tuple, lastRes, res, mtoF, tableToProject, filter, needJoin, tuples);
          tuples.pop_back();
        } else
          res = res + lastRes + "\n";
      }
    }
  }
  pred_oper->close();
  delete pred_oper;
  delete scan_oper;
}
RC ExecuteStage::do_select(SQLStageEvent *sql_event)
{
  SelectStmt *select_stmt = (SelectStmt *)(sql_event->stmt());
  SessionEvent *session_event = sql_event->session_event();
  RC rc = RC::SUCCESS;
  // select mutiple tables happens here
  if (select_stmt->tables().size() > 1) {
    auto tables = select_stmt->tables();
    std::reverse(tables.begin(), tables.end());
    auto cons = select_stmt->filter_stmt()->filter_units();
    FieldExpr *left_attr;
    FieldExpr *right_attr;
    std::map<std::pair<std::string, std::string>, std::vector<std::tuple<FieldExpr *, FieldExpr *, CompOp>>> mtoF;
    bool need_join = false;
    for (int i = 0; i < cons.size(); ++i) {
      if (dynamic_cast<FieldExpr *>(cons[i]->left()) != 0 && dynamic_cast<FieldExpr *>(cons[i]->right()) != 0) {
        left_attr = dynamic_cast<FieldExpr *>(cons[i]->left());
        right_attr = dynamic_cast<FieldExpr *>(cons[i]->right());
        need_join = true;
        mtoF[std::pair<std::string, std::string>(left_attr->table_name(), right_attr->table_name())].push_back(
            std::tuple<FieldExpr *, FieldExpr *, CompOp>(left_attr, right_attr, cons[i]->comp()));
      }
    }

    if (rc != RC::SUCCESS) {
      LOG_WARN("failed to open operator");
      return rc;
    }
    std::stringstream ss;
    std::vector<ProjectOperator> project_oper(10);
    auto &query_fields = select_stmt->query_fields();
    std::map<std::string, ProjectOperator *> m;
    int accuse;
    for (int i = 0, j = 0; i < query_fields.size(); ++i) {
      if (i && query_fields[i].table_name() != query_fields[i - 1].table_name()) {
        j++;
      }
      accuse = j;
      project_oper[j].add_projection(query_fields[i].table(), query_fields[i].meta(), true);
      m[std::string(query_fields[i].table()->name())] = &project_oper[j];
    }
    project_oper.resize(accuse + 1);
    p_mutiple_table_header(ss, project_oper, select_stmt->need_reverse);
    std::vector<RowTuple *> start;
    std::string res;
    dfs(tables, 0, query_fields, nullptr, "", res, mtoF, m, select_stmt->filter_stmt(), need_join, start);
    session_event->set_response(ss.str() + res);
    return rc;
  }

  // agg  fun happens here
  if (select_stmt->funs().size() != 0) {
    auto funs = select_stmt->funs();
    Operator *scan_oper = new TableScanOperator(select_stmt->tables()[0]);
    DEFER([&]() { delete scan_oper; });
    PredicateOperator pred_oper(select_stmt->filter_stmt());
    pred_oper.add_child(scan_oper);
    ProjectOperator project_oper;
    project_oper.add_child(&pred_oper);
    for (int i = 0; i < funs.size(); ++i) {
      project_oper.add_projection(funs[i].second.table(), funs[i].second.meta());
    }
    rc = project_oper.open();
    if (rc != RC::SUCCESS) {
      LOG_WARN("failed to open operator");
      return rc;
    }
    std::stringstream ss;
    print_aggfun_header(ss, funs);
    std::vector<int> ret(funs.size(), 0);
    std::vector<int> char_len(funs.size(), 0);
    init_ret_aggfun(ret, funs, char_len);
    int cnt = 0;
    while ((rc = project_oper.next()) == RC::SUCCESS) {
      // get current record
      // write to response
      Tuple *tuple = project_oper.current_tuple();
      if (nullptr == tuple) {
        rc = RC::INTERNAL;
        LOG_WARN("failed to get current record. rc=%s", strrc(rc));
        break;
      }
      do_aggfun(ret, char_len, *tuple, funs);
      cnt++;
    }

    if (rc != RC::RECORD_EOF) {
      LOG_WARN("something wrong while iterate operator. rc=%s", strrc(rc));
      project_oper.close();
    } else {
      rc = project_oper.close();
    }
    gen_result(ret, funs, ss, cnt, char_len);

    session_event->set_response(ss.str());
    return rc;
  }

  // check whether is valid (maybe just for date)
  for (const FilterUnit *filter_unit : select_stmt->filter_stmt()->filter_units()) {
    TupleCell cell;
    RowTuple t;
    if (dynamic_cast<ValueExpr *>(filter_unit->left())) {
      filter_unit->left()->get_value(t, cell);
      auto p = cell.data();
      if (p == nullptr) {
        session_event->set_response("FAILURE\n");
        return RC::INVALID_ARGUMENT;
      }
    }
    if (dynamic_cast<ValueExpr *>(filter_unit->right())) {
      filter_unit->right()->get_value(t, cell);
      auto p = cell.data();
      if (p == nullptr) {
        session_event->set_response("FAILURE\n");
        return RC::INVALID_ARGUMENT;
      }
    }
  }

  Operator *scan_oper = try_to_create_index_scan_operator(select_stmt->filter_stmt());
  if (nullptr == scan_oper) {
    scan_oper = new TableScanOperator(select_stmt->tables()[0]);
  }

  DEFER([&]() { delete scan_oper; });

  PredicateOperator pred_oper(select_stmt->filter_stmt());
  pred_oper.add_child(scan_oper);
  ProjectOperator project_oper;
  project_oper.add_child(&pred_oper);
  for (const Field &field : select_stmt->query_fields()) {
    project_oper.add_projection(field.table(), field.meta());
  }
  rc = project_oper.open();
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to open operator");
    return rc;
  }

  Table *thistable = select_stmt->tables()[0];
  std::stringstream ss;
  print_tuple_header(ss, project_oper);
  while ((rc = project_oper.next()) == RC::SUCCESS) {
    // get current record
    // write to response
    Tuple *tuple = project_oper.current_tuple();
    if (nullptr == tuple) {
      rc = RC::INTERNAL;
      LOG_WARN("failed to get current record. rc=%s", strrc(rc));
      break;
    }

    tuple_to_string(ss, *tuple);
    ss << std::endl;
  }

  if (rc != RC::RECORD_EOF) {
    LOG_WARN("something wrong while iterate operator. rc=%s", strrc(rc));
    project_oper.close();
  } else {
    rc = project_oper.close();
  }
  session_event->set_response(ss.str());
  return rc;
}

RC ExecuteStage::do_help(SQLStageEvent *sql_event)
{
  SessionEvent *session_event = sql_event->session_event();
  const char *response = "show tables;\n"
                         "desc `table name`;\n"
                         "create table `table name` (`column name` `column type`, ...);\n"
                         "create index `index name` on `table` (`column`);\n"
                         "insert into `table` values(`value1`,`value2`);\n"
                         "update `table` set column=value [where `column`=`value`];\n"
                         "delete from `table` [where `column`=`value`];\n"
                         "select [ * | `columns` ] from `table`;\n";
  session_event->set_response(response);
  return RC::SUCCESS;
}
RC ExecuteStage::do_drop_table(SQLStageEvent *sql_event)
{
  /*
  const CreateTable &create_table = sql_event->query()->sstr.create_table;
  SessionEvent *session_event = sql_event->session_event();
  Db *db = session_event->session()->get_current_db();
  RC rc = db->create_table(create_table.relation_name,
            create_table.attribute_count, create_table.attributes);
  if (rc == RC::SUCCESS) {
    session_event->set_response("SUCCESS\n");
  } else {
    session_event->set_response("FAILURE\n");
  }
  return rc; */
  const DropTable &drop_table = sql_event->query()->sstr.drop_table;
  SessionEvent *session_event = sql_event->session_event();
  Db *db = session_event->session()->get_current_db();
  RC rc = db->drop_table(drop_table.relation_name);
  if (rc == RC::SUCCESS) {
    session_event->set_response("SUCCESS\n");
  } else {
    session_event->set_response("FAILURE\n");
  }
  return rc;
}
RC ExecuteStage::do_create_table(SQLStageEvent *sql_event)
{
  const CreateTable &create_table = sql_event->query()->sstr.create_table;
  SessionEvent *session_event = sql_event->session_event();
  Db *db = session_event->session()->get_current_db();
  RC rc = db->create_table(create_table.relation_name, create_table.attribute_count, create_table.attributes);
  if (rc == RC::SUCCESS) {
    session_event->set_response("SUCCESS\n");
  } else {
    session_event->set_response("FAILURE\n");
  }
  return rc;
}
RC ExecuteStage::do_create_index(SQLStageEvent *sql_event)
{
  SessionEvent *session_event = sql_event->session_event();
  Db *db = session_event->session()->get_current_db();
  const CreateIndex &create_index = sql_event->query()->sstr.create_index;
  Table *table = db->find_table(create_index.relation_name);
  if (nullptr == table) {
    session_event->set_response("FAILURE\n");
    return RC::SCHEMA_TABLE_NOT_EXIST;
  }

  RC rc = table->create_index(nullptr, create_index.index_name, create_index.attribute_name, 
                              create_index.attribute_count, create_index.unique != 0);
  sql_event->session_event()->set_response(rc == RC::SUCCESS ? "SUCCESS\n" : "FAILURE\n");
  return rc;
}

RC ExecuteStage::do_show_tables(SQLStageEvent *sql_event)
{
  SessionEvent *session_event = sql_event->session_event();
  Db *db = session_event->session()->get_current_db();
  std::vector<std::string> all_tables;
  db->all_tables(all_tables);
  if (all_tables.empty()) {
    session_event->set_response("No table\n");
  } else {
    std::stringstream ss;
    for (const auto &table : all_tables) {
      ss << table << std::endl;
    }
    session_event->set_response(ss.str().c_str());
  }
  return RC::SUCCESS;
}
RC ExecuteStage::do_show_indexes(SQLStageEvent *sql_event)
{
  SessionEvent *session_event = sql_event->session_event();
  Db *db = session_event->session()->get_current_db();
  const ShowIndex &sIndex = sql_event->query()->sstr.show_index;
  Table *table = db->find_table(sIndex.relation_name);
  if (nullptr == table) {
    session_event->set_response("FAILURE\n");
    return RC::SCHEMA_TABLE_NOT_EXIST;
  }
  std::vector<std::string> ret;
  RC rc = table->show_index(ret);
  std::stringstream ss;
  for (auto &x : ret) {
    ss << x << std::endl;
  }
  session_event->set_response(ss.str().c_str());
  return rc;
}

RC ExecuteStage::do_desc_table(SQLStageEvent *sql_event)
{
  Query *query = sql_event->query();
  Db *db = sql_event->session_event()->session()->get_current_db();
  const char *table_name = query->sstr.desc_table.relation_name;
  Table *table = db->find_table(table_name);
  std::stringstream ss;
  if (table != nullptr) {
    table->table_meta().desc(ss);
  } else {
    ss << "No such table: " << table_name << std::endl;
  }
  sql_event->session_event()->set_response(ss.str().c_str());
  return RC::SUCCESS;
}

RC ExecuteStage::do_insert(SQLStageEvent *sql_event)
{
  Stmt *stmt = sql_event->stmt();
  SessionEvent *session_event = sql_event->session_event();
  Session *session = session_event->session();
  Db *db = session->get_current_db();
  Trx *trx = session->current_trx();
  CLogManager *clog_manager = db->get_clog_manager();

  if (stmt == nullptr) {
    LOG_WARN("cannot find statement");
    return RC::GENERIC_ERROR;
  }

  InsertStmt *insert_stmt = (InsertStmt *)stmt;
  Table *table = insert_stmt->table();
  int j = insert_stmt->record_num();
  for (int k = 0; k < j; k++) {
    const Value *v = insert_stmt->values_[k];
    for (int i = 0; i < insert_stmt->value_amount(); i++) {
      const Value *vm = v + i;
      if (vm->data == nullptr) {
        session_event->set_response("FAILURE\n");
        return RC::INVALID_ARGUMENT;
      }
    }
  }
  const Inserts &inserts = sql_event->query()->sstr.insertion;                      // get inserts
  int cnt = table->table_meta().field_num() - table->table_meta().sys_field_num();  // check length
  for (int i = 0, j = 0; i < inserts.record_num; i++, j = inserts.record_length[i - 1]) {
    if (inserts.record_length[i] - j != cnt) {
      LOG_ERROR("record %d has wrong length %d - %d should be %d", i, inserts.record_length[i], j, cnt);
      return RC::SCHEMA_FIELD_TYPE_MISMATCH;
    }
  }

  RC rc = table->insert_records(trx, (int)inserts.record_num, (int)inserts.value_num, inserts.values);

  if (rc == RC::SUCCESS) {
    if (!session->is_trx_multi_operation_mode()) {
      CLogRecord *clog_record = nullptr;
      rc = clog_manager->clog_gen_record(CLogType::REDO_MTR_COMMIT, trx->get_current_id(), clog_record);
      if (rc != RC::SUCCESS || clog_record == nullptr) {
        session_event->set_response("FAILURE\n");
        return rc;
      }

      rc = clog_manager->clog_append_record(clog_record);
      if (rc != RC::SUCCESS) {
        session_event->set_response("FAILURE\n");
        return rc;
      }
      end_trx_if_need(session, trx, true);
      trx->next_current_id();
    }
    session_event->set_response("SUCCESS\n");
  } else {
    session_event->set_response("FAILURE\n");
  }
  return rc;
}

void agg_result(std::vector<int> &ret, const std::vector<std::pair<DescribeFun, Field>> &funs, 
                int cnt, std::vector<int> &char_len, std::vector<Value> &out_value) {
  out_value.reserve(ret.size());

  for (int i = 0; i < ret.size(); ++i) {
    Value value;
    switch (funs[i].first) {
    case COUNT:
    case COUNT_STAR:
      value.type = INTS;
      value.data = new int(cnt);
      break;
    case AVG:
      value.type = FLOATS;
      value.data = new float((*(float *)&ret[i]) / cnt);
      break;
    default:
      switch (funs[i].second.attr_type()) {
      case FLOATS:
        value.type = FLOATS;
        value.data = new float(*(float *)&ret[i]);
        break;
      case INTS:
        value.type = INTS;
        value.data = new int(ret[i]);
        break;
      case CHARS:
        value.type = CHARS;
        char *str = new char[char_len[i] + 1];
        memcpy(str, (char *)&ret[i], char_len[i]);
        str[char_len[i] + 1] = 0;
        value.data = str;
        break;
      }
      break;
    }
    out_value.push_back(value);
  }
}

RC do_update_select(SelectStmt *select_stmt, SessionEvent *session_event, std::vector<Value> &out_value) {
  RC rc = RC::SUCCESS;
  // agg fun happens here
  if (select_stmt->funs().size() != 0) {
    auto funs = select_stmt->funs();
    if (funs.size() != 1) {
      return RC::INVALID_ARGUMENT;
    }
    Operator *scan_oper = new TableScanOperator(select_stmt->tables()[0]);
    DEFER([&]() { delete scan_oper; });
    PredicateOperator pred_oper(select_stmt->filter_stmt());
    pred_oper.add_child(scan_oper);
    ProjectOperator project_oper;
    project_oper.add_child(&pred_oper);
    for (int i = 0; i < funs.size(); ++i) {
      project_oper.add_projection(funs[i].second.table(), funs[i].second.meta());
    }
    rc = project_oper.open();
    if (rc != RC::SUCCESS) {
      LOG_WARN("failed to open operator");
      return rc;
    }

    std::vector<int> ret(funs.size(), 0);
    std::vector<int> char_len(funs.size(), 0);
    init_ret_aggfun(ret, funs, char_len);
    int cnt = 0;
    while ((rc = project_oper.next()) == RC::SUCCESS) {
      // get current record
      // write to response
      Tuple *tuple = project_oper.current_tuple();
      if (nullptr == tuple) {
        rc = RC::INTERNAL;
        LOG_WARN("failed to get current record. rc=%s", strrc(rc));
        break;
      }
      do_aggfun(ret, char_len, *tuple, funs);
      cnt++;
    }

    if (rc != RC::RECORD_EOF) {
      LOG_WARN("something wrong while iterate operator. rc=%s", strrc(rc));
      project_oper.close();
    } else {
      rc = project_oper.close();
    }
    agg_result(ret, funs, cnt, char_len, out_value);
    return rc;
  }

  Operator *scan_oper = new TableScanOperator(select_stmt->tables()[0]);
  DEFER([&]() { delete scan_oper; });

  PredicateOperator pred_oper(select_stmt->filter_stmt());
  pred_oper.add_child(scan_oper);
  ProjectOperator project_oper;
  project_oper.add_child(&pred_oper);
  for (const Field &field : select_stmt->query_fields()) {
    project_oper.add_projection(field.table(), field.meta());
  }
  rc = project_oper.open();
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to open operator");
    return rc;
  }

  Table * thistable = select_stmt->tables()[0];
  while ((rc = project_oper.next()) == RC::SUCCESS) {
    // get current record
    // write to response
    Tuple *tuple = project_oper.current_tuple();
    if (nullptr == tuple) {
      rc = RC::INTERNAL;
      LOG_WARN("failed to get current record. rc=%s", strrc(rc));
      break;
    }

    TupleCell cell;
    for (int i = 0; i < tuple->cell_num(); i++) {
      rc = tuple->cell_at(i, cell);
      if (rc != RC::SUCCESS) {
        LOG_WARN("failed to fetch field of cell. index=%d, rc=%s", i, strrc(rc));
        break;
      }
      Value value;
      value.type = cell.attr_type();
      char *str = new char[cell.length() + 1];
      memcpy(str, cell.data(), cell.length());
      str[cell.length() + 1] = 0;
      value.data = str;
      out_value.push_back(value);
    }
  }

  if (rc != RC::RECORD_EOF) {
    LOG_WARN("something wrong while iterate operator. rc=%s", strrc(rc));
    project_oper.close();
  } else {
    rc = project_oper.close();
  }
  return rc;
}

RC ExecuteStage::do_update(UpdateStmt *update_stmt, SessionEvent *session_event)
{
  RC rc = RC::SUCCESS;
  Session *session = session_event->session();
  Db *db = session->get_current_db();
  Trx *trx = session->current_trx();
  CLogManager *clog_manager = db->get_clog_manager();

  std::vector<UpdateAttrInfo> &update_attr = update_stmt->attrs();
  for(UpdateAttrInfo &attr : update_attr) {
    if(attr.value_ == nullptr) {
      RC rc2 = do_update_select(attr.select_stmt_, session_event, attr.selected_values);
      if (rc2 != SUCCESS) {
        LOG_ERROR("error occured during update-select: %s", strrc(rc2));
        session_event->set_response("FAILURE\n");
        return rc2;
      }
      if (attr.selected_values.size() != 1) {
        LOG_WARN("selected value num not equal 1 in update");
        session_event->set_response("FAILURE\n");
        return RC::INVALID_ARGUMENT;
      }
    }
  }

  TableScanOperator scan_oper(update_stmt->table());
  PredicateOperator pred_oper(update_stmt->filter_stmt());
  pred_oper.add_child(&scan_oper);
  UpdateOperator update_oper(update_stmt, trx);
  update_oper.add_child(&pred_oper);

  rc = update_oper.open();
  update_oper.close();
  if (rc != RC::SUCCESS) {
    session_event->set_response("FAILURE\n");
  } else {
    session_event->set_response("SUCCESS\n");
    if (!session->is_trx_multi_operation_mode()) {
      CLogRecord *clog_record = nullptr;
      rc = clog_manager->clog_gen_record(CLogType::REDO_MTR_COMMIT, trx->get_current_id(), clog_record);
      if (rc != RC::SUCCESS || clog_record == nullptr) {
        session_event->set_response("FAILURE\n");
        return rc;
      }
      rc = clog_manager->clog_append_record(clog_record);
      if (rc != RC::SUCCESS) {
        session_event->set_response("FAILURE\n");
        return rc;
      }
      end_trx_if_need(session, trx, true);
      trx->next_current_id();
      session_event->set_response("SUCCESS\n");
    }
  }
  return rc;
}

RC ExecuteStage::do_delete(SQLStageEvent *sql_event)
{
  Stmt *stmt = sql_event->stmt();
  SessionEvent *session_event = sql_event->session_event();
  Session *session = session_event->session();
  Db *db = session->get_current_db();
  Trx *trx = session->current_trx();
  CLogManager *clog_manager = db->get_clog_manager();

  if (stmt == nullptr) {
    LOG_WARN("cannot find statement");
    return RC::GENERIC_ERROR;
  }

  DeleteStmt *delete_stmt = (DeleteStmt *)stmt;
  TableScanOperator scan_oper(delete_stmt->table());
  PredicateOperator pred_oper(delete_stmt->filter_stmt());
  pred_oper.add_child(&scan_oper);
  DeleteOperator delete_oper(delete_stmt, trx);
  delete_oper.add_child(&pred_oper);

  RC rc = delete_oper.open();
  if (rc != RC::SUCCESS) {
    session_event->set_response("FAILURE\n");
  } else {
    session_event->set_response("SUCCESS\n");
    if (!session->is_trx_multi_operation_mode()) {
      CLogRecord *clog_record = nullptr;
      rc = clog_manager->clog_gen_record(CLogType::REDO_MTR_COMMIT, trx->get_current_id(), clog_record);
      if (rc != RC::SUCCESS || clog_record == nullptr) {
        session_event->set_response("FAILURE\n");
        return rc;
      }

      rc = clog_manager->clog_append_record(clog_record);
      if (rc != RC::SUCCESS) {
        session_event->set_response("FAILURE\n");
        return rc;
      }

      trx->next_current_id();
      session_event->set_response("SUCCESS\n");
    }
  }
  return rc;
}

RC ExecuteStage::do_begin(SQLStageEvent *sql_event)
{
  RC rc = RC::SUCCESS;
  SessionEvent *session_event = sql_event->session_event();
  Session *session = session_event->session();
  Db *db = session->get_current_db();
  Trx *trx = session->current_trx();
  CLogManager *clog_manager = db->get_clog_manager();

  session->set_trx_multi_operation_mode(true);

  CLogRecord *clog_record = nullptr;
  rc = clog_manager->clog_gen_record(CLogType::REDO_MTR_BEGIN, trx->get_current_id(), clog_record);
  if (rc != RC::SUCCESS || clog_record == nullptr) {
    session_event->set_response("FAILURE\n");
    return rc;
  }

  rc = clog_manager->clog_append_record(clog_record);
  if (rc != RC::SUCCESS) {
    session_event->set_response("FAILURE\n");
  } else {
    session_event->set_response("SUCCESS\n");
  }

  return rc;
}

RC ExecuteStage::do_commit(SQLStageEvent *sql_event)
{
  RC rc = RC::SUCCESS;
  SessionEvent *session_event = sql_event->session_event();
  Session *session = session_event->session();
  Db *db = session->get_current_db();
  Trx *trx = session->current_trx();
  CLogManager *clog_manager = db->get_clog_manager();

  session->set_trx_multi_operation_mode(false);

  CLogRecord *clog_record = nullptr;
  rc = clog_manager->clog_gen_record(CLogType::REDO_MTR_COMMIT, trx->get_current_id(), clog_record);
  if (rc != RC::SUCCESS || clog_record == nullptr) {
    session_event->set_response("FAILURE\n");
    return rc;
  }

  rc = clog_manager->clog_append_record(clog_record);
  if (rc != RC::SUCCESS) {
    session_event->set_response("FAILURE\n");
  } else {
    session_event->set_response("SUCCESS\n");
  }

  trx->next_current_id();

  return rc;
}

RC ExecuteStage::do_clog_sync(SQLStageEvent *sql_event)
{
  RC rc = RC::SUCCESS;
  SessionEvent *session_event = sql_event->session_event();
  Db *db = session_event->session()->get_current_db();
  CLogManager *clog_manager = db->get_clog_manager();

  rc = clog_manager->clog_sync();
  if (rc != RC::SUCCESS) {
    session_event->set_response("FAILURE\n");
  } else {
    session_event->set_response("SUCCESS\n");
  }

  return rc;
}
