#ifndef BALANCE_H
#define BALANCE_H

#include <QObject>
#include "balancechange.h"

class Balance : public QObject
{
    Q_OBJECT
public:
    Balance(const float &balance, const BalanceChange &income,
                     const BalanceChange &expense, QObject *parent = nullptr);

    void changeBalance(const Operation &op);

    BalanceChange income() const;

    BalanceChange expense() const;

private:
    BalanceChange income_, expense_;
    float balance_;
};

#endif // BALANCE_H
