#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include "logger.h"
#include "operation.h"
#include "appregister.h"
#include "balance.h"

//#define TESTS

#ifdef TESTS
#include "tests/operationTests.h"
#include "tests/balanceChangeTests.h"
#endif



int main(int argc, char *argv[])
{
    //to shorten the notation
    auto *bal = &Balance::getBalanceInstance();

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    #ifdef TESTS
    (operationTests()) ?  qInfo() << "Operation tests went well" :
                                   qInfo() << "Operations tests failure";

    (balanceChangeTests()) ?  qInfo() << "BalanceChange tests went well" :
                                   qInfo() << "BalanceChange tests failure";

    #endif

    auto appReg = QScopedPointer<AppRegister>(new AppRegister());

    bal->addAppRegister(appReg.get());
    bal->initiateBalance();
//    bal->setBalance(200.50);
//    bal->changeBalance({-150.25f, QDateTime::currentDateTime(), "Sport", 1});
    qInfo() << bal->getExpense().size();
    auto lastOp = bal->getLastOperation();
    qInfo() << lastOp.first.value();
    Logger::attach();

    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("balance", bal);
    engine.rootContext()->setContextProperty("appregister", QVariant::fromValue(appReg.get()));

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);


    //Saving data TODO: catching exceptions
    appReg->saveState();
    bal->saveCurrentState();

    return app.exec();
}
