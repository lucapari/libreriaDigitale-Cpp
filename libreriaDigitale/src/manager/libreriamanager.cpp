/*
 * libreriamanager.cpp
 *
 *      Author: Luca Parimbelli
 */

#include "libreriamanager.h"
#include "libreriainitializer.h"
#include <iostream>

//costruttore chiamato una sola volta quando instance() viene chiamato per la prima volta
LibreriaManager::LibreriaManager() {
	LibreriaInitializer::inizializzaLibreria(vettArticoli);
}

LibreriaManager& LibreriaManager::instance() {
	// static = instanzia solo alla prima chiamata
	static LibreriaManager instance;
	return instance;
}

void LibreriaManager::printAllArticoli(){
	for(vector<ArticoloLibreria* >::iterator i = vettArticoli.begin(); i!=vettArticoli.end(); i++)
		cout<<(*(*i)).toString()<<endl;
}
