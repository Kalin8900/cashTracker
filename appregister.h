#ifndef APPREGISTER_H
#define APPREGISTER_H

#include <QObject>

class AppRegister : public QObject
{
    Q_OBJECT
public:
    explicit appRegister(QObject *parent = nullptr);

signals:

};

#endif // APPREGISTER_H
