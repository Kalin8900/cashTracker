#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QMessageBox>
#include <QtQuickWidgets/QQuickWidget>
#include <QDebug>
#include "GLOBALS.h"

using GLOBAL::setTextInCenter;

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
    setTextInCenter(ui->pageName, "Home");

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

void MainWindow::on_pushButton_clicked()
{
    ui->pages->setCurrentIndex(0);
    setTextInCenter(ui->pageName, "Home");
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->pages->setCurrentIndex(1);
    setTextInCenter(ui->pageName, "Income");
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->pages->setCurrentIndex(2);
    setTextInCenter(ui->pageName, "Expense");
}

void MainWindow::updateTimer()
{
    setTextInCenter(ui->time, QTime::currentTime().toString("hh:mm"));
}
