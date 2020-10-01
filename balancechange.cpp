#include "balancechange.h"

BalanceChange::BalanceChange(QVector<Operation>& ops):
    operations(ops);
    {

    };
BalanceChange::Operation removeLast()
    {
        Operation temp = operations.back();
        operations.pop_back();
        return temp;
    }

