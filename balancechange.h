#ifndef BALANCECHANGE_H
#define BALANCECHANGE_H
#include <QVector>
#include <QDataStream>
#include "operation.h"

class BalanceChange
{

public:

    BalanceChange(QVector<Operation> ops = {});

    void addOperation(const Operation& operation);

    Operation removeLast();

    friend QDataStream& operator<<(QDataStream &ds, const BalanceChange &bc);

    friend QDataStream& operator>>(QDataStream &ds, BalanceChange &bc);

    QVector<Operation> getOperations() const;

    qint64 size() const;

    Operation lastOperation() const;

private:
    QVector<Operation> operations_;
};

bool operator==(const BalanceChange &lhs, const BalanceChange &rhs);

bool operator!=(const BalanceChange &lhs, const BalanceChange &rhs);

#endif // BALANCECHANGE_H
