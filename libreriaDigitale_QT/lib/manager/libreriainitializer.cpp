/*
 * libreriainitializer.cpp
 *
 *      Author: Luca Parimbelli
 */

#include "libreriainitializer.h"
#include "../libreria/articololibreria.h"
#include "../libreria/audio.h"
#include "../libreria/audiolibro.h"
#include "../libreria/libro.h"
#include "../libreria/rivista.h"

void LibreriaInitializer::inizializzaLibreria(vector<ArticoloLibreria*> &vettArticoli){

	Rivista* r1 = new Rivista("Focus Storia", "14|08|2021", "Mondadori");
	Audio* a1 = new Audio("The best of Vivaldi", 12231, "Antonio Vivaldi","Classic Lbl");
	Libro* l1 = new Libro("I Malavoglia", "01|01|2014", "Giovanni Verga", "Einaudi",320);
	AudioLibro* al1 = new AudioLibro("L'insostenibile leggerezza dell'essere", "01|01|2016", 31242, "Marco Narri", "Kundera Milan", "Einaudi", "Audiolibri_Label");

	Rivista* r2 = new Rivista("Wired", "21|06|2021", "Conde Nast Publications");
	Audio* a2 = new Audio("West End Blues", 318, "Louis Armstrong", "Columbia Jazz Classics");
	Libro* l2 = new Libro("Anna Karenina", "02|02|2018", "Lev Tolstoj", "Feltrinelli", 1107);
	AudioLibro* al2 = new AudioLibro("Il Conte di Montecristo", "05|06|2013", 62145, "Marco Mosso", "Alexandre Dumas", "Rizzoli", "narraLibri casa");

	vettArticoli.push_back(r1);
	vettArticoli.push_back(a1);
	vettArticoli.push_back(l1);
	vettArticoli.push_back(al1);
	vettArticoli.push_back(r2);
	vettArticoli.push_back(a2);
	vettArticoli.push_back(l2);
	vettArticoli.push_back(al2);

}

