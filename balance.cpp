#include "balance.h"
#include "appregister.h"

QString Balance::balancePath_ = QDir::currentPath() + QDir::separator() + "balance.txt";

Balance::Balance(QObject *parent)
    : QObject(parent)
{
    //because appregister is not ready there is init only
    //Balance::init();
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
    qInfo() << "Loading from file";

    //TODO: check if file exist

    QFile file(Balance::balancePath_);

    if(!file.open(QIODevice::ReadOnly))
    {
        throw std::runtime_error("Coudln't open file to perform a Balance last state loading"
                                 + file.fileName().toStdString());
        return;
    }

    QDataStream ds(&file);

    ds >> *this;

}

void Balance::init()
{
    qInfo() << "Balance initialised";

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

void Balance::addAppRegister(AppRegister *app)
{
    appRegister_= app;
}

Balance &Balance::getBalanceInstance()
{
    static Balance bal;
    return bal;
}

void Balance::startBalance()
{
    (appRegister_->getFirstTime()) ? init() : loadLast();
}

bool Balance::saveCurrentState()
{
    //TODO: file validation and creating if needed
    QFile file(balancePath_);

    if(!file.open(QIODevice::WriteOnly))
    {
        throw std::runtime_error("Coudln't open file to perform a balance state saving " + file.fileName().toStdString());
        return false;
    }

    QDataStream ds(&file);
    ds << *this;

    file.close();
    return true;
}

QDataStream &operator>>(QDataStream &ds, Balance &bl)
{
    ds >> bl.income_ >> bl.expense_ >> bl.balance_;
    return ds;
}

QDataStream &operator<<(QDataStream &ds, const Balance &bl)
{
    ds << bl.income() << bl.expense() << bl.getBalance();
    return ds;
}
