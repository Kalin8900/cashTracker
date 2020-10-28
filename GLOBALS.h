#ifndef GLOBALS_H
#define GLOBALS_H

#include <QString>
#include <QLabel>

namespace GLOBAL{
const QString INCOME = "INCOME";
const QString EXPENSE = "EXPENSE";
void setTextInCenter(QLabel *l, const QString &msg)
{
    l->setText(msg);
    l->setAlignment(Qt::AlignCenter);
}
}

#endif // GLOBALS_H
