#ifndef CERCAPERIDDIALOG_H
#define CERCAPERIDDIALOG_H

#include <QDialog>

namespace Ui {
class cercaPerIDDialog;
}

class cercaPerIDDialog : public QDialog
{
    Q_OBJECT

public:
    explicit cercaPerIDDialog(QWidget *parent = nullptr);
    ~cercaPerIDDialog();

private slots:
    void on_cercaIDButton_clicked();

private:
    Ui::cercaPerIDDialog *ui;
};

#endif // CERCAPERIDDIALOG_H
