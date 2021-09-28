#ifndef RESTITUISCIARTICOLODIALOG_H
#define RESTITUISCIARTICOLODIALOG_H

#include <QDialog>

namespace Ui {
class RestituisciArticoloDialog;
}

class RestituisciArticoloDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RestituisciArticoloDialog(QWidget *parent = nullptr);
    ~RestituisciArticoloDialog();

private slots:
    void on_restituisciButton_clicked();

private:
    Ui::RestituisciArticoloDialog *ui;
};

#endif // RESTITUISCIARTICOLODIALOG_H
