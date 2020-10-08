#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "logger.h"
#include "operation.h"
#include "appregister.h"
#include "balance.h"

#define TESTS

#ifdef TESTS
#include "tests/operationTests.h"
#include "tests/balanceChangeTests.h"
#endif



int main(int argc, char *argv[])
{
    auto *bal = &Balance::getBalanceInstance();

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    #ifdef TESTS
    (operationTests()) ?  qInfo() << "Operation tests went well" :
                                   qInfo() << "Operations tests failure";

    (balanceChangeTests()) ?  qInfo() << "BalanceChange tests went well" :
                                   qInfo() << "BalanceChange tests failure";

    #endif

    AppRegister a;

    bal->addAppRegister(&a);
    bal->startBalance();

    Logger::attach();

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);


    //Saving data
    a.saveState();
    bal->saveCurrentState();

    return app.exec();
}
