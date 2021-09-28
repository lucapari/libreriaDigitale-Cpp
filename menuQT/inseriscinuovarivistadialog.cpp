#include "inseriscinuovarivistadialog.h"
#include "ui_inseriscinuovarivistadialog.h"
#include "mainwindow.h"

#include "libreria/rivista.h"
#include "manager/libreriamanager.h"

#include <string>



InserisciNuovaRivistaDialog::InserisciNuovaRivistaDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InserisciNuovaRivistaDialog)
{
    ui->setupUi(this);

    ui->rivistaInseritaLabel->setVisible(false);

    this->setStyleSheet("background-color: black;");
    //impongo una dimensione fissa per la finestra (non resizable)
    this->setFixedSize(QSize(720, 450));

}

InserisciNuovaRivistaDialog::~InserisciNuovaRivistaDialog()
{
    delete ui;
}

void InserisciNuovaRivistaDialog::on_inserisciNuovaRivistaButton_clicked()
{
    //ricavo le informazioni dai textBox
    string titolo = ui->titoloRTextEdit->toPlainText().toStdString();
    string data = ui->dataRTextEdit->toPlainText().toStdString();
    string casaEditrice = ui->casaEditriceRTextEdit->toPlainText().toStdString();

    Rivista* newRiv = new Rivista(titolo,data,casaEditrice);
    LibreriaManager::instance().aggiungiArticolo(newRiv);

    ui->rivistaInseritaLabel->setVisible(true);

    //leggo testo stampato in console con info sul nuovo articolo
    QString rivistaInserita = MainWindow::fromSTDtoQStringstringArgument(&LibreriaManager::printArticolo, titolo);
    ui->rivistaInseritaTextEdit->appendPlainText(rivistaInserita);
}

