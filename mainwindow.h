#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTime>
#include <QDate>
#include <QTimer>
#include <QLabel>
#include <array>
#include "balance.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(Balance *balance, QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void updateTimer();

private:
    Ui::MainWindow *ui;
    Balance *balance_;

    std::array<QLabel *, 3> lastOperationLabels_; //amount, date, category

    QTimer *timer_;

};
#endif // MAINWINDOW_H
