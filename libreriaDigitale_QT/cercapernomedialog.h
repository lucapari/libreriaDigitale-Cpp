#ifndef CERCAPERNOMEDIALOG_H
#define CERCAPERNOMEDIALOG_H

#include <QDialog>

namespace Ui {
class cercaPerNomeDialog;
}

class cercaPerNomeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit cercaPerNomeDialog(QWidget *parent = nullptr);
    ~cercaPerNomeDialog();

private slots:
    void on_cercaTitoloButton_clicked();

private:
    Ui::cercaPerNomeDialog *ui;
};

#endif // CERCAPERNOMEDIALOG_H
