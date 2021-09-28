#ifndef RIMUOVIARTICOLODIALOG_H
#define RIMUOVIARTICOLODIALOG_H

#include <QDialog>

namespace Ui {
class rimuoviArticoloDialog;
}

class rimuoviArticoloDialog : public QDialog
{
    Q_OBJECT

public:
    explicit rimuoviArticoloDialog(QWidget *parent = nullptr);
    ~rimuoviArticoloDialog();

private slots:
    void on_rimuoviButton_clicked();

private:
    Ui::rimuoviArticoloDialog *ui;
};

#endif // RIMUOVIARTICOLODIALOG_H
