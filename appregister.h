#ifndef APPREGISTER_H
#define APPREGISTER_H

#include <QObject>

class appRegister : public QObject
{
    Q_OBJECT
public:
    explicit appRegister(QObject *parent = nullptr);

signals:

};

#endif // APPREGISTER_H
