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

	std::vector<ArticoloLibreria*>::iterator findArticolo(int articoloID);
	std::vector<ArticoloLibreria*>::iterator findArticolo(string nomeArticolo);

	//template devono essere implementati nel .h
	template<typename T> vector<T*> getVettSottocategoria(TipoArticolo sottocategoria) {
		vector<T*> vettSottoCat;
		for (vector<ArticoloLibreria*>::iterator i = vettArticoli.begin(); i != vettArticoli.end(); i++)
			if ((*i)->getTipo() == sottocategoria) {
				T* temp = dynamic_cast<T*>(*i);
				vettSottoCat.push_back(temp);
			}
		return vettSottoCat;
	}

public:
	//singleton: instance() ritorna l'unica istanza della classe
	static LibreriaManager& instance();

	void aggiungiArticolo(ArticoloLibreria *articolo);
	void rimuoviArticolo(int articoloID);

	void noleggiaArticolo(int articoloID);
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
