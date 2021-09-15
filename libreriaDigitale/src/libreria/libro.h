/*
 * libro.h
 *
 *      Author: Luca Parimbelli
 */

#ifndef LIBRERIA_LIBRO_H_
#define LIBRERIA_LIBRO_H_

#include "articololibreria.h"
#include "datetimepub.h"
#include <string>
using namespace std;

//eredito virtual per evitare "member duplication" in "AudioLibro"
class Libro: virtual public ArticoloLibreria, private DateTimePub {

private:
	string autore;
	string casaEditrice;
	int numPagine;

public:
	Libro(string titolo, string data, string autore, string casaEditrice,
			int numPagine);
	Libro(string titolo, string data, string autore);

	virtual ~Libro();

	string getAutore();
	int getNumPagine();
	string getCasaEditrice();

	//rendo nuovamente pubblic getDatePub() di DateTimePub
	using DateTimePub::getDatePub;

	//implementazione metodo astratto superclasse
	string toString();

};

#endif /* LIBRERIA_LIBRO_H_ */
