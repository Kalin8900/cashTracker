#include "balancechange.h"

BalanceChange::BalanceChange(QVector<Operation> ops):
    operations(std::move(ops));
{ };

BalanceChange::Operation removeLast()
{
    return operations.takeLast();
}


Income::void change(const Operation& operation)
{
    operations.push_back(operation);
}

Expense::void change(const Operation& operation)
{
    operations.push_back(operation);
}

