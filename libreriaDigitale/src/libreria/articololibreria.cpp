/*
 * ArticoloLibreria.h
 *
 *      Author: Luca Parimbelli
 */

#ifndef LIBRARY_ARTICOLOLIBRERIA_CPP_
#define LIBRARY_ARTICOLOLIBRERIA_CPP_

#include "articololibreria.h"

#include<string>
using namespace std;

int ArticoloLibreria::staticID = 0;

ArticoloLibreria::ArticoloLibreria() {
	articoloID = ++staticID;
}

ArticoloLibreria::~ArticoloLibreria() {
}

#endif /* LIBRARY_ARTICOLOLIBRERIA_CPP_ */
