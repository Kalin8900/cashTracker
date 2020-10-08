#ifndef APPREGISTER_H
#define APPREGISTER_H

#include <QObject>
#include <QDir>
#include <QFile>
#include <QDataStream>
#include <QTextStream>


class AppRegister
{
public:
    AppRegister();

private:
    bool firstTime;

    void init();
};

#endif // APPREGISTER_H
