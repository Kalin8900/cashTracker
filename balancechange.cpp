#include "balancechange.h"

BalanceChange::BalanceChange(QVector<Operation> ops)
    : operations_(std::move(ops))
{}

void BalanceChange::addOperation(const Operation &operation)
{
    operations_.push_back(operation);
}

Operation BalanceChange::removeLast()
{
    return operations_.takeLast();
}

QVector<Operation> BalanceChange::getOperations() const
{
    return operations_;
}

qint64 BalanceChange::size() const
{
    return operations_.size();
}

Operation BalanceChange::lastOperation() const
{
    if(operations_.size() == 0)
        throw std::range_error("Can't give last operation because operation vector size is 0");
    return operations_.back();
}

QDataStream &operator<<(QDataStream &ds, const BalanceChange &bc)
{
    ds << bc.operations_;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, BalanceChange &bc)
{
    ds >> bc.operations_;
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
