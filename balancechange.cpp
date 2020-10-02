#include "balancechange.h"

BalanceChange::BalanceChange(QVector<Operation> ops)
    : operations(std::move(ops))
{}

Operation BalanceChange::removeLast()
{
    return operations.takeLast();
}


void Income::change(const Operation& operation)
{
    operations.push_back(operation);
}

void Expense::change(const Operation& operation)
{
    operations.push_back(operation);
}

