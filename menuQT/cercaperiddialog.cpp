#include "cercaperiddialog.h"
#include "ui_cercaperiddialog.h"
#include "mainwindow.h"

cercaPerIDDialog::cercaPerIDDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cercaPerIDDialog)
{
    ui->setupUi(this);

    this->setStyleSheet("background-color: black;");
    //impongo una dimensione fissa per la finestra (non resizable)
    this->setFixedSize(QSize(260, 450));
}

cercaPerIDDialog::~cercaPerIDDialog()
{
    delete ui;
}

void cercaPerIDDialog::on_cercaIDButton_clicked()
{

    int articoloID = ui->cercaIDTextEdit->toPlainText().toInt();

    //invoco il metodo printArticolo di LibreriaManager e salvo il risultato stampato in console in cercaMess
    QString cercaMess = MainWindow::fromSTDtoQStringintArgument(&LibreriaManager::printArticolo, articoloID);
    QString err ="Errore! Articolo non trovato.\n";

    //se il messaggio è un errore colore rosso, altrimenti verde
    if(cercaMess==err){
       ui->cercaIDEdit->clear();
       ui->cercaIDErrorLabel->setStyleSheet("QLabel {color: red;}");
       ui->cercaIDErrorLabel->setText(cercaMess);
    }
    else {
       ui->cercaIDErrorLabel->setText(" ");
       ui->cercaIDEdit->clear();
       ui->cercaIDEdit->appendPlainText(cercaMess);
    }

}

