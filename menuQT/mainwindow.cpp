#include "mainwindow.h"
#include "ui_mainwindow.h"

#include<sstream>

#include "libreria/libro.h"
#include "manager/libreriamanager.h"
#include "libreria/tipoarticolo.h"


#include "visualizzaarticolidialog.h"
#include "inseriscinuovolibro.h"
#include "inseriscinuovoaudiodialog.h"
#include "inseriscinuovarivistadialog.h"
#include "inseriscinuovoaudiolibrodialog.h"
#include "noleggiaarticolodialog.h"
#include "restituisciarticolodialog.h"
#include "cercaperiddialog.h"
#include "cercapernomedialog.h"
#include "rimuoviarticolodialog.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    this->setStyleSheet("background-color: black;");

    //inizializza la libreria tramite LibreriaInitializer chiamata dal costruttore di LibreriaManager
    LibreriaManager::instance();

    //impongo una dimensione fissa per la finestra (non resizable)
    this->setFixedSize(QSize(700, 600));

    ui->widgetCercaArticolo->setVisible(false);
    ui->widgetInserisciArticolo->setVisible(false);


}

MainWindow::~MainWindow()
{
    delete ui;
}


//funzione di supporto per convertire da stdout (console) a QString
//argomento = funzione della classe LibreriaManager senza parametri
QString MainWindow::fromSTDtoQStringVoidArgument(void (LibreriaManager::*func)()){

    //preparo il buffer per la lettura del testo da stdout
    stringstream buffer;
    cout.rdbuf(buffer.rdbuf());
    //stampo in stdout chiamando la funzione di LibreriaManager passata come parametro
    //il buffer leggerà quello che viene stampato a stdout
    (LibreriaManager::instance().*func)();
    //trasformo il testo del buffer in una stringa
    std::string text = buffer.str();
    //converto la std::string in una Qstring
    QString res = QString::fromStdString(text);

    return res;
}

//argomento = funzione della classe LibreriaManager con parametro di tipo TipoArticolo
QString MainWindow::fromSTDtoQStringTipoArticoloArgument(void (LibreriaManager::*func)(TipoArticolo), TipoArticolo tipoArt){
    stringstream buffer;
    cout.rdbuf(buffer.rdbuf());

    (LibreriaManager::instance().*func)(tipoArt);

    std::string text = buffer.str();
    QString res = QString::fromStdString(text);

    return res;
}

//argomento = funzione della classe LibreriaManager con parametro di tipo string
QString MainWindow::fromSTDtoQStringstringArgument(void (LibreriaManager::*func)(string), string nomeArticolo){
    stringstream buffer;
    cout.rdbuf(buffer.rdbuf());

    (LibreriaManager::instance().*func)(nomeArticolo);

    std::string text = buffer.str();
    QString res = QString::fromStdString(text);

    return res;
}


//argomento = funzione della classe LibreriaManager con parametro di tipo int
QString MainWindow::fromSTDtoQStringintArgument(void (LibreriaManager::*func)(int), int articoloID){
    stringstream buffer;
    cout.rdbuf(buffer.rdbuf());

    (LibreriaManager::instance().*func)(articoloID);

    std::string text = buffer.str();
    QString res = QString::fromStdString(text);

    return res;
}


void MainWindow::on_visualizzaLibreriaButton_clicked()
{
    //apro una nuova finestra (dialog) per la visualizzazione degli articoli libreria
    //utilizzo smart pointer per evitare eventuali memory leak
    unique_ptr <VisualizzaArticoliDialog> newWindow (new VisualizzaArticoliDialog());
    newWindow->setModal(true);
    newWindow->exec();
}

void MainWindow::on_cercaArticoloButton_clicked()
{
    ui->widgetMenuScelta->setVisible(false);
    ui->widgetCercaArticolo->setVisible(true);
}

void MainWindow::on_backToMenuSceltaButton_clicked()
{
    ui->widgetCercaArticolo->setVisible(false);
    ui->widgetMenuScelta->setVisible(true);
}

void MainWindow::on_inserisciNuovoArticoloButton_clicked()
{
    ui->widgetMenuScelta->setVisible(false);
    ui->widgetInserisciArticolo->setVisible(true);
}

void MainWindow::on_backToMenuSceltaButton_3_clicked()
{
    ui->widgetInserisciArticolo->setVisible(false);
    ui->widgetMenuScelta->setVisible(true);
}


void MainWindow::on_inserisciLibroButton_clicked()
{
    //apro una nuova finestra (dialog) per la visualizzazione dell'inserimento nuovo libro
    unique_ptr <inserisciNuovoLibroDialog> newWindow (new inserisciNuovoLibroDialog());
    newWindow->setModal(true);
    newWindow->exec();

}

void MainWindow::on_inserisciAudioButton_clicked()
{
    unique_ptr <InserisciNuovoAudioDialog> newWindow (new InserisciNuovoAudioDialog());
    newWindow->setModal(true);
    newWindow->exec();

}


void MainWindow::on_inserisciRivistaButton_clicked()
{

    unique_ptr <InserisciNuovaRivistaDialog> newWindow (new InserisciNuovaRivistaDialog());
    newWindow->setModal(true);
    newWindow->exec();

}


void MainWindow::on_inserisciAudiolibroButton_clicked()
{

    unique_ptr <InserisciNuovoAudiolibroDialog> newWindow (new InserisciNuovoAudiolibroDialog());
    newWindow->setModal(true);
    newWindow->exec();

}


void MainWindow::on_backToMenuSceltaButton_2_clicked(){}
void MainWindow::on_visualizzaTuttiArtButton_clicked(){}

void MainWindow::on_noleggiaArticoloButton_clicked()
{
    unique_ptr <NoleggiaArticoloDialog> newWindow (new NoleggiaArticoloDialog());
    newWindow->setModal(true);
    newWindow->exec();

}


void MainWindow::on_restituisciArticoloButton_clicked()
{
    unique_ptr <RestituisciArticoloDialog> newWindow (new RestituisciArticoloDialog());
    newWindow->setModal(true);
    newWindow->exec();
}


void MainWindow::on_cercaIDButton_clicked()
{
    unique_ptr <cercaPerIDDialog> newWindow (new cercaPerIDDialog());
    newWindow->setModal(true);
    newWindow->exec();
}


void MainWindow::on_cercaNomeButton_clicked()
{
    unique_ptr <cercaPerNomeDialog> newWindow (new cercaPerNomeDialog());
    newWindow->setModal(true);
    newWindow->exec();
}


void MainWindow::on_rimuoviArticoloButton_clicked()
{
    unique_ptr <rimuoviArticoloDialog> newWindow (new rimuoviArticoloDialog());
    newWindow->setModal(true);
    newWindow->exec();
}

