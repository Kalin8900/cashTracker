#include "operation.h"


Operation::Operation(const float &value, const QDateTime &date,
                     const QString &category, const qint64 &number, QObject *parent)
    : QObject(parent),
      value_(value),
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

QDataStream &operator<<(QDataStream &ds, const Operation &op)
{
    qInfo() << "Saving Operation number " << op.number_ << "\n";

    ds << op.value_ << op.date_ << op.category_ << op.number_;

    return ds;
}

QDataStream &operator>>(QDataStream &ds, Operation &op)
{
    ds >> op.value_ >> op.date_ >> op.category_ >> op.number_;

    qInfo() << "Loaded Operation number " << op.number_ << "\n";

    return ds;
}
