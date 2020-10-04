#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "logger.h"
#include "operation.h"

#define TESTS

#ifdef TESTS
#include "tests/operationTests.h"
#endif



int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    #ifdef TESTS
    (operationTests()) ?  qInfo() << "All tests went well" :
                                   qInfo() << "Operations tests failure";
    #endif

    Logger::attach();

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
