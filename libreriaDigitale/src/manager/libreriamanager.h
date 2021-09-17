/*
 * libreriamanager.h
 *
 *      Author: Luca Parimbelli
 */

#ifndef MANAGER_LIBRERIAMANAGER_H_
#define MANAGER_LIBRERIAMANAGER_H_

#include <vector>
#include <iostream>
#include "../libreria/articololibreria.h"
using namespace std;

//singleton
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

	std::vector<ArticoloLibreria*>::iterator findArticolo(int articoloID);
	std::vector<ArticoloLibreria*>::iterator findArticolo(string nomeArticolo);

	//template devono essere implementati nel .h
	template<typename T> vector<T*> getVettSottocategoria(TipoArticolo sottocategoria) {
		vector<T*> vettSottoCat;
		for (vector<ArticoloLibreria*>::iterator i = vettArticoli.begin(); i != vettArticoli.end(); i++)
			if ((*i)->getTipo() == sottocategoria) {
				vettSottoCat.push_back((T*) *i);
			}
		return vettSottoCat;
	}
public:
	//singleton: instance() ritorna l'unica istanza della classe
	static LibreriaManager& instance();

	void aggiungiArticolo(ArticoloLibreria *articolo);
	void rimuoviArticolo(int articoloID);

	void prestaArticolo(int articoloID);
	void restituisciArticolo(int articoloID);

	void printArticolo(int articoloID);
	void printArticolo(string nomeArticolo);
	void printAllArticoli();

	template<typename T> void printSottocategoria(TipoArticolo sottocategoria) {
		vector<T*> vett = getVettSottocategoria<T>(sottocategoria);
		for (typename vector<T*>::iterator i = vett.begin(); i != vett.end(); i++)
			cout << (*i)->toString() << endl;
	}

};

#endif /* MANAGER_LIBRERIAMANAGER_H_ */
