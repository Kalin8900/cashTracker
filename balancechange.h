#ifndef BALANCECHANGE_H
#define BALANCECHANGE_H
#include "operation.h"
#include "operation.cpp"
#include <qvector>

class BalanceChange
{
    public:
        BalanceChange(QVector<Operation>& ops);
        virtual void change(const Operation& operation) = 0;
        Operation removeLast();
    protected:
        QVector<Operation> operations
};

#endif // BALANCECHANGE_H
