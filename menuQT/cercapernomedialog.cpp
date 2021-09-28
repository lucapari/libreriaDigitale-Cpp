#include "cercapernomedialog.h"
#include "ui_cercapernomedialog.h"
#include "mainwindow.h"

cercaPerNomeDialog::cercaPerNomeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cercaPerNomeDialog)
{
    ui->setupUi(this);

    this->setStyleSheet("background-color: black;");
    //impongo una dimensione fissa per la finestra (non resizable)
    this->setFixedSize(QSize(260, 450));
}

cercaPerNomeDialog::~cercaPerNomeDialog()
{
    delete ui;
}

void cercaPerNomeDialog::on_cercaTitoloButton_clicked()
{

    string nomeArticolo = ui->cercaTitoloTextEdit->toPlainText().toStdString();

    //invoco il metodo printArticolo di LibreriaManager e salvo il risultato stampato in console in cercaMess
    QString cercaMess = MainWindow::fromSTDtoQStringstringArgument(&LibreriaManager::printArticolo, nomeArticolo);
    QString err ="Errore! Articolo non trovato.\n";

    //se il messaggio è un errore colore rosso, altrimenti verde
    if(cercaMess==err){
       ui->cercaTitoloEdit->clear();
       ui->cercaTitoloErrorLabel->setStyleSheet("QLabel {color: red;}");
       ui->cercaTitoloErrorLabel->setText(cercaMess);
    }
    else {
       ui->cercaTitoloErrorLabel->setText(" ");
       ui->cercaTitoloEdit->clear();
       ui->cercaTitoloEdit->appendPlainText(cercaMess);
    }

}

