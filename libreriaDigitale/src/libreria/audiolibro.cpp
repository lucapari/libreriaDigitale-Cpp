/*
 * audiolibro.cpp
 *
 *      Author: Luca Parimbelli
 */

#include "audiolibro.h"
#include "articololibreria.h"
#include "tipoarticoloprinter.h"

AudioLibro::AudioLibro(string titolo, string data, int time, string audioAut,
		string libroAut, string casaEditrice, string casaDiscografica) :
		ArticoloLibreria(titolo, TipoArticolo::tipoAudiolibro), Audio(titolo,
				time, audioAut, casaDiscografica), Libro(titolo, data, libroAut,
				casaEditrice, 0) {
}

AudioLibro::AudioLibro(string titolo, string data, int time, string audioAut,
		string libroAut) :
		AudioLibro(titolo, data, time, audioAut, libroAut, "null", "null") {
}

AudioLibro::~AudioLibro() {
}

//risolvo il name clash di "autore" con l'explicit resolution
string AudioLibro::getAutoreLibro() {
	return Libro::getAutore();
}
string AudioLibro::getNarratore() {
	return Audio::getAutore();
}

string AudioLibro::toString() {
	string sTipo = TipoArticoloPrinter::toString(getTipo()) + " (ID_" + to_string(getArticoloID()) + ") :";
	string sTitolo = "Titolo = " + getTitolo();
	string sAutoreLibro = "Autore Libro = " + getAutoreLibro();
	string sNarratore = "Narratore = " + getNarratore();
	string sDurata = "Durata = " + Audio::getDurata();
	string sCasaEditrice = "Casa Editrice = " + getCasaEditrice();
	string sCasaDiscografica = "Casa Discografica = " + getCasaDiscografica();
	string sData = "Data = " + Libro::getDatePub();
	string sDisponibilita = "Disponibile = " + getStrDisponibilita();
	string sRes = sTipo + "\n" + sTitolo + "\n" + sAutoreLibro + "\n"
			+ sNarratore + "\n" + sDurata + "\n" + sCasaEditrice + "\n"
			+ sCasaDiscografica + "\n" + sData + "\n" + sDisponibilita + "\n";

	return sRes;
}

