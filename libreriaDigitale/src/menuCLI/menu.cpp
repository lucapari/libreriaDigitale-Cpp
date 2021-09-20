/*
 * menu.cpp
 *
 *      Author: Luca Parimbelli
 */

#include "menu.h"
#include <string>
#include <iostream>
#include "../manager/libreriamanager.h"
#include "../libreria/libro.h"
#include "../libreria/rivista.h"
#include "../libreria/audio.h"
#include "../libreria/audiolibro.h"
#include "../libreria/tipoarticolo.h"

using namespace std;

void Menu::inizializzaMenu() {

	LibreriaManager::instance(); //inizializza la libreria tramite LibreriaInitializer

	string nomeApp =
			"  _      _ _                   _         _____  _       _ _        _      \n"
					" | |    (_) |                 (_)       |  __ \\(_)     (_) |      | |     \n"
					" | |     _| |__  _ __ ___ _ __ _  __ _  | |  | |_  __ _ _| |_ __ _| | ___ \n"
					" | |    | | '_ \\| '__/ _ \\ '__| |/ _` | | |  | | |/ _` | | __/ _` | |/ _ \\\n"
					" | |____| | |_) | | |  __/ |  | | (_| | | |__| | | (_| | | || (_| | |  __/\n"
					" |______|_|_.__/|_|  \\___|_|  |_|\\__,_| |_____/|_|\\__, |_|\\__\\__,_|_|\\___|\n"
					"                                                   __/ |                  \n"
					"                                                  |___/                   ";

	string nomeAutore =
			"\t\t  _                      _                              \n"
					"\t\t |_)     |       _  _.  |_) _. ._ o ._ _  |_   _  | | o \n"
					"\t\t |_) \\/  |_ |_| (_ (_|  |  (_| |  | | | | |_) (/_ | | | \n"
					"\t\t     /                                                  ";

	cout << nomeApp << endl;
	cout << endl;
	cout << nomeAutore << endl;
	cout << endl << endl;
}

void Menu::startMenuScelta() {
	string menu =
			"*******************************************************************\n"
					"***\t\t\t    Fai la tua scelta:\t\t\t***\n"
					"*** 1] Visualizza libreria\t\t\t\t\t***\n"
					"*** 2] Noleggia articolo\t\t\t\t\t***\n"
					"*** 3] Restituisci articolo\t\t\t\t\t***\n"
					"*** 4] Cerca articolo\t\t\t\t\t\t***\n"
					"*** 5] Inserisci nuovo articolo\t\t\t\t\t***\n"
					"*** 6] Rimuovi articolo\t\t\t\t\t\t***\n"
					"***\t\t\t\t\t\t\t\t***\n"
					"*** 0] Termina il programma\t\t\t\t\t***\n"
					"***\t\t\t\t\t\t\t\t***\n"
					"*******************************************************************";

	cout << menu << endl << endl;
	int scelta = -1;
	while (!(scelta >= 0 && scelta <= 6)) {
		cout << "Scelta >> ";
		cin >> scelta;
	}

	cout << endl << endl;

	switch (scelta) {
	case 0:
		return;
		break;
	case 1:
		visualizzaLibreria();
		break;
	case 2:
		noleggiaArticolo();
		break;
	case 3:
		restituisciArticolo();
		break;
	case 4:
		cercaArticolo();
		break;
	case 5:
		inserisciArticolo();
		break;
	case 6:
		rimuoviArticolo();
		break;
	}
}

void Menu::visualizzaLibreria() {
	string menuVisLib =
			"*******************************************************************\n"
					"***\t\t\t    Fai la tua scelta:\t\t\t***\n"
					"*** 1] Visualizza tutti gli articoli\t\t\t\t***\n"
					"*** 2] Visualizza libri \t\t\t\t\t***\n"
					"*** 3] Visualizza riviste\t\t\t\t\t***\n"
					"*** 4] Visualizza audio\t\t\t\t\t\t***\n"
					"*** 5] Visualizza audiolibri\t\t\t\t\t***\n"
					"***\t\t\t\t\t\t\t\t***\n"
					"*** 0] Torna al menu principale\t\t\t\t\t***\n"
					"***\t\t\t\t\t\t\t\t***\n"
					"*******************************************************************";

	cout << menuVisLib << endl << endl;

	int scelta = -1;
	while (!(scelta >= 0 && scelta <= 5)) {
		cout << "Scelta >> ";
		cin >> scelta;
	}

	cout << endl << endl;

	switch (scelta) {
	case 0:
		startMenuScelta();
		break;
	case 1:
		visualizzaTuttiArticoli();
		break;
	case 2:
		visualizzaLibri();
		break;
	case 3:
		visualizzaRiviste();
		break;
	case 4:
		visualizzaAudio();
		break;
	case 5:
		visualizzaAudiolibri();
		break;
	}

	backToMenuScelta();
}

void Menu::visualizzaTuttiArticoli() {
	string titolo =
			"*************** Articoli presenti nella libreria:  ****************";
	cout << titolo << endl;

	LibreriaManager::instance().printAllArticoli();

	cout << endl;
}

void Menu::visualizzaRiviste() {
	string titolo =
			"*************** Riviste presenti nella libreria:  *****************";
	cout << titolo << endl;

	LibreriaManager::instance().printSottocategoria<Rivista>(
			TipoArticolo::tipoRivista);

	cout << endl;

}
void Menu::visualizzaAudio() {
	string titolo =
			"*************** Audio presenti nella libreria:  *******************";
	cout << titolo << endl;

	LibreriaManager::instance().printSottocategoria<Audio>(
			TipoArticolo::tipoAudio);

	cout << endl;
}
void Menu::visualizzaLibri() {
	string titolo =
			"***************** Libri presenti nella libreria:  *****************";
	cout << titolo << endl;

	LibreriaManager::instance().printSottocategoria<Libro>(
			TipoArticolo::tipoLibro);

	cout << endl;
}
void Menu::visualizzaAudiolibri() {
	string titolo =
			"************* Audiolibri presenti nella libreria:  ****************";
	cout << titolo << endl;

	LibreriaManager::instance().printSottocategoria<AudioLibro>(
			TipoArticolo::tipoAudiolibro);

	cout << endl;
}

void Menu::noleggiaArticolo() {
	cout << "Inserisci ID dell'articolo che si vuole noleggiare >> ";
	int articoloID;
	cin >> articoloID;

	cout << endl;
	LibreriaManager::instance().noleggiaArticolo(articoloID);

	cout << endl << endl;

	backToMenuScelta();
}
void Menu::restituisciArticolo() {
	cout << "Inserisci ID dell'articolo che si vuole restituire >> ";
	int articoloID;
	cin >> articoloID;

	cout << endl;
	LibreriaManager::instance().restituisciArticolo(articoloID);

	cout << endl << endl;

	backToMenuScelta();
}
void Menu::cercaArticolo() {
	string menuCerca =
			"*******************************************************************\n"
					"***\t\t\t    Fai la tua scelta:\t\t\t***\n"
					"*** 1] Cerca per ID\t\t\t\t\t\t***\n"
					"*** 2] Cerca per nome\t\t\t\t\t\t***\n"
					"***\t\t\t\t\t\t\t\t***\n"
					"*** 0] Torna al menu principale\t\t\t\t\t***\n"
					"***\t\t\t\t\t\t\t\t***\n"
					"*******************************************************************";

	cout << menuCerca << endl << endl;

	int scelta = -1;
	while (!(scelta >= 0 && scelta <= 2)) {
		cout << "Scelta >> ";
		cin >> scelta;
	}

	switch(scelta){
	case 0:
		startMenuScelta();
		break;
	case 1:
		cout << "Inserisci ID dell'articolo che si vuole cercare >> ";
		int articoloID;
		cin >> articoloID;
		cout<<endl;

		LibreriaManager::instance().printArticolo(articoloID);
		break;
	case 2:
		cout << "Inserisci nome dell'articolo che si vuole cercare >> ";
		string nomeArticolo;
		//non posso usare cin>> altrimenti ho errori con la gestione degli spazi
		cin.clear();
		cin.sync();
		getline(cin, nomeArticolo);
		cout<<endl;

		LibreriaManager::instance().printArticolo(nomeArticolo);
		break;
	}

	cout<<endl;

	backToMenuScelta();
}
void Menu::inserisciArticolo() {
	string menuInserisci =
			"*******************************************************************\n"
					"***\t\t\t    Fai la tua scelta:\t\t\t***\n"
					"*** 1] Inserisci nuovo libro\t\t\t\t\t***\n"
					"*** 2] Inserisci nuovo audio\t\t\t\t\t***\n"
					"*** 3] Inserisci nuova rivista\t\t\t\t\t***\n"
					"*** 4] Inserisci nuovo audiolibro\t\t\t\t***\n"
					"***\t\t\t\t\t\t\t\t***\n"
					"*** 0] Termina il programma\t\t\t\t\t***\n"
					"***\t\t\t\t\t\t\t\t***\n"
					"*******************************************************************";

	cout << menuInserisci << endl << endl;

	int scelta = -1;
	while (!(scelta >= 0 && scelta <= 4)) {
		cout << "Scelta >> ";
		cin >> scelta;
	}

	switch (scelta) {
	case 0:
		startMenuScelta();
		break;
	case 1:
		inserisciLibro();
		break;
	case 2:
		inserisciAudio();
		break;
	case 3:
		inserisciRivista();
		break;
	case 4:
		inserisciAudiolibro();
		break;
	}
}


void Menu::inserisciLibro(){
	string titolo;
	string data;
	string autore;
	string casaEditrice;
	int numPagine;

	cout<<"Titolo >>";
	cin>>titolo;
	cout<<"Data (formato \"DD|MM|YYY\") >>";
	cin>>data;
	cout<<"Autore >>";
	cin>>autore;
	cout<<"Casa editrice >>";
	cin>>casaEditrice;
	cout<<"Numero pagine >>";
	cin>>numPagine;


	Libro* lib = new Libro(titolo, data, autore, casaEditrice, numPagine);

	LibreriaManager::instance().aggiungiArticolo(lib);

	cout<<"Il seguente libro è stato aggiunto correttamente alla libreria: "<<endl<<endl;
	LibreriaManager::instance().printArticolo(titolo);

	cout<<endl;
	backToMenuScelta();

}
void Menu::inserisciAudio(){

	string titolo;
	int time;
	string autore;
	string casaDiscografica;

	cout << "Titolo >>";
	cin >> titolo;
	cout << "Durata (formato \"HHMMSS\", non iniziare con 0) >>";
	cin >> time;
	cout << "Autore >>";
	cin >> autore;
	cout << "Casa discografica >>";
	cin >> casaDiscografica;

	Audio *aud = new Audio(titolo, time, autore, casaDiscografica);

	LibreriaManager::instance().aggiungiArticolo(aud);

	cout << "Il seguente audio è stato aggiunto correttamente alla libreria: "<< endl << endl;
	LibreriaManager::instance().printArticolo(titolo);

	cout << endl;
	backToMenuScelta();

}


void Menu::inserisciRivista(){

	string titolo;
	string data;
	string autore;
	string casaEditrice;

	cout << "Titolo >>";
	cin >> titolo;
	cout << "Data (formato \"DD|MM|YYY\") >>";
	cin >> data;
	cout << "Autore >>";
	cin >> autore;
	cout << "Casa editrice >>";
	cin >> casaEditrice;

	Rivista *riv = new Rivista(titolo, data, casaEditrice);

	LibreriaManager::instance().aggiungiArticolo(riv);

	cout << "La seguente rivista è stata aggiunta correttamente alla libreria: " << endl << endl;
	LibreriaManager::instance().printArticolo(titolo);

	cout << endl;
	backToMenuScelta();

}
void Menu::inserisciAudiolibro(){

	string titolo;
	string data;
	int time;
	string audioAut;
	string libroAut;
	string casaEditrice;
	string casaDiscografica;

	cout << "Titolo >>";
	cin >> titolo;
	cout << "Data (formato \"DD|MM|YYY\") >>";
	cin >> data;
	cout << "Durata (formato \"HHMMSS\", non iniziare con 0) >>";
	cin >> time;
	cout << "Autore traccia vocale >>";
	cin >> audioAut;
	cout << "Autore libro >>";
	cin >> libroAut;
	cout << "Casa editrice >>";
	cin >> casaEditrice;
	cout << "Casa discografica >>";
	cin >> casaDiscografica;

	AudioLibro *audlib = new AudioLibro(titolo, data, time, audioAut, libroAut, casaEditrice, casaDiscografica);

	LibreriaManager::instance().aggiungiArticolo(audlib);


	cout << "Il seguente audiolibro è stato aggiunto correttamente alla libreria: "<< endl << endl;
	LibreriaManager::instance().printArticolo(titolo);

	cout << endl;
	backToMenuScelta();

}

void Menu::rimuoviArticolo() {
	cout << "Inserisci ID dell'articolo che si vuole rimuovere >> ";
	int articoloID;
	cin >> articoloID;

	cout << endl;
	LibreriaManager::instance().rimuoviArticolo(articoloID);

	cout << endl << endl;

	backToMenuScelta();
}

void Menu::backToMenuScelta() {
	int scelta = -1;
	while (scelta != 0) {
		cout << "0 per tornare al menu principale >> ";
		cin >> scelta;
	}

	startMenuScelta();
}
