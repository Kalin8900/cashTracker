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

//methods below will need to connect to the Balance class and change the value saved there
Income::void change(const Operation& operation)
{
    operations.push_back(operation);
}

Expense::void change(const Operation& operation)
{
    operations.push_back(operation);
}

