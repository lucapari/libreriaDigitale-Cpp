#include "restituisciarticolodialog.h"
#include "ui_restituisciarticolodialog.h"
#include "mainwindow.h"

RestituisciArticoloDialog::RestituisciArticoloDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RestituisciArticoloDialog)
{
    ui->setupUi(this);

    this->setStyleSheet("background-color: black;");
    //impongo una dimensione fissa per la finestra (non resizable)
    this->setFixedSize(QSize(270, 260));
}

RestituisciArticoloDialog::~RestituisciArticoloDialog()
{
    delete ui;
}

void RestituisciArticoloDialog::on_restituisciButton_clicked()
{
    int articoloID = ui->restituisciTextEdit->toPlainText().toInt();

    //noleggio articolo e contemporaneamente leggo il return message stampato in console
    QString noleggiaMess = MainWindow::fromSTDtoQStringintArgument(&LibreriaManager::restituisciArticolo, articoloID);
    QString err1 = "Impossibile restituire articolo. L'articolo e' gia' stato restituito.\n";
    QString err2 ="Errore! Articolo non trovato.\n";

    //se il messaggio è un errore colore rosso, altrimenti verde
    if(noleggiaMess==err1 || noleggiaMess==err2 )
       ui->restituisciMessageLabel->setStyleSheet("QLabel {color: red;}");
    else
       ui->restituisciMessageLabel->setStyleSheet("QLabel {color: green;}");

    ui->restituisciMessageLabel->setText(noleggiaMess);

}

