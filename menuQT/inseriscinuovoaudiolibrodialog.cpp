#include "inseriscinuovoaudiolibrodialog.h"
#include "ui_inseriscinuovoaudiolibrodialog.h"
#include "mainwindow.h"

#include "libreria/audiolibro.h"
#include "manager/libreriamanager.h"

InserisciNuovoAudiolibroDialog::InserisciNuovoAudiolibroDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InserisciNuovoAudiolibroDialog)
{
    ui->setupUi(this);

    ui->AUInseritoLabel->setVisible(false);

    this->setStyleSheet("background-color: black;");
    //impongo una dimensione fissa per la finestra (non resizable)
    this->setFixedSize(QSize(740, 450));
}

InserisciNuovoAudiolibroDialog::~InserisciNuovoAudiolibroDialog()
{
    delete ui;
}

void InserisciNuovoAudiolibroDialog::on_inserisciNuovoAUButton_clicked()
{
    //ricavo le informazioni dai textBox
    string titolo = ui->titoloAUTextEdit->toPlainText().toStdString();
    string data = ui->dataAUTextEdit->toPlainText().toStdString();
    int durata = ui->durataAUTextEdit->toPlainText().toInt();
    string audioAut = ui->autoreAudAUTextEdit->toPlainText().toStdString();
    string libroAut = ui->autoreAUTextEdit->toPlainText().toStdString();
    string casaEditrice = ui->casaEditriceAUTextEdit->toPlainText().toStdString();
    string casaDiscografica = ui->casaDiscograficaAUTextEdit->toPlainText().toStdString();

    AudioLibro* newAudLib = new AudioLibro(titolo,data,durata,audioAut,libroAut,casaEditrice,casaDiscografica);
    LibreriaManager::instance().aggiungiArticolo(newAudLib);

    ui->AUInseritoLabel->setVisible(true);

    //leggo testo stampato in console con info sul nuovo articolo
    QString audlibInserito = MainWindow::fromSTDtoQStringstringArgument(&LibreriaManager::printArticolo, titolo);
    ui->auInseritoTextEdit->appendPlainText(audlibInserito);


}

