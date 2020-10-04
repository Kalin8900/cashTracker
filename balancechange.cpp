#include "balancechange.h"

BalanceChange::BalanceChange(QVector<Operation> ops)
    : operations(std::move(ops))
{}

Operation BalanceChange::removeLast()
{
    return operations.takeLast();
}
