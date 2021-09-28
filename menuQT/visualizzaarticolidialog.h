#ifndef VISUALIZZAARTICOLIDIALOG_H
#define VISUALIZZAARTICOLIDIALOG_H

#include <QDialog>

namespace Ui {
class VisualizzaArticoliDialog;
}

class VisualizzaArticoliDialog : public QDialog
{
    Q_OBJECT

public:
    explicit VisualizzaArticoliDialog(QWidget *parent = nullptr);
    ~VisualizzaArticoliDialog();

private:
    Ui::VisualizzaArticoliDialog *ui;
};

#endif // VISUALIZZAARTICOLIDIALOG_H
