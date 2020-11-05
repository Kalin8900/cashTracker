#include "operation.h"
#include "GLOBALS.h"

Operation::Operation(const float &value, const QDateTime &date,
                     const QString &category, const qint64 &number)
    : value_(value),
      date_(date),
      category_(category),
      number_(number)
{
    if(value_ == 0)
        throw std::invalid_argument("Operation must have either positive or negative value.");
}

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

void Operation::setValue(float value)
{
    value_ = value;
}

void Operation::setDate(const QDateTime &date)
{
    date_ = date;
}

void Operation::setCategory(const QString &category)
{
    category_ = category;
}

void Operation::setNumber(const qint64 &number)
{
    number_ = number;
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

void operator<<(const Operation &lhs, const std::array<QLabel *, 3> &arr)
{
    using GLOBAL::setTextInCenter;
    setTextInCenter(arr.at(0), QString::number(lhs.value()) + " " + GLOBAL::CURRENCY);
    setTextInCenter(arr.at(1), lhs.date().date().toString("dd-MM-yyyy"));
    setTextInCenter(arr.at(2), lhs.category());
}
