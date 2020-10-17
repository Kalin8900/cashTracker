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

QVector<Operation> BalanceChange::getOperations() const
{
    return operations;
}

QDataStream &operator<<(QDataStream &ds, const BalanceChange &bc)
{
    ds << bc.operations;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, BalanceChange &bc)
{
    ds >> bc.operations;
    return ds;
}

bool operator==(const BalanceChange &lhs, const BalanceChange &rhs)
{
    return lhs.getOperations() == rhs.getOperations();
}

bool operator!=(const BalanceChange &lhs, const BalanceChange &rhs)
{
    return lhs.getOperations() != rhs.getOperations();
}
