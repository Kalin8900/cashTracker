#ifndef LOGGER_H
#define LOGGER_H

#include <QObject>
#include <QDir>
#include <QDebug>
#include <QDateTime>
#include <QFile>
#include <QTextStream>

class logger : public QObject
{
    Q_OBJECT
public:


    static void attach();
    static void handler(QtMsgType type, const QMessageLogContext &context, const QString &msg);

    void turnLoggingOff() { logging = false; };
    void turnLoggingOn() { logging = true; };
    bool toggleLogging();

    static QString getLogFile();
    static void setLogFile(const QString &value);

    logger(const logger &other) = delete;
    logger operator=(const logger &other) = delete;
    static bool isLogging();

private:
    explicit logger(QObject *parent = nullptr);
    logger &getLogger() const;

    static QString logFile;
    static bool logging;

};

#endif // LOGGER_H
