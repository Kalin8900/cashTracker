#include "removeoperationwindow.h"
#include "ui_removeoperationwindow.h"

RemoveOperationWindow::RemoveOperationWindow(bool *remove, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RemoveOperationWindow),
    remove_(remove)
{
    ui->setupUi(this);
}

RemoveOperationWindow::~RemoveOperationWindow()
{
    delete ui;
}

void RemoveOperationWindow::on_goBackBtn_clicked()
{
    *remove_ = false;
    hide();
}

void RemoveOperationWindow::on_removeOpBtn_clicked()
{
    *remove_ = true;
    hide();
}
