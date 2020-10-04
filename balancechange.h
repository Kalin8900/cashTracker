#ifndef BALANCECHANGE_H
#define BALANCECHANGE_H
#include <QVector>
#include "operation.h"

class BalanceChange
{
    public:

        BalanceChange(QVector<Operation> ops);

        void addOperation(const Operation& operation);

        Operation removeLast();

    private:
        QVector<Operation> operations;
};

#endif // BALANCECHANGE_H
