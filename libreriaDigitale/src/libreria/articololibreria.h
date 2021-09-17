/*
 * ArticoloLibreria.h
 *
 *      Author: Luca Parimbelli
 */

#ifndef LIBRERIA_ARTICOLOLIBRERIA_H_
#define LIBRERIA_ARTICOLOLIBRERIA_H_

#include<string>
#include "tipoarticolo.h"
using namespace std;

//classe astratta
class ArticoloLibreria {
private:
	//staticID = campo statico per incrementare automaticamente articoloID
	static int staticID;

	int articoloID;
	bool disponibilita;
	string titolo;
	TipoArticolo tipo;

public:
	ArticoloLibreria(string titolo, TipoArticolo tipo);
	virtual ~ArticoloLibreria();

	int getArticoloID();
	bool getDisponibilita();
	string getStrDisponibilita();
	void setDisponibilita(bool disponibilita);
	string getTitolo();
	TipoArticolo getTipo();

	//metodo toString pure virtual da implementare nelle sottoclassi
	virtual string toString()=0;

//	//overload operator==
//	bool operator==(const ArticoloLibreria& rhs) const;

};

#endif /* LIBRERIA_ARTICOLOLIBRERIA_H_ */
