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

    AppRegister(const AppRegister &other) = delete;
    AppRegister operator=(const AppRegister &other) = delete;
private:
    bool firstTime;
    static QString appPath_;

    bool init();
};

QDataStream &operator<<(QDataStream &ds, const AppRegister &app);
QDataStream &operator>>(QDataStream &ds, AppRegister &app);

Q_DECLARE_METATYPE(AppRegister*)
#endif // APPREGISTER_H
