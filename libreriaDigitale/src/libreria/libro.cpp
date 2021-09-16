/*
 * libro.cpp
 *
 *      Author: Luca Parimbelli
 */

#include "libro.h"
#include "tipoarticoloprinter.h"

Libro::Libro(string titolo, string data, string autore, string casaEditrice,
		int numPagine) :
		ArticoloLibreria(titolo, TipoArticolo::tipoLibro), DateTimePub(data) {
	Libro::autore = autore;
	Libro::casaEditrice = casaEditrice;
	Libro::numPagine = numPagine;
}
Libro::Libro(string titolo, string data, string autore) :
		Libro(titolo, data, autore, "null", 0) {
}

Libro::~Libro() {
}

string Libro::getAutore() {
	return autore;
}
int Libro::getNumPagine() {
	return numPagine;
}
string Libro::getCasaEditrice() {
	return casaEditrice;
}

string Libro::toString() {
	string sTipo = TipoArticoloPrinter::toString(getTipo()) + " (ID_" + to_string(getArticoloID()) + ") :";
	string sTitolo = "Titolo = " + getTitolo();
	string sAutore = "Autore = " + getAutore();
	string sCasaEditrice = "Casa Editrice = " + getCasaEditrice();
	string sData = "Data = " + getDatePub();
	string sNumPagine = "Pagine = " + to_string(getNumPagine());
	string sDisponibilita = "Disponibile = " + getDisponibilita();
	string sRes = sTipo + "\n" + sTitolo + "\n" + sAutore + "\n" + sCasaEditrice
	+"\n" + sData + "\n" + sNumPagine + "\n" + sDisponibilita + "\n";

	return sRes;
}
