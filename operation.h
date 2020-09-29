#ifndef OPERATION_H
#define OPERATION_H

#include <QObject>
#include <QDateTime>


class Operation : public QObject
{
    Q_OBJECT
public:
    Operation(const float& value, const QDateTime &date,
              const QString &category, QObject *parent = nullptr);




private:
    float value_;
    QDateTime date_;
    QString category_;

};

#endif // OPERATION_H
