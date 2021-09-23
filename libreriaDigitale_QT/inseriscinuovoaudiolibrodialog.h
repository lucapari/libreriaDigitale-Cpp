#ifndef INSERISCINUOVOAUDIOLIBRODIALOG_H
#define INSERISCINUOVOAUDIOLIBRODIALOG_H

#include <QDialog>

namespace Ui {
class InserisciNuovoAudiolibroDialog;
}

class InserisciNuovoAudiolibroDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InserisciNuovoAudiolibroDialog(QWidget *parent = nullptr);
    ~InserisciNuovoAudiolibroDialog();

private slots:
    void on_inserisciNuovoAUButton_clicked();

private:
    Ui::InserisciNuovoAudiolibroDialog *ui;
};

#endif // INSERISCINUOVOAUDIOLIBRODIALOG_H
