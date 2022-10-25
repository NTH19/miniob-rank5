#include "common/log/log.h"
#include "sql/operator/update_operator.h"
#include "storage/record/record.h"
#include "storage/common/table.h"
#include "sql/stmt/update_stmt.h"

RC UpdateOperator::open()
{
  if (children_.size() != 1) {
    LOG_WARN("update operator must has 1 child");
    return RC::INTERNAL;
  }

  Operator *child = children_[0];
  RC rc = child->open();
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to open child operator: %s", strrc(rc));
    return rc;
  }

  Table *table = update_stmt_->table();
  int record_size = table->table_meta().record_size();
  char *new_record_data = new char[record_size];

  while (RC::SUCCESS == (rc = child->next())) {
    Tuple *tuple = child->current_tuple();
    if (nullptr == tuple) {
      LOG_WARN("failed to get current record: %s", strrc(rc));
      return rc;
    }

    RowTuple *row_tuple = static_cast<RowTuple *>(tuple);
    Record &record = row_tuple->record();
    memcpy(new_record_data, record.data_, record_size);
    auto &update_attrs = update_stmt_->attrs();
    for(auto &attr : update_attrs) {
      const FieldMeta *field_meta = attr.field_;
      int record_data_size = field_meta->len();
      const Value &value = attr.value_ == nullptr ? attr.selected_values[0] : *attr.value_;
      const char *value_data = static_cast<char *>(value.data);
      if (value._is_null){
        memcpy(new_record_data + field_meta->offset(), __NULL_DATA__, 4);
        continue;
      }
      switch (field_meta->type()) {
      case CHARS:
        memset(new_record_data + field_meta->offset(), 0, field_meta->len());
        rc = table->cast_to_char(*field_meta, value, new_record_data);
        break;
      case INTS:
        rc = table->cast_to_int(*field_meta, value, new_record_data);
        break;
      case FLOATS:
        rc = table->cast_to_float(*field_meta, value, new_record_data);
        break;
      case DATES:
        memcpy(new_record_data + field_meta->offset(), value_data, record_data_size);
        break;
      case TEXTS: {
        char *s;
        if (strlen(value_data) > 4096) {
          s = (char*)malloc(4097);
          memcpy(s, value_data, 4096);
          s[4096] = 0;
        } else {
          s = (char*)malloc(strlen(value_data) + 1);
          memcpy(s, value_data, strlen(value_data) + 1);
        }
        int result = update_stmt_->table()->insert_text(s);
        memcpy(new_record_data + field_meta->offset(), &result, field_meta->len());
        break;
      }
      default:
        rc = RC::SCHEMA_FIELD_TYPE_MISMATCH;
        break;
      }
      if (rc != RC::SUCCESS) {
        LOG_PANIC("cast error during update");
      }
    }
    rc = table->update_record(trx_, &record, new_record_data);
    if (rc != RC::SUCCESS) {
      LOG_WARN("failed to update record: %s", strrc(rc));
      delete[] new_record_data;
      return rc;
    }
  }
  delete[] new_record_data;
  return RC::SUCCESS;
}

RC UpdateOperator::next()
{
  return RC::RECORD_EOF;
}

RC UpdateOperator::close()
{
  children_[0]->close();
  return RC::SUCCESS;
}