#pragma once

#include "sql/operator/operator.h"
#include "rc.h"

class UpdateStmt;

class UpdateOperator : public Operator
{
public:
  UpdateOperator(UpdateStmt *delete_stmt)
    : update_stmt_(delete_stmt)
  {}

  virtual ~UpdateOperator() = default;

  RC open() override;
  RC next() override;
  RC close() override;
  UpdateStmt * get()
  {return update_stmt_;}

  Tuple * current_tuple() override {
    return nullptr;
  }
  //int tuple_cell_num() const override
  //RC tuple_cell_spec_at(int index, TupleCellSpec &spec) const override
private:
  UpdateStmt *update_stmt_ = nullptr;
};