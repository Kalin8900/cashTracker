#include "balance.h"

Balance::Balance(const float &balance, const BalanceChange &income,
                 const BalanceChange &expense, QObject *parent)
    : QObject(parent),
      income_(income),
      expense_(expense),
      balance_(balance) {}

void Balance::changeBalance(const Operation &op)
{
    balance_ += op.value();

    (op.value() > 0) ? income_.addOperation(op) : expense_.addOperation(op);
}

BalanceChange Balance::income() const
{
    return income_;
}

BalanceChange Balance::expense() const
{
    return expense_;
}
