#include "operation.h"


Operation::Operation(const float &value, const QDateTime &date,
                     const QString &category, const qint64 &number)
    : value_(value),
      date_(date),
      category_(category),
      number_(number) {}

float Operation::value() const
{
    return value_;
}

QDateTime Operation::date() const
{
    return date_;
}

QString Operation::category() const
{
    return category_;
}

qint64 Operation::number() const
{
    return number_;
}

QDataStream &operator<<(QDataStream &ds, const Operation &op)
{
    ds << op.value_ << op.date_ << op.category_ << op.number_;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, Operation &op)
{
    ds >> op.value_ >> op.date_ >> op.category_ >> op.number_;
    return ds;
}

bool operator==(const Operation &lhs, const Operation &rhs)
{
    return lhs.date() == rhs.date() && lhs.value() == rhs.value()
            && lhs.category() == rhs.category() && lhs.number() == rhs.number();
}

bool operator!=(const Operation &lhs, const Operation &rhs)
{
    return !(lhs == rhs);
}
