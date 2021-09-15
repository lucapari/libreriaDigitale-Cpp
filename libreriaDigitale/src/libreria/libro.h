/*
 * libro.h
 *
 *      Author: Luca Parimbelli
 */

#include "articololibreria.h"
#include <string>

class Libro: virtual public ArticoloLibreria {
private:
	string autore;
	int numPagine;
	int annoPubblicazione;
public:
	Libro(string autore);
	Libro(string autore, int numPagine, int annoPubblicazione);
	string getAutore();
	int getNumPagine();
	int getAnnoPubblicazione();
};
