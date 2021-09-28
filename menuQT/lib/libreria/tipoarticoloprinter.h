/*
 * tipoarticoloprinter.h
 *
 *      Author: Luca Parimbelli
 */

#ifndef LIBRERIA_TIPOARTICOLOPRINTER_H_
#define LIBRERIA_TIPOARTICOLOPRINTER_H_

#include "tipoarticolo.h"
#include <string>
using namespace std;

class TipoArticoloPrinter {
public:
	static string toString(TipoArticolo tipo);
};

#endif /* LIBRERIA_TIPOARTICOLOPRINTER_H_ */
