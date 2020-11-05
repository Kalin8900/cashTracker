#include "GLOBALS.h"

void GLOBAL::setTextInCenter(QLabel *l, const QString &msg)
{
    l->setText(msg);
    l->setAlignment(Qt::AlignCenter);
}
