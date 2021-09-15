/*
 * audiolibro.h
 *
 *      Author: Luca Parimbelli
 */

#ifndef LIBRERIA_AUDIOLIBRO_H_
#define LIBRERIA_AUDIOLIBRO_H_

#include "audio.h"
#include "libro.h"
#include <string>

class AudioLibro: public Audio, public Libro {

public:
	//Aut = autore
	AudioLibro(string titolo, string data, int time, string audioAut,
			string libroAut, string numPagine, string casaEditrice,
			string casaDiscografica);
	AudioLibro(string titolo, string data, int time, string audioAut,
			string libroAut);

	~AudioLibro();

	string getAutoreLibro();
	string getNarratore();

	//implementazione metodo astratto superclasse
	string toString();

};

#endif /* LIBRERIA_AUDIOLIBRO_H_ */
