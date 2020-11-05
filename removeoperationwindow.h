#ifndef REMOVEOPERATIONWINDOW_H
#define REMOVEOPERATIONWINDOW_H

#include <QDialog>

namespace Ui {
class RemoveOperationWindow;
}

class RemoveOperationWindow : public QDialog
{
    Q_OBJECT

public:
    explicit RemoveOperationWindow(bool *remove, QWidget *parent = nullptr);
    ~RemoveOperationWindow();

private slots:
    void on_goBackBtn_clicked();

    void on_removeOpBtn_clicked();

private:
    Ui::RemoveOperationWindow *ui;

    bool *remove_;
};

#endif // REMOVEOPERATIONWINDOW_H
