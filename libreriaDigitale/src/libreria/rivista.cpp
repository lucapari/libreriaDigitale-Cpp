/*
 * rivista.cpp
 *
 *      Author: Luca Parimbelli
 */

#include "rivista.h"
#include "tipoarticoloprinter.h"

Rivista::Rivista(string titolo, string data, string casaEditrice) :
		ArticoloLibreria(titolo, TipoArticolo::tipoRivista), DateTimePub(data) {
	Rivista::casaEditrice = casaEditrice;
}

Rivista::~Rivista() {
}

string Rivista::getCasaEditrice() {
	return casaEditrice;
}

string Rivista::toString() {
	string sTipo = TipoArticoloPrinter::toString(getTipo()) + " (ID_" + to_string(getArticoloID()) + ") :";
	string sTitolo = "Titolo = " + getTitolo();
	string sCasaEditrice = "Casa Editrice = " + getCasaEditrice();
	string sData = "Data = " + getDatePub();
	string sDisponibilita = "Disponibile = " + getDisponibilita();
	string sRes = sTipo + "\n" + sTitolo + "\n" + sData + "\n" + sCasaEditrice
			+ "\n" + sDisponibilita + "\n";

	return sRes;
}
