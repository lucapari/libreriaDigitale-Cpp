#ifndef INSERISCINUOVOLIBRO_H
#define INSERISCINUOVOLIBRO_H

#include <QDialog>

namespace Ui {
class inserisciNuovoLibro;
}

class inserisciNuovoLibroDialog : public QDialog
{
    Q_OBJECT

public:
    explicit inserisciNuovoLibroDialog(QWidget *parent = nullptr);
    ~inserisciNuovoLibroDialog();

private slots:
    void on_inserisciNuovoLibroButton_clicked();

private:
    Ui::inserisciNuovoLibro *ui;
};

#endif // INSERISCINUOVOLIBRO_H
