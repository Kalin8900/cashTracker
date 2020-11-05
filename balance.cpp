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

    auto toInsert = op;
    toInsert.setNumber(totalSize());

    (op.value() > 0) ? income_.addOperation(toInsert) : expense_.addOperation(toInsert);


    emit lastOperationChanged();
}

void Balance::changeBalance(const float &value, const QDateTime &date, const QString &category)
{
    if(value == 0)
        throw std::invalid_argument("Value of the operation cannot be equal to 0");

    balance_ += value;

    if(value > 0)
        income_.addOperation({value, date, category, totalSize()});
    else
        expense_.addOperation({value, date, category, totalSize()});

    emit lastOperationChanged();
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

    balance_ = 0.00;
}

AppRegister *Balance::getAppRegister() const
{
    return appRegister_;
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

void Balance::removeLastlyAddedOp()
{

    float val;
    bool onlyOne(false);
    if(totalSize() == 0)
        throw std::range_error("Balance does not have any operations");
    if(income_.size() == 0 && expense_.size() != 0)
    {
        val = expense_.removeLast().value();
        onlyOne = true;
    }
    if(income_.size() != 0 && expense_.size() == 0)
    {
        val = income_.removeLast().value();
        onlyOne = true;
    }


    if(!onlyOne)
        (income_.lastOperation().number() > expense_.lastOperation().number())
            ? val = income_.removeLast().value() : val = expense_.removeLast().value();

    balance_ -= val;

    emit lastOperationChanged();
}

QPair<Operation, QString> Balance::getNewestOperation()
{

    if(totalSize() == 0)
        throw std::range_error("Balance does not have any operations");
//    if(income_.size() == 0 && expense_.size() != 0)
//        return qMakePair(expense_.lastOperation(), GLOBAL::EXPENSE);
//    if(income_.size() != 0 && expense_.size() == 0)
//        return qMakePair(income_.lastOperation(), GLOBAL::INCOME);




    const Operation *newestOperation;
    bool income;

    if(income_.size() != 0 && expense_.size() == 0)
    {
        newestOperation = &income_.getOperations().at(0);
        income = true;

        for(int i = 1; i < income_.size(); ++i)
            if(newestOperation->date() < income_.getOperations().at(i).date())
            {
                newestOperation = &income_.getOperations().at(i);
                income = true;
            }
    }

    if(income_.size() == 0 && expense_.size() != 0)
    {
        newestOperation = &expense_.getOperations().at(0);
        income = false;

        for(int i = 0; i < expense_.size(); ++i)
        {
            if(newestOperation->date() < expense_.getOperations().at(i).date())
            {
                newestOperation = &expense_.getOperations().at(i);
                income = false;
            }
        }
    }

    return (income) ? qMakePair(*newestOperation, GLOBAL::INCOME)
                    : qMakePair(*newestOperation, GLOBAL::EXPENSE);
}

QPair<Operation, QString> Balance::getLastlyAddedOperation()
{

    if(totalSize() == 0)
        throw std::range_error("Balance does not have any operations");
    if(income_.size() == 0 && expense_.size() != 0)
        return qMakePair(expense_.lastOperation(), GLOBAL::EXPENSE);
    if(income_.size() != 0 && expense_.size() == 0)
        return qMakePair(income_.lastOperation(), GLOBAL::INCOME);


    auto incomeLast = income_.lastOperation();
    auto expenseLast = expense_.lastOperation();

    return (incomeLast.number() > expenseLast.number()) ?
                qMakePair(incomeLast, GLOBAL::INCOME) : qMakePair(expenseLast, GLOBAL::EXPENSE);

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

int Balance::getIncomeSize()
{
    return income_.size();
}

int Balance::getExpenseSize()
{
    return expense_.size();
}

int Balance::totalSize()
{
    return getIncomeSize() + getExpenseSize();
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
