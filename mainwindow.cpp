#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QMessageBox>
#include <QtQuickWidgets/QQuickWidget>
#include <QDebug>

void setTextInCenter(QLabel *l, const QString &msg)
{
    l->setText(msg);
    l->setAlignment(Qt::AlignCenter);
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      timer_(new QTimer(this))
{
    ui->setupUi(this);
    connect(timer_, &QTimer::timeout, this, QOverload<>::of(&MainWindow::updateTimer));
    timer_->start(1000);

    setTextInCenter(ui->date, QDate::currentDate().toString("dd-MM-yyyy"));
    setTextInCenter(ui->pageName, "Home");

    lastOperationLabels.at(0) = ui->lastAmount;
    lastOperationLabels.at(1) = ui->lastDate;
    lastOperationLabels.at(2) = ui->lastCategory;
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
