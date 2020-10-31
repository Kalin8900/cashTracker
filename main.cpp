#include <QApplication>
#include "mainwindow.h"
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

    #ifdef TESTS
        (operationTests()) ?  qInfo() << "Operation tests went well" :
                                     qInfo() << "Operations tests failure";

        (balanceChangeTests()) ?  qInfo() << "BalanceChange tests went well" :
                                         qInfo() << "BalanceChange tests failure";

    #endif

    QApplication a(argc, argv);


    //to shorten the notation
    auto *bal = &Balance::getBalanceInstance();

    auto appReg = QScopedPointer<AppRegister>(new AppRegister());

    bal->addAppRegister(appReg.get());
    bal->initiateBalance();

    for(const auto &op : bal->getIncome().getOperations())
    {
        qInfo() << op.number();
    }


    for(const auto &op : bal->getExpense().getOperations())
    {
        qInfo() << op.number();
    }


//    bal->setBalance(200.50);
//    bal->changeBalance({1532.32, QDateTime::currentDateTime(), "Rtv", bal->totalSize()});

    Logger::attach();

    MainWindow w(bal);
    w.show();

    //Saving data TODO: catching exceptions
    //saving should be in window destructr



    return a.exec();
}
