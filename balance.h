#ifndef BALANCE_H
#define BALANCE_H

#include <QObject>
#include "balancechange.h"
#include "appregister.h"

class Balance : public QObject
{
    Q_OBJECT
    Q_PROPERTY(float balance READ getBalance)
public:
    static Balance &getBalanceInstance();

    void changeBalance(const Operation &op);

    BalanceChange getIncome() const;

    BalanceChange getExpense() const;

    float getBalance() const;
    void setBalance(float balance);

    void addAppRegister(AppRegister *app);

    void initiateBalance();

    bool saveCurrentState();

    QPair<Operation, QString> getLastOperation();

    Q_INVOKABLE float getValueFromOperation(const qint32 &index, const QString &place);

    Q_INVOKABLE qint32 getLastOperationIdx();

    Q_INVOKABLE QString getIsLastOperationPlace();

    QPair<qint32, QString> getLastOperationMeta();

    friend QDataStream &operator>>(QDataStream &ds, Balance &bl);

    Balance(const Balance &other) = delete;
    Balance operator=(const Balance &other) = delete;


private:
    explicit Balance(QObject *parent = nullptr);

    void loadLast(); //this will read the data if app is opend not the first time
    void init(); //when app is opend for the first time

    BalanceChange income_, expense_;
    float balance_;
    AppRegister *appRegister_;

    static QString balancePath_;

};

QDataStream &operator<<(QDataStream &ds, const Balance &bl);

#endif // BALANCE_H
