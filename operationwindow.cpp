#include "operationwindow.h"
#include "ui_operationwindow.h"


#include <QDebug>
OperationWindow::OperationWindow(Operation *operation, bool *added, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OperationWindow),
    operation_(operation),
    added_(added)
{
    ui->setupUi(this);
    ui->dateInput->setDateTime(QDateTime::currentDateTime());
    ui->dateInput->setMaximumDate(QDate::currentDate());

    setWindowTitle("Add new operation");
}

OperationWindow::~OperationWindow()
{
    delete ui;
}

void OperationWindow::accept()
{
    if(getValuesFromInputs())
    {
        *added_ = true;
        hide();
    }
}

void OperationWindow::reject()
{
    *added_ = false;
    hide();
}

void OperationWindow::on_addOpBtn_clicked()
{
    accept();
}

void OperationWindow::on_cancelOpBtn_clicked()
{
    reject();
}

bool OperationWindow::getValuesFromInputs()
{
    //TODO: Check if number has no more than two numbers after .

    bool correctlyReaded(true);
    auto amount = ui->amountInput->toPlainText().toFloat(&correctlyReaded);
    auto date = ui->dateInput->dateTime();
    auto category = ui->categoryInput->toPlainText();

    if(!category.isEmpty() && correctlyReaded)
    {
        operation_->setValue(amount);
        operation_->setDate(date);
        operation_->setCategory(category);

        return true;
    }
    else return false;

    return false;
}
