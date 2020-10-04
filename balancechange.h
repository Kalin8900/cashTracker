#ifndef BALANCECHANGE_H
#define BALANCECHANGE_H
#include <QVector>
#include "operation.h"

class BalanceChange
{
    public:
        BalanceChange(QVector<Operation> ops);
        virtual void addOperation(const Operation& operation) = 0;
        Operation removeLast();
    protected:
        QVector<Operation> operations;
};

#endif // BALANCECHANGE_H
