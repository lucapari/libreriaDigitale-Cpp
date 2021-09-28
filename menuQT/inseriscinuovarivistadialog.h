#ifndef INSERISCINUOVARIVISTADIALOG_H
#define INSERISCINUOVARIVISTADIALOG_H

#include <QDialog>

namespace Ui {
class InserisciNuovaRivistaDialog;
}

class InserisciNuovaRivistaDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InserisciNuovaRivistaDialog(QWidget *parent = nullptr);
    ~InserisciNuovaRivistaDialog();

private slots:
    void on_inserisciNuovaRivistaButton_clicked();

private:
    Ui::InserisciNuovaRivistaDialog *ui;
};

#endif // INSERISCINUOVARIVISTADIALOG_H
