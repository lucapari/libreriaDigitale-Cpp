#include "visualizzaarticolidialog.h"
#include "ui_visualizzaarticolidialog.h"

#include <mainwindow.h>

#include "manager/libreriamanager.h"
#include "libreria/rivista.h"
#include "libreria/libro.h"
#include "libreria/audio.h"
#include "libreria/audiolibro.h"


#include <sstream>

using namespace std;

VisualizzaArticoliDialog::VisualizzaArticoliDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VisualizzaArticoliDialog)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: black;");
    //impongo una dimensione fissa per la finestra (non resizable)
    this->setFixedSize(QSize(930, 600));


    //leggo testo stampato in console da printSottocategoria<T> e converto in QString
    QString libri = MainWindow::fromSTDtoQStringTipoArticoloArgument(&LibreriaManager::printSottocategoria<Libro>, tipoLibro);
    ui->libriTextEdit->appendPlainText(libri);

    QString audio = MainWindow::fromSTDtoQStringTipoArticoloArgument(&LibreriaManager::printSottocategoria<Audio>, tipoAudio);
    ui->audioTextEdit->appendPlainText(audio);

    QString riviste = MainWindow::fromSTDtoQStringTipoArticoloArgument(&LibreriaManager::printSottocategoria<Rivista>, tipoRivista);
    ui->rivisteTextEdit->appendPlainText(riviste);

    QString audiolibri = MainWindow::fromSTDtoQStringTipoArticoloArgument(&LibreriaManager::printSottocategoria<AudioLibro>, tipoAudiolibro);
    ui->audiolibriTextEdit->appendPlainText(audiolibri);

}

VisualizzaArticoliDialog::~VisualizzaArticoliDialog()
{
    delete ui;
}
