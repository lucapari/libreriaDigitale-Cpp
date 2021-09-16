/*
 * libreriamanager.cpp
 *
 *      Author: Luca Parimbelli
 */

#include "libreriamanager.h"
#include "libreriainitializer.h"

LibreriaManager::LibreriaManager(){}

LibreriaManager& LibreriaManager::instance() {
	// static = instanzia solo alla prima chiamata
	static LibreriaManager instance;
	static LibreriaInitializer::inizializzaLibreria(vettArticoli);
	return instance;
}

