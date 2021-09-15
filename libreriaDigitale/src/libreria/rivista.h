/*
 * rivista.h
 *
 *      Author: Luca Parimbelli
 */

#ifndef LIBRERIA_RIVISTA_H_
#define LIBRERIA_RIVISTA_H_

#include "articololibreria.h"
#include "datetimepub.h"
#include <string>
using namespace std;

class Rivista: public ArticoloLibreria, private DateTimePub {
private:
	string casaEditrice;

public:
	Rivista(string titolo, string data, string casaEditrice);
	~Rivista();

	string getCasaEditrice();

	//rendo nuovamente pubblic getDatePub() di DateTimePub
	using DateTimePub::getDatePub;

	//implementazione metodo astratto superclasse
	string toString();

};

#endif /* LIBRERIA_RIVISTA_H_ */
