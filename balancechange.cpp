#include "balancechange.h"

BalanceChange::BalanceChange(QVector<Operation> ops)
    : operations(std::move(ops))
{}

void BalanceChange::addOperation(const Operation &operation)
{
    operations.push_back(operation);
}

Operation BalanceChange::removeLast()
{
    return operations.takeLast();
}
