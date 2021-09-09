/*
 * ArticoloLibreria.h
 *
 *      Author: Luca Parimbelli
 */

#include "articololibreria.h"

#include<string>
using namespace std;

int ArticoloLibreria::staticID = 0;

ArticoloLibreria::ArticoloLibreria(int titolo, TipoArticolo tipo) {
	articoloID = ++staticID;
	ArticoloLibreria::titolo = titolo;
	ArticoloLibreria::tipo = tipo;

	//un libro è disponibile appena viene inserito nel sistema
	ArticoloLibreria::disponibilita = true;
}

ArticoloLibreria::~ArticoloLibreria() {
}

int ArticoloLibreria::getArticoloID() {
	return articoloID;
}

bool ArticoloLibreria::getDisponibilita() {
	return disponibilita;
}

string ArticoloLibreria::getTitolo() {
	return titolo;
}

TipoArticolo ArticoloLibreria::getTipo() {
	return tipo;
}

