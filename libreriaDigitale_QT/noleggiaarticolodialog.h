#ifndef NOLEGGIAARTICOLODIALOG_H
#define NOLEGGIAARTICOLODIALOG_H

#include <QDialog>

namespace Ui {
class NoleggiaArticoloDialog;
}

class NoleggiaArticoloDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NoleggiaArticoloDialog(QWidget *parent = nullptr);
    ~NoleggiaArticoloDialog();

private slots:
    void on_noleggiaButton_clicked();

private:
    Ui::NoleggiaArticoloDialog *ui;
};

#endif // NOLEGGIAARTICOLODIALOG_H
