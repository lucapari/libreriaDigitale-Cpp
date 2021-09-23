#include "rimuoviarticolodialog.h"
#include "ui_rimuoviarticolodialog.h"
#include "mainwindow.h"

rimuoviArticoloDialog::rimuoviArticoloDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::rimuoviArticoloDialog)
{
    ui->setupUi(this);

    this->setStyleSheet("background-color: black;");
    //impongo una dimensione fissa per la finestra (non resizable)
    this->setFixedSize(QSize(270, 260));
}

rimuoviArticoloDialog::~rimuoviArticoloDialog()
{
    delete ui;
}

void rimuoviArticoloDialog::on_rimuoviButton_clicked()
{
    int articoloID = ui->rimuoviTextEdit->toPlainText().toInt();

    //rimuovo articolo e contemporaneamente leggo il return message stampato in console
    QString rimuoviMess = MainWindow::fromSTDtoQStringintArgument(&LibreriaManager::rimuoviArticolo, articoloID);
    QString err ="Errore! Articolo non trovato.\n";

    //se il messaggio è un errore colore rosso, altrimenti verde
    if(rimuoviMess==err)
       ui->rimuoviMessageLabel->setStyleSheet("QLabel {color: red;}");
    else
       ui->rimuoviMessageLabel->setStyleSheet("QLabel {color: green;}");

    ui->rimuoviMessageLabel->setText(rimuoviMess);

}

