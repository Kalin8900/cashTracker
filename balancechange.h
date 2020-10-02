#ifndef BALANCECHANGE_H
#define BALANCECHANGE_H
#include <QVector>
#include "operation.h"

class BalanceChange
{
    public:
        BalanceChange(QVector<Operation> ops);
        virtual void change(const Operation& operation) = 0;
        Operation removeLast();
    protected:
        QVector<Operation> operations;
};

class Income : public BalanceChange
{
    public:
        void change(const Operation& operation);
};

class Expense : public BalanceChange
{
    public:
        void change(const Operation& operation);
};

#endif // BALANCECHANGE_H
