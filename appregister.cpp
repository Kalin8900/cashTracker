#include "appregister.h"

AppRegister::AppRegister()
{
    AppRegister::init();
}

void AppRegister::init()
{
    //path
    const QString path = QDir::currentPath() + QDir::separator() + "appregisterinit.txt";

    //check if exists


    QFile file(path);
    QDataStream ts(&file);
    bool read;
    ts >> read;

    firstTime = read;
    //file
    //read from file
    //firstTime
    //save to class



}
