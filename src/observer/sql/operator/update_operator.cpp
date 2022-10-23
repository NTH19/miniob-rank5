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

    const FieldMeta *field_meta = update_stmt_->field();
    int record_data_size = field_meta->len();
    char *value_data = static_cast<char *>(update_stmt_->values()->data);
    memcpy(new_record_data, record.data_, record_size);
    if (field_meta->type() == CHARS) {
      size_t value_len = strlen(value_data) + 1;
      record_data_size = std::min(record_data_size, static_cast<int>(value_len));
      memset(new_record_data + field_meta->offset(), 0, field_meta->len());
      memcpy(new_record_data + field_meta->offset(), value_data, record_data_size);
    } else if (field_meta->type() == TEXTS) {
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
    } else {
      memcpy(new_record_data + field_meta->offset(), update_stmt_->values()->data, record_data_size);
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