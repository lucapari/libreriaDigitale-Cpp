/*
 * tipoarticoloprinter.cpp
 *
 *      Author: Luca Parimbelli
 */

#include "tipoarticoloprinter.h"

string TipoArticoloPrinter::toString(TipoArticolo tipo) {
	string res;
	switch (tipo) {
	case tipoAudio:
		res = "AUDIO";
		break;
	case tipoLibro:
		res = "LIBRO";
		break;
	case tipoRivista:
		res = "RIVISTA";
		break;
	case tipoAudiolibro:
		res = "AUDIOLIBRO";
		break;
	}
	return res;
}
