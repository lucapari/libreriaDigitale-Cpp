#include "inseriscinuovolibro.h"
#include "ui_inseriscinuovolibro.h"

#include "mainwindow.h"

#include "libreria/libro.h"
#include "manager/libreriamanager.h"

inserisciNuovoLibroDialog::inserisciNuovoLibroDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::inserisciNuovoLibro)
{
    ui->setupUi(this);
    ui->libroInseritoLabel->setVisible(false);

    this->setStyleSheet("background-color: black;");
    //impongo una dimensione fissa per la finestra (non resizable)
    this->setFixedSize(QSize(720, 450));
}

inserisciNuovoLibroDialog::~inserisciNuovoLibroDialog()
{
    delete ui;
}

void inserisciNuovoLibroDialog::on_inserisciNuovoLibroButton_clicked()
{
    //ricavo le informazioni dai textBox
    string titolo = ui->titoloLTextEdit->toPlainText().toStdString();
    string data = ui->dataLTextEdit->toPlainText().toStdString();
    string autore = ui->autoreLTextEdit->toPlainText().toStdString();
    string casaEditrice = ui->casaEditriceLTextEdit->toPlainText().toStdString();
    int numPagine = ui->numPagineLTextEdit->toPlainText().toInt();

    Libro* newLib = new Libro(titolo,data,autore,casaEditrice,numPagine);
    LibreriaManager::instance().aggiungiArticolo(newLib);

    ui->libroInseritoLabel->setVisible(true);

    //leggo testo stampato in console con info sul nuovo articolo
    QString libroInserito = MainWindow::fromSTDtoQStringstringArgument(&LibreriaManager::printArticolo, titolo);
    ui->libroInseritoTextEdit->appendPlainText(libroInserito);


}

