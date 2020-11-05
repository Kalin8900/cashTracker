#ifndef BALANCE_H
#define BALANCE_H

#include <QObject>
#include "balancechange.h"
#include "appregister.h"

class Balance : public QObject
{
    Q_OBJECT
public:
    static Balance &getBalanceInstance();

    void changeBalance(const Operation &op);
    void changeBalance(const float &value, const QDateTime &date, const QString &category);

    BalanceChange getIncome() const;

    BalanceChange getExpense() const;

    float getBalance() const;
    void setBalance(float balance);

    void addAppRegister(AppRegister *app);

    void initiateBalance();

    bool saveCurrentState();

    void removeLastlyAddedOp();

    QPair<Operation, QString> getNewestOperation(); //newest in term of time

    QPair<Operation, QString> getLastlyAddedOperation(); //last added to app

    float getValueFromOperation(const qint32 &index, const QString &place);

    QString getCategoryFromOperation(const qint32 &index, const QString &place);

    QString getDateFromOperation(const qint32 &index, const QString &place);

    int getIncomeSize();

    int getExpenseSize();

    int totalSize();

    friend QDataStream &operator>>(QDataStream &ds, Balance &bl);

    Balance(const Balance &other) = delete;
    Balance operator=(const Balance &other) = delete;

    AppRegister *getAppRegister() const;

signals:
    void lastOperationChanged();


private:
    explicit Balance(QObject *parent = nullptr);

    void loadLast(); //this will read the data if app is opened not the first time
    void init(); //when app is opened for the first time

    BalanceChange income_, expense_;
    float balance_;
    AppRegister *appRegister_;

    static QString balancePath_;

};

QDataStream &operator<<(QDataStream &ds, const Balance &bl);

#endif // BALANCE_H
