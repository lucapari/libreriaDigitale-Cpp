/*
 * ArticoloLibreria.h
 *
 *      Author: Luca Parimbelli
 */

#include<string>
#include "tipoarticolo.h"
#include <stdbool.h>
using namespace std;

virtual class ArticoloLibreria {
private:
	//staticID = campo statico per incrementare automaticamente articoloID
	static int staticID;
	int articoloID;
	bool disponibilita;
	string titolo;
	TipoArticolo tipo;

public:
	ArticoloLibreria(int titolo, TipoArticolo tipo);
	virtual ~ArticoloLibreria();

	//metodo toString pure virtual da implementare nelle sottoclassi
	virtual string toString()=0;

	int getArticoloID();
	bool getDisponibilita();
	string getTitolo();
	TipoArticolo getTipo();
	string toString();

};

