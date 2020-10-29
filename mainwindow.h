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
    void on_homeBtn_clicked();

    void on_incomeBtn_clicked();

    void on_expenseBtn_clicked();

    void updateTimer();

    void on_closeBtn_clicked();

private:
    Ui::MainWindow *ui;
    Balance *balance_;

    enum Pages{HomePage, IncomePage, ExpensePage};

    Pages curPage_;
    std::array<QLabel *, 3> lastOperationLabels_; //amount, date, category

    QTimer *timer_;

    void handleMenuBtnClick(Pages page);

};
#endif // MAINWINDOW_H
