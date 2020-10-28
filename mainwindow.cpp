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
    handleMenuBtnClick(MainWindow::HomeButton);
}

void MainWindow::on_incomeBtn_clicked()
{
    handleMenuBtnClick(MainWindow::IncomeButton);
}

void MainWindow::on_expenseBtn_clicked()
{

    handleMenuBtnClick(MainWindow::ExpenseButton);
}

void MainWindow::updateTimer()
{
    setTextInCenter(ui->time, QTime::currentTime().toString("hh:mm"));
}

void MainWindow::handleMenuBtnClick(MainWindow::MenuButtons btnType)
{
    switch (btnType)
    {
    case MainWindow::HomeButton:
        ui->pages->setCurrentIndex(0);
        setTextInCenter(ui->pageName, HOMEPAGE);
        break;
    case MainWindow::IncomeButton:
        ui->pages->setCurrentIndex(1);
        setTextInCenter(ui->pageName, INCOMEPAGE);
        break;
    case MainWindow::ExpenseButton:
        ui->pages->setCurrentIndex(2);
        setTextInCenter(ui->pageName, EXPENSEPAGE);
        break;

    }
}
