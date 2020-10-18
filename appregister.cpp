#include "appregister.h"

QString AppRegister::appPath_ = QDir::currentPath() + QDir::separator() + "appregisterinit.txt";

AppRegister::AppRegister()
{
    if(!AppRegister::init())
        throw std::runtime_error("Couldn't initalise AppRegister");
}


bool AppRegister::isFirstTime() const
{
    return firstTime;
}

void AppRegister::setFirstTime(bool value)
{
    firstTime = value;
}

bool AppRegister::saveState()
{
    QFile file(AppRegister::appPath_);

    setFirstTime(false);
    if(!file.open(QIODevice::WriteOnly))
    {
        throw std::runtime_error("Couldn't open file to perform a AppRegister state save " + file.fileName().toStdString());
        return false;
    }

    QDataStream ds(&file);
    ds << *this;
    file.close();

    return true;
}



bool AppRegister::init()
{
    //TODO: check if file exists


    QFile file(AppRegister::appPath_);

    if(!file.exists())
    {
        throw std::runtime_error("File: " + file.fileName().toStdString() + " does not exist.");
        return false;
    }

    if(!file.open(QIODevice::ReadOnly))
    {
        throw std::runtime_error("Couldn't open file to perform a AppRegister init " + file.fileName().toStdString());
        return false;
    }
    QDataStream ts(&file);
    ts >> *this; //should load firstTime;

    file.close();

    return true;
}


QDataStream &operator<<(QDataStream &ds, const AppRegister &app)
{
    ds << app.isFirstTime();
    return ds;
}

QDataStream &operator>>(QDataStream &ds, AppRegister &app)
{
    bool read;
    ds >> read;
    app.setFirstTime(read);
    return ds;
}
