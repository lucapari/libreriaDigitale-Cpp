#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <manager/libreriamanager.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    /*
     *   Tutti i metodi di LibreriaManager stampano con "cout<<" su console:
     *   devo prendere il testo dalla console e convertirlo in QString per poterlo
     *   visualizzare nelle window di QT
     *
     */

    /*funzioni di supporto per convertire da stdout (console) a QString*/

    //prende come parametro una funzione che non ha parametri
    static QString fromSTDtoQStringVoidArgument(void (LibreriaManager::*func)());

    //prende come parametro una funzione che prende un TipoArticolo come parametro
    static QString fromSTDtoQStringTipoArticoloArgument(void (LibreriaManager::*func)(TipoArticolo),  TipoArticolo tipoArt);

    //prende come parametro una funzione che prende un string come parametro
    static QString fromSTDtoQStringstringArgument(void (LibreriaManager::*func)(string), string nomeArticolo);

    //prende come parametro una funzione che prende un string come parametro
    static QString fromSTDtoQStringintArgument(void (LibreriaManager::*func)(int), int articoloID);


private slots:
    void on_visualizzaLibreriaButton_clicked();

    void on_backToMenuSceltaButton_clicked();

    void on_backToMenuSceltaButton_2_clicked();

    void on_backToMenuSceltaButton_3_clicked();

    void on_cercaArticoloButton_clicked();

    void on_inserisciNuovoArticoloButton_clicked();

    void on_visualizzaTuttiArtButton_clicked();

    void on_inserisciLibroButton_clicked();

    void on_inserisciAudioButton_clicked();

    void on_inserisciRivistaButton_clicked();

    void on_inserisciAudiolibroButton_clicked();

    void on_noleggiaArticoloButton_clicked();

    void on_restituisciArticoloButton_clicked();

    void on_cercaIDButton_clicked();

    void on_cercaNomeButton_clicked();

    void on_rimuoviArticoloButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
