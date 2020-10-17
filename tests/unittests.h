#ifndef UNITTESTS_H
#define UNITTESTS_H

#include <QString>
#include <QVector>
#include <QDir>
#include <QPair>
#include <QFile>
#include <QVariant>
#include <typeinfo>
#include <exception>
#include <QDebug>
#include <QDataStream>

//To use unit tests class must have operator== and constructor without arguments or defualt


namespace UnitTests {

static const QString path(QDir::currentPath() + QDir::separator() + "unitTests");

template<class T>
QPair<bool, QString> savingTest(const QVector<T> &testsElements)
{

    QDir dir(UnitTests::path);
    if(!dir.exists())
        dir.mkpath(dir.absolutePath());

    QString pathCore = UnitTests::path + QDir::separator() + typeid(T).name() + "_savingTest";
    QFile file(pathCore);

    QVariant cnt = 1;
    while(file.exists())
    {
        file.setFileName(pathCore + cnt.toString());
        cnt.setValue(cnt.value<qint32>() + 1);
    }

    if(!file.open(QIODevice::WriteOnly))
    {
        throw std::runtime_error("Couldn't open file to perform a saving test " + file.fileName().toStdString());
        file.close();
        return qMakePair(false, file.fileName());
    }

    QDataStream ds(&file);
    ds.setVersion(QDataStream::Qt_5_15);
    for(const auto &elem : testsElements)
        ds << elem;

    file.close();
    return qMakePair(true, file.fileName());
}

template<class T>
bool readingTest(const QString &path, const QVector<T> &toMatch)
{
    QFile file(path);

    if(!file.open(QIODevice::ReadOnly))
    {
        throw std::runtime_error("Couldn't open file to perform a reading test" + file.fileName().toStdString());
        return false;
    }

    QDataStream ds(&file);

    T obj;
    QVector<T> loadedVec;
    while(!ds.atEnd())
    {
        ds >> obj;
        loadedVec.push_back(obj);
    }

    if(loadedVec != toMatch)
    {
        qCritical() << "Loaded vector is not equal to given \n";
        file.close();
        return false;
    }


    file.close();
    return true;

}

template<class T>
bool serializationTest(const QVector<T> &testsElements)
{

    auto savingRes = UnitTests::savingTest(testsElements);

    if(!(savingRes.first))
        return false;

    if(!(UnitTests::readingTest(savingRes.second, testsElements)))
        return false;

    return true;
}
}
#endif // UNITTESTS_H
