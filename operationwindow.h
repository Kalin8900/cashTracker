#ifndef OPERATIONWINDOW_H
#define OPERATIONWINDOW_H

#include <QDialog>
#include <QDateTime>
#include "operation.h"


namespace Ui {
class OperationWindow;
}

class OperationWindow : public QDialog
{
    Q_OBJECT

public:
    OperationWindow(Operation *operation, bool *added, QWidget *parent = nullptr);
    ~OperationWindow();

public slots:
    void accept() override;
    void reject() override;

private slots:
    void on_addOpBtn_clicked();

    void on_cancelOpBtn_clicked();

private:
    Ui::OperationWindow *ui;
    Operation *operation_;
    bool *added_;

    bool getValuesFromInputs();

};

#endif // OPERATIONWINDOW_H
