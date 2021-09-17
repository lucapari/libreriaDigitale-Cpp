/*
 * main.cpp
 *
 *      Author: Luca Parimbelli
 */

#include <iostream>
#include "libreria/datetimepub.h"
#include "libreria/audio.h"
#include "libreria/rivista.h"
#include "libreria/libro.h"
#include "libreria/audiolibro.h"
#include "libreria/articololibreria.h"
#include "manager/libreriamanager.h"

using namespace std;
int main(int argc, char **argv) {

//	//PROVA ISTANZIAZIONE CLASSI
//	DateTimePub d = DateTimePub("12|11|2011", 123);
//	cout << d.getDurata() << endl;
//	cout << d.getDatePub() << endl;
//
//	cout << endl;
//
//	Rivista r = Rivista("Focus Storia", "14|08|2021", "Mondadori");
//	cout << r.toString() << endl;
//
//
//	Audio a = Audio("The best of Vivaldi", 12231, "Antonio Vivaldi",
//			"Classic Lbl");
//	cout << a.toString() << endl;
//
//
//	Libro l = Libro("I Malavoglia", "01|01|2014", "Giovanni Verga", "Einaudi",
//			320);
//	cout << l.toString() << endl;
//
//
//	AudioLibro al = AudioLibro("L'insostenibile leggerezza dell'essere", "01|01|2016", 31242, "Marco Narri", "Kundera Milan", "Einaudi", "Audiolibri_Label");
//	cout<<al.toString()<<endl;
//
//
//	//PROVA BINDING DINAMICO toString()
//	ArticoloLibreria* art_riv = new Rivista("Wired", "21|06|2021", "Conde Nast Publications");
//	cout<<art_riv->toString()<<endl;
//
//	ArticoloLibreria* art_aud = new Audio("West End Blues", 318, "Louis Armstrong", "Columbia Jazz Classics");
//	cout<<art_aud->toString()<<endl;
//
//	ArticoloLibreria* art_lib = new Libro("Anna Karenina", "02|02|2018", "Lev Tolstoj", "Feltrinelli", 1107);
//	cout<<art_lib->toString()<<endl;
//
//	ArticoloLibreria* art_audlib = new AudioLibro("Il Conte di Montecristo", "05|06|2013", 62145, "Marco Mosso", "Alexandre Dumas", "Rizzoli", "narraLibri casa");
//	cout<<art_audlib->toString()<<endl;
//
//	//PROVA OVERLOAD == OPERATOR
//	cout<<(art_riv==art_aud)<<endl;
//	cout<<(art_riv==art_riv)<<endl;
//	cout<<(r==r)<<endl;
//
	LibreriaManager::instance().printAllArticoli();

	cout<<"-------------------Elimino ID 6-----------------------"<<endl<<endl;
	LibreriaManager::instance().rimuoviArticolo(6);
	LibreriaManager::instance().printAllArticoli();

	cout<<"-------------------Presto ID 3-----------------------"<<endl<<endl;
	LibreriaManager::instance().prestaArticolo(3);
	LibreriaManager::instance().prestaArticolo(3);
	LibreriaManager::instance().printAllArticoli();

	cout << "-------------------Restituisco ID 3-----------------------" << endl<< endl;
	LibreriaManager::instance().restituisciArticolo(3);
	LibreriaManager::instance().restituisciArticolo(3);
	LibreriaManager::instance().printAllArticoli();

	cout << "-------------------Stampo articolo con ID 3-----------------------"<< endl << endl;
	LibreriaManager::instance().printArticolo(3);

	cout << "-------------------Stampo articolo titolo Wired-----------------------"<< endl << endl;
	LibreriaManager::instance().printArticolo("Wired");

	cout << "-------------------Stampo solo RIVISTE-----------------------"<< endl << endl;
	LibreriaManager::instance().printSottocategoria<Rivista>(TipoArticolo::tipoRivista);



	return 0;
}

