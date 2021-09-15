/*
 * audio.cpp
 *
 *      Author: Luca Parimbelli
 */

#include "audio.h"

Audio::Audio(string titolo, int time, string autore, string casaDiscografica) :
		ArticoloLibreria(titolo, TipoArticolo::Audio), DateTimePub(time) {
	Audio::autore = autore;
	Audio::casaDiscografica = casaDiscografica;
}
Audio::Audio(string titolo, int time, string autore) :
		Audio(titolo, time, autore, "") {
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
	return ArticoloLibreria::getTipo() + ":\nTitolo = "
			+ ArticoloLibreria::getTitolo() + "\nDurata = "
			+ DateTimePub::getDurata() + "\nAutore = " + autore
			+ "\ncasaDiscografica = " + casaDiscografica;
}
