#ifndef GLOBALS_H
#define GLOBALS_H

#include <QString>
#include <QLabel>

namespace GLOBAL{
const QString INCOME = "INCOME";
const QString EXPENSE = "EXPENSE";
const QString CURRENCY = "PLN";

void setTextInCenter(QLabel *l, const QString &msg);
}
#endif // GLOBALS_H
