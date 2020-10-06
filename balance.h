#ifndef BALANCE_H
#define BALANCE_H

#include <QObject>
#include "balancechange.h"

class Balance : public QObject
{
    Q_OBJECT
public:

    void changeBalance(const Operation &op);

    BalanceChange income() const;

    BalanceChange expense() const;

    float getBalance() const;
    void setBalance(float balance);


    Balance(const Balance &other) = delete;
    Balance operator==(const Balance &other) = delete;


private:
    explicit Balance(QObject *parent = nullptr);
    static Balance &getBalanceInstance();

    void loadLast(); //this will read the data if app is opend not the first time
    void init(); //when app is opend for the first time

    BalanceChange income_, expense_;
    float balance_;


};

#endif // BALANCE_H
