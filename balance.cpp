#include "balance.h"

Balance::Balance(QObject *parent)
    : QObject(parent)
{
    //because appregister is not ready there is init only
    Balance::init();
}

void Balance::changeBalance(const Operation &op)
{
    balance_ += op.value();

    (op.value() > 0) ? income_.addOperation(op) : expense_.addOperation(op);
}

BalanceChange Balance::income() const
{
    return income_;
}

BalanceChange Balance::expense() const
{
    return expense_;
}

void Balance::loadLast()
{
    //TODO: check if its opend more than once

    //TODO: load data from files

    //TODO: save to Balance
}

void Balance::init()
{
    //TODO: check if its opend for the first time

    balance_ = 0;
}

float Balance::getBalance() const
{
    return balance_;
}

void Balance::setBalance(float balance)
{
    balance_ = balance;
}

Balance &Balance::getBalanceInstance()
{
    static Balance bal;
    return bal;
}
