/*
 * libreriainitializer.h
 *
 *      Author: Luca Parimbelli
 */

#ifndef MANAGER_LIBRERIAINITIALIZER_H_
#define MANAGER_LIBRERIAINITIALIZER_H_

#include<vector>
#include "../libreria/articololibreria.h"
#include "libreriamanager.h"

class LibreriaInitializer {
private:
	static void inizializzaLibreria(vector<ArticoloLibreria*> &vettArticoli);
	friend class LibreriaManager;
};

#endif /* MANAGER_LIBRERIAINITIALIZER_H_ */
