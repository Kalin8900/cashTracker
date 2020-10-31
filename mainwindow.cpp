#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <cmath>
#include <QDebug>
#include "GLOBALS.h"
#include "operationwindow.h"
#include "removeoperationwindow.h"

using GLOBAL::setTextInCenter, GLOBAL::HOMEPAGE, GLOBAL::INCOMEPAGE, GLOBAL::EXPENSEPAGE;

MainWindow::MainWindow(Balance *balance, QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      balance_(balance),
      curPage_(MainWindow::HomePage),
      timer_(new QTimer(this))
{
    ui->setupUi(this);
    connect(timer_, &QTimer::timeout, this, QOverload<>::of(&MainWindow::updateTimer));
    timer_->start(1000);

    setTextInCenter(ui->date, QDate::currentDate().toString("dd-MM-yyyy"));
    setTextInCenter(ui->pageName, HOMEPAGE);

    lastOperationLabels_.at(0) = ui->lastAmount;
    lastOperationLabels_.at(1) = ui->lastDate;
    lastOperationLabels_.at(2) = ui->lastCategory;

    showNewestOperation();
    showNewestBalance();

    connect(balance_, &Balance::lastOperationChanged, this, &MainWindow::updateNewestOperation);
    connect(balance_, &Balance::lastOperationChanged, this, &MainWindow::updateCurrentBalance);

    setWindowTitle("CashTracker");
    setWindowIcon(QIcon("cashTracker.png"));
}

MainWindow::~MainWindow()
{
    balance_->getAppRegister()->saveState();
    balance_->saveCurrentState();
    delete ui;
}

void MainWindow::updateNewestOperation()
{
    showNewestOperation();
}

void MainWindow::updateCurrentBalance()
{
    showNewestBalance();
}

void MainWindow::on_homeBtn_clicked()
{
    handleMenuBtnClick(MainWindow::HomePage);
}

void MainWindow::on_incomeBtn_clicked()
{
    handleMenuBtnClick(MainWindow::IncomePage);
}

void MainWindow::on_expenseBtn_clicked()
{
    handleMenuBtnClick(MainWindow::ExpensePage);
}

void MainWindow::updateTimer()
{
    setTextInCenter(ui->time, QTime::currentTime().toString("hh:mm"));
}

void MainWindow::on_pushButton_clicked()
{
    handleMenuBtnClick(MainWindow::HomePage);
}


void MainWindow::handleMenuBtnClick(MainWindow::Pages page)
{

    if(page == curPage_)
        return;

    switch (page)
    {
    case MainWindow::HomePage:
        ui->pages->setCurrentIndex(0);
        setTextInCenter(ui->pageName, HOMEPAGE);
        break;
    case MainWindow::IncomePage:
        ui->pages->setCurrentIndex(1);
        setTextInCenter(ui->pageName, INCOMEPAGE);
        break;
    case MainWindow::ExpensePage:
        ui->pages->setCurrentIndex(2);
        setTextInCenter(ui->pageName, EXPENSEPAGE);
        break;
    }

    curPage_ = page;
}

void MainWindow::showNewestBalance()
{
    setTextInCenter(ui->balance, QString::number(std::roundf(balance_->getBalance() * 100) / 100) + " " + GLOBAL::CURRENCY);
}

void MainWindow::showNewestOperation()
{
    if(balance_->totalSize() <= 0)
        setNewestBlank();
    else
        balance_->getNewestOperation().first << lastOperationLabels_;
}

void MainWindow::setNewestBlank()
{
    for(const auto &label : lastOperationLabels_)
        label->clear();
}

void MainWindow::on_closeBtn_clicked()
{
    auto closed = close();

    if(!closed)
        throw std::runtime_error("Couldn't close application");
}

void MainWindow::on_hAddOperationBtn_clicked()
{
    Operation op;
    bool added;

    op.setNumber(balance_->totalSize());
    OperationWindow ow(&op, &added, this);
    ow.exec();

    if(added)
        balance_->changeBalance(op);
}

void MainWindow::on_hRemoveOperationBtn_clicked()
{
    if(balance_->totalSize() <= 0)
        return;

    bool remove;
    RemoveOperationWindow rw(&remove, this);

    rw.exec();

    if(remove)
        balance_->removeLastlyAddedOp();
}
