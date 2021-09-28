#include "inseriscinuovoaudiodialog.h"
#include "ui_inseriscinuovoaudiodialog.h"
#include "mainwindow.h"

#include "libreria/audio.h"
#include "manager/libreriamanager.h"


InserisciNuovoAudioDialog::InserisciNuovoAudioDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InserisciNuovoAudioDialog)
{
    ui->setupUi(this);
    ui->audioInseritoLabel->setVisible(false);

    this->setStyleSheet("background-color: black;");
    //impongo una dimensione fissa per la finestra (non resizable)
    this->setFixedSize(QSize(720, 450));
}

InserisciNuovoAudioDialog::~InserisciNuovoAudioDialog()
{
    delete ui;
}

void InserisciNuovoAudioDialog::on_inserisciNuovoAudioButton_clicked()
{
    //ricavo le informazioni dai textBox
    string titolo = ui->titoloATextEdit->toPlainText().toStdString();
    int durata = ui->durataATextEdit->toPlainText().toInt();
    string autore = ui->autoreATextEdit->toPlainText().toStdString();
    string casaDiscografica = ui->casaDiscATextEdit->toPlainText().toStdString();

    Audio* newAudio = new Audio(titolo,durata,autore,casaDiscografica);
    LibreriaManager::instance().aggiungiArticolo(newAudio);

    ui->audioInseritoLabel->setVisible(true);

    //leggo testo stampato in console con info sul nuovo articolo
    QString audioInserito = MainWindow::fromSTDtoQStringstringArgument(&LibreriaManager::printArticolo, titolo);
    ui->audioInseritoTextEdit->appendPlainText(audioInserito);

}

