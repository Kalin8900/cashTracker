#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QMessageBox>
#include <QtQuickWidgets/QQuickWidget>
#include <QDebug>
#include "GLOBALS.h"

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

    balance->getLastOperation().first << lastOperationLabels_;

    setTextInCenter(ui->balance, QString::number(balance_->getBalance()) + " " + GLOBAL::CURRENCY);


}

MainWindow::~MainWindow()
{
    delete ui;
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

void MainWindow::on_closeBtn_clicked()
{
    auto closed = close();

    if(!closed)
        throw std::runtime_error("Couldn't close application");
}
