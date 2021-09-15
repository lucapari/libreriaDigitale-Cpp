/*
 * audio.h
 *
 *      Author: Luca Parimbelli
 */
#ifndef LIBRERIA_AUDIO_H_
#define LIBRERIA_AUDIO_H_

#include "articololibreria.h"
#include "datetimepub.h"
#include <string>

class Audio: virtual public ArticoloLibreria, private DateTimePub {

private:
	string autore;
	string casaDiscografica;

public:
	Audio(string titolo, int time, string autore, string casaDiscografica);
	Audio(string titolo, int time, string autore);

	virtual ~Audio();

	string getAutore();
	string getCasaDiscografica();
	//implementazione metodo astratto superclasse
	string toString();

	//rendo nuovamente pubblic getTime() di DateTimePub
	using DateTimePub::getDurata;

};

#endif /* LIBRERIA_AUDIO_H_ */
