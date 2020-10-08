#include "appregister.h"
#include <QDebug>

QString AppRegister::appPath_ = QDir::currentPath() + QDir::separator() + "appregisterinit.txt";

AppRegister::AppRegister()
{
    AppRegister::init();
}

bool AppRegister::checkFirstTime()
{
    return firstTime;
}

bool AppRegister::getFirstTime() const
{
    return firstTime;
}

void AppRegister::setFirstTime(bool value)
{
    firstTime = value;
}

void AppRegister::saveState()
{
    QFile file(AppRegister::appPath_);

    setFirstTime(false);
    if(!file.open(QIODevice::WriteOnly))
    {
        throw std::runtime_error("Coudln't open file to perform a AppRegister state save " + file.fileName().toStdString());
        return false;
    }

    QDataStream ds(&file);
    ds << *this;
    file.close();
}



bool AppRegister::init()
{
    //TODO: check if file exists


    QFile file(AppRegister::appPath_);

    if(!file.open(QIODevice::ReadOnly))
    {
        throw std::runtime_error("Coudln't open file to perform a AppRegister init " + file.fileName().toStdString());
        return false;
    }
    QDataStream ts(&file);
    ts >> *this; //should load firstTime;

    file.close();

    return true;
}


QDataStream &operator<<(QDataStream &ds, AppRegister &app)
{
    ds << app.getFirstTime();
    return ds;
}

QDataStream &operator>>(QDataStream &ds, AppRegister &app)
{
    bool read;
    ds >> read;
    app.setFirstTime(read);
    return ds;
}
