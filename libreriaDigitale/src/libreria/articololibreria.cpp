/*
 * ArticoloLibreria.h
 *
 *      Author: Luca Parimbelli
 */

#include "articololibreria.h"

#include<string>
using namespace std;

//membro statico inzializzato nel .cpp
int ArticoloLibreria::staticID = 0;

//initializer list
//alla creazione di un articolo la disponibilità viene settata a true
ArticoloLibreria::ArticoloLibreria(string titolo, TipoArticolo tipo) :
		articoloID(++staticID), disponibilita(true), titolo(titolo), tipo(tipo) {
}

ArticoloLibreria::~ArticoloLibreria() {
}

int ArticoloLibreria::getArticoloID() {
	return this->articoloID;
}

string ArticoloLibreria::getDisponibilita() {
	return (this->disponibilita==true) ? "true" : "false";
}

string ArticoloLibreria::getTitolo() {
	return this->titolo;
}

TipoArticolo ArticoloLibreria::getTipo() {
	return this->tipo;
}

bool ArticoloLibreria::operator==(const ArticoloLibreria& rhs) const
{
    return this->articoloID == rhs.articoloID;
}
