#ifndef INSERISCINUOVOAUDIODIALOG_H
#define INSERISCINUOVOAUDIODIALOG_H

#include <QDialog>

namespace Ui {
class InserisciNuovoAudioDialog;
}

class InserisciNuovoAudioDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InserisciNuovoAudioDialog(QWidget *parent = nullptr);
    ~InserisciNuovoAudioDialog();

private slots:
    void on_inserisciNuovoAudioButton_clicked();

private:
    Ui::InserisciNuovoAudioDialog *ui;
};

#endif // INSERISCINUOVOAUDIODIALOG_H
