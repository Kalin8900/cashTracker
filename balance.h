#ifndef BALANCE_H
#define BALANCE_H

#include <QObject>

class Balance : public QObject
{
    Q_OBJECT
public:
    explicit Balance(QObject *parent = nullptr);

signals:

};

#endif // BALANCE_H
