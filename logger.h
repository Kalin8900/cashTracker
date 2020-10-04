#ifndef LOGGER_H
#define LOGGER_H

#include <QObject>
#include <QDir>
#include <QDebug>
#include <QDateTime>
#include <QFile>
#include <QTextStream>

class Logger : public QObject
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

    Logger(const Logger &other) = delete;
    Logger operator=(const Logger &other) = delete;
    static bool isLogging();

private:
    explicit Logger(QObject *parent = nullptr);
    Logger &getLogger() const;

    static QString logFile;
    static bool logging;

};

#endif // LOGGER_H
