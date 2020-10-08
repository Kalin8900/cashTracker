#ifndef APPREGISTER_H
#define APPREGISTER_H

#include <QObject>
#include <QDir>
#include <QFile>
#include <QDataStream>


class AppRegister
{
public:
    AppRegister();

    bool isFirstTime() const;
    void setFirstTime(bool value);

    bool saveState();

private:
    bool firstTime;
    static QString appPath_;

    bool init();
};

QDataStream &operator<<(QDataStream &ds, const AppRegister &app);
QDataStream &operator>>(QDataStream &ds, AppRegister &app);
#endif // APPREGISTER_H
