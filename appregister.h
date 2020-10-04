#ifndef APPREGISTER_H
#define APPREGISTER_H

#include <QObject>

class AppRegister : public QObject
{
    Q_OBJECT
public:
    explicit AppRegister(QObject *parent = nullptr);

signals:

};

#endif // APPREGISTER_H
