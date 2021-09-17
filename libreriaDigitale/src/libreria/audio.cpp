/*
 * audio.cpp
 *
 *      Author: Luca Parimbelli
 */

#include "audio.h"
#include "tipoarticoloprinter.h"

Audio::Audio(string titolo, int time, string autore, string casaDiscografica) :
		ArticoloLibreria(titolo, TipoArticolo::tipoAudio), DateTimePub(time) {
	Audio::autore = autore;
	Audio::casaDiscografica = casaDiscografica;
}

Audio::Audio(string titolo, int time, string autore) :
		Audio(titolo, time, autore, "null") {
}

Audio::~Audio() {
}

string Audio::getAutore() {
	return autore;
}
string Audio::getCasaDiscografica() {
	return casaDiscografica;
}

//implementazione metodo astratto superclasse
string Audio::toString() {
	string sTipo = TipoArticoloPrinter::toString(getTipo()) + " (ID_" + to_string(getArticoloID()) + ") :";
	string sTitolo = "Titolo = " + getTitolo();
	string sDurata = "Durata = " + getDurata();
	string sAutore = "Autore = " + getAutore();
	string sCasaDiscografica = "Casa discografica = " + getCasaDiscografica();
	string sDisponibilita = "Disponibile = " + getStrDisponibilita();
	string sRes = sTipo + "\n" + sTitolo + "\n" + sDurata + "\n" + sAutore
			+ "\n" + sCasaDiscografica + "\n" + sDisponibilita + "\n";

	return sRes;
}
