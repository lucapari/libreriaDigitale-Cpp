/*
 * libreriamanager.h
 *
 *      Author: Luca Parimbelli
 */

#ifndef MANAGER_LIBRERIAMANAGER_H_
#define MANAGER_LIBRERIAMANAGER_H_

#include <vector>
#include "../libreria/articololibreria.h"

//classe singleton
class LibreriaManager {
private:
	vector<ArticoloLibreria*> vettArticoli;

	LibreriaManager();

	LibreriaManager(LibreriaManager const&) = delete;
	void operator=(LibreriaManager const&) = delete;

	/*
	 *** Nota copy constructor e assignment operator per singleton.
	 *
	 * Copy constructor / Assignment operator: per il singleton non devo poterli utilizzare.
	 * = delete, i metodi non vengono generati automaticamente.
	 * Permette di evitare le seguenti situazioni:
	 * 1) Copy constructor
	 * 		LibreriaManager x = LibreriaManager::instance()
	 *
	 *2) Assignment operator
	 *		LibreriaManager x
	 *		LibreriaManager x=LibreriaManager::instance()
	 *
	 * */

public:
	//ritorna l'unica istanza della classe (singleton)
	static LibreriaManager& instance();

};

#endif /* MANAGER_LIBRERIAMANAGER_H_ */
