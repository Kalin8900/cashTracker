#include <stdexcept>
#include "logger.h"

QString logger::logFile(QDir::currentPath() +
                        QDir::separator() + "log.txt");
bool logger::logging(false);
const static QtMessageHandler QT_DEFAULT_MESSAGE_HANDLER = qInstallMessageHandler(nullptr);


logger::logger(QObject *parent) : QObject(parent)
{

}

logger &logger::getLogger() const
{
    static logger log;
    return log;
}

bool logger::isLogging()
{
    return logging;
}

QString logger::getLogFile()
{
    return logFile;
}

void logger::setLogFile(const QString &value)
{
    logFile = value;
}

void logger::attach()
{
    logger::logging = true;
    qInstallMessageHandler(logger::handler);
}

void logger::handler(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    if(logger::logging)
    {
        QString toPrint;
        switch (type) {
        case QtInfoMsg:
            toPrint = QString("Info: %1 in %2").arg(msg).arg(context.file);
            break;
        case QtDebugMsg:
            toPrint = QString("Debug: %1 in %2").arg(msg).arg(context.file);
            break;
        case QtWarningMsg:
            toPrint = QString("Warning: %1 in %2").arg(msg).arg(context.file);
            break;
        case QtCriticalMsg:
            toPrint = QString("Critical: %1 in %2").arg(msg).arg(context.file);
            break;
        case QtFatalMsg:
            toPrint = QString("Fatal: %1 in %2").arg(msg).arg(context.file);
            break;
        }

        QFile outFile(logger::logFile);
        if(outFile.open(QIODevice::WriteOnly | QIODevice::Append))
        {
            QTextStream stream(&outFile);
            stream << QDateTime::currentDateTime().toString("dd.MM.yyyy hh:mm:ss") << " - " << toPrint <<
                      " line: " << context.line << "\n";
            stream.flush();
            outFile.close();
        } else
            throw std::runtime_error("Couldn't open log file " + logger::logFile.toStdString());


    }

    (*QT_DEFAULT_MESSAGE_HANDLER)(type, context, msg);
}

bool logger::toggleLogging()
{
    logger::logging = !logger::logging;

    return logger::logging;
}
