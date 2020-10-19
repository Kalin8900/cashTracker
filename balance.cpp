#include "balance.h"
#include "appregister.h"
#include "GLOBALS.h"

QString Balance::balancePath_ = QDir::currentPath() + QDir::separator() + "balance.txt";

Balance::Balance(QObject *parent)
    : QObject(parent)
{}

void Balance::changeBalance(const Operation &op)
{
    balance_ += op.value();

    (op.value() > 0) ? income_.addOperation(op) : expense_.addOperation(op);
}

BalanceChange Balance::getIncome() const
{
    return income_;
}

BalanceChange Balance::getExpense() const
{
    return expense_;
}

void Balance::loadLast()
{
    qInfo() << "Loading Balance from file";

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

void Balance::initiateBalance ()
{
    (appRegister_->isFirstTime()) ? init() : loadLast();
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

QPair<Operation, QString> Balance::getLastOperation()
{
    if(income_.size() == 0 && expense_.size() == 0)
        throw std::range_error("Balance does not have any operations");
    if(income_.size() == 0 && expense_.size() != 0)
        return qMakePair(expense_.lastOperation(), GLOBAL::EXPENSE);
    if(income_.size() != 0 && expense_.size() == 0)
        return qMakePair(income_.lastOperation(), GLOBAL::INCOME);

    return (income_.lastOperation().date() > expense_.lastOperation().date()) ?
                qMakePair(income_.lastOperation(), GLOBAL::INCOME) : qMakePair(expense_.lastOperation(), GLOBAL::EXPENSE);
}

float Balance::getValueFromOperation(const qint32 &index, const QString &place)
{
    if(place == GLOBAL::INCOME)
        return income_.getOperations().at(index).value();
    else if(place == GLOBAL::EXPENSE)
        return expense_.getOperations().at(index).value();
    else
        throw std::invalid_argument("Given argument " + place.toStdString() + " does not match any place. Check GLOBALS");
}

QString Balance::getCategoryFromOperation(const qint32 &index, const QString &place)
{
    if(place == GLOBAL::INCOME)
        return income_.getOperations().at(index).category();
    else if(place == GLOBAL::EXPENSE)
        return expense_.getOperations().at(index).category();
    else
        throw std::invalid_argument("Given argument " + place.toStdString() + " does not match any place. Check GLOBALS");
}

QString Balance::getDateFromOperation(const qint32 &index, const QString &place)
{
    if(place == GLOBAL::INCOME)
        return income_.getOperations().at(index).date().date().toString("dd-MM-yyyy");
    else if(place == GLOBAL::EXPENSE)
        return expense_.getOperations().at(index).date().date().toString("dd-MM-yyyy");
    else
        throw std::invalid_argument("Given argument " + place.toStdString() + " does not match any place. Check GLOBALS");

}

qint32 Balance::getLastOperationIdx()
{
    return getLastOperationMeta().first;
}

QString Balance::getLastOperationPlace()
{
    return getLastOperationMeta().second;
}

QPair<qint32, QString> Balance::getLastOperationMeta()
{
    return (getLastOperation().second == GLOBAL::INCOME) ? qMakePair(income_.size() - 1, GLOBAL::INCOME)
                                                         : qMakePair(expense_.size() - 1, GLOBAL::EXPENSE);
}

QDataStream &operator>>(QDataStream &ds, Balance &bl)
{
    ds >> bl.income_ >> bl.expense_ >> bl.balance_;
    return ds;
}

QDataStream &operator<<(QDataStream &ds, const Balance &bl)
{
    ds << bl.getIncome() << bl.getExpense() << bl.getBalance();
    return ds;
}
