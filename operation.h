#ifndef OPERATION_H
#define OPERATION_H

#include <QObject>
#include <QDateTime>
#include <QDataStream>
#include <QDebug>

class Operation : public QObject
{
    Q_OBJECT
public:
    Operation(const float& value, const QDateTime &date,
              const QString &category, const qint64 &number, QObject *parent = nullptr);

    float value() const;

    QDateTime date() const;

    QString category() const;

    friend QDataStream& operator<<(QDataStream &ds, const Operation &op);

    friend QDataStream& operator>>(QDataStream &ds, Operation &op);


private:
    float value_;
    QDateTime date_;
    QString category_;
    qint64 number_;
};

#endif // OPERATION_H
