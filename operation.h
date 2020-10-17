#ifndef OPERATION_H
#define OPERATION_H

#include <QObject>
#include <QDateTime>
#include <QDataStream>
#include <QDebug>

class Operation
{

public:
    Operation(const float& value, const QDateTime &date,
              const QString &category, const qint64 &number);

    Operation() = default;

    float value() const;

    QDateTime date() const;

    QString category() const;

    qint64 number() const;

    friend QDataStream& operator<<(QDataStream &ds, const Operation &op);

    friend QDataStream& operator>>(QDataStream &ds, Operation &op);


private:
    float value_;
    QDateTime date_;
    QString category_;
    qint64 number_;
};


bool operator==(const Operation &lhs, const Operation &rhs);

bool operator!=(const Operation &lhs, const Operation &rhs);
#endif // OPERATION_H
