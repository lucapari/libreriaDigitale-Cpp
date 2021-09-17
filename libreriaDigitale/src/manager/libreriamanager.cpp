/*
 * libreriamanager.cpp
 *
 *      Author: Luca Parimbelli
 */

#include "libreriamanager.h"
#include "libreriainitializer.h"
#include <string>
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

//return iterator a end() se non trova l'elemento cercato
std::vector<ArticoloLibreria*>::iterator LibreriaManager::findArticolo(int articoloID) {
	vector<ArticoloLibreria*>::iterator cercato = vettArticoli.end();
	for (vector<ArticoloLibreria*>::iterator i = vettArticoli.begin(); i != vettArticoli.end(); i++)
		if ((*i)->getArticoloID() == articoloID)
			cercato = i;
	return cercato;
}

std::vector<ArticoloLibreria*>::iterator LibreriaManager::findArticolo(string nomeArticolo) {
	vector<ArticoloLibreria*>::iterator cercato = vettArticoli.end();
	for (vector<ArticoloLibreria*>::iterator i = vettArticoli.begin();
			i != vettArticoli.end(); i++)
		if ((*i)->getTitolo() == nomeArticolo)
			cercato = i;
	return cercato;
}

void LibreriaManager::printAllArticoli() {
	for (vector<ArticoloLibreria*>::iterator i = vettArticoli.begin(); i != vettArticoli.end(); i++)
		cout << (*i)->toString() << endl;
}

void LibreriaManager::aggiungiArticolo(ArticoloLibreria *articolo) {
	vettArticoli.push_back(articolo);
}

void LibreriaManager::rimuoviArticolo(int articoloID) {
	vector<ArticoloLibreria*>::iterator cercato = findArticolo(articoloID);
	if (cercato != vettArticoli.end()) {
		delete(*cercato);	//evito memory leak
		vettArticoli.erase(cercato);
	} else {
		cout << "** Errore! Articolo non trovato. ** " << endl;
	}
}


void LibreriaManager::prestaArticolo(int articoloID) {
	vector<ArticoloLibreria*>::iterator cercato = findArticolo(articoloID);
	if (cercato != vettArticoli.end()) {
		if ((*cercato)->getDisponibilita())
			(*cercato)->setDisponibilita(false);
		else
			cout<< "** Impossibile prestare articolo. L'articolo non è disponibile. **" <<endl;
	} else {
		cout << "** Errore! Articolo non trovato. ** " << endl;
	}
}

void LibreriaManager::restituisciArticolo(int articoloID){
	vector<ArticoloLibreria*>::iterator cercato = findArticolo(articoloID);
		if (cercato != vettArticoli.end()) {
			if (!(*cercato)->getDisponibilita())
				(*cercato)->setDisponibilita(true);
			else
				cout<< "** Impossibile restituire articolo. L'articolo è già stato restituito. **" <<endl;
		} else {
			cout << "** Errore! Articolo non trovato. ** " << endl;
		}
}

void LibreriaManager::printArticolo(int articoloID) {
	vector<ArticoloLibreria*>::iterator cercato = findArticolo(articoloID);
	if (cercato != vettArticoli.end()) {
		cout << (*cercato)->toString() << endl;
	} else {
		cout << "** Errore! Articolo non trovato. ** " << endl;
	}
}

void LibreriaManager::printArticolo(string nomeArticolo) {
	vector<ArticoloLibreria*>::iterator cercato = findArticolo(nomeArticolo);
	if (cercato != vettArticoli.end()) {
		cout << (*cercato)->toString() << endl;
	} else {
		cout << "** Errore! Articolo non trovato. ** " << endl;
	}
}
