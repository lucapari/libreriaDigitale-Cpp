#include "noleggiaarticolodialog.h"
#include "ui_noleggiaarticolodialog.h"
#include "mainwindow.h"

#include "manager/libreriamanager.h"

NoleggiaArticoloDialog::NoleggiaArticoloDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NoleggiaArticoloDialog)
{
    ui->setupUi(this);

    this->setStyleSheet("background-color: black;");
    //impongo una dimensione fissa per la finestra (non resizable)
    this->setFixedSize(QSize(270, 260));
}

NoleggiaArticoloDialog::~NoleggiaArticoloDialog()
{
    delete ui;
}

void NoleggiaArticoloDialog::on_noleggiaButton_clicked()
{
    int articoloID = ui->noleggiaTextEdit->toPlainText().toInt();

    //noleggio articolo e contemporaneamente leggo il return message stampato in console
    QString noleggiaMess = MainWindow::fromSTDtoQStringintArgument(&LibreriaManager::noleggiaArticolo, articoloID);
    QString err1 = "Impossibile prestare articolo. L'articolo non e' disponibile.\n";
    QString err2 ="Errore! Articolo non trovato.\n";

    //se il messaggio è un errore colore rosso, altrimenti verde
    if(noleggiaMess==err1 || noleggiaMess==err2 )
       ui->noleggiaMessageLabel->setStyleSheet("QLabel {color: red;}");
    else
       ui->noleggiaMessageLabel->setStyleSheet("QLabel {color: green;}");

    ui->noleggiaMessageLabel->setText(noleggiaMess);


}

