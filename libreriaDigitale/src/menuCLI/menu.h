/*
 * menu.h
 *
 *      Author: Luca Parimbelli
 */

#ifndef MENUCLI_MENU_H_
#define MENUCLI_MENU_H_

class Menu {
private:
	static void visualizzaLibreria();
	static void visualizzaTuttiArticoli();
	static void visualizzaRiviste();
	static void visualizzaAudio();
	static void visualizzaLibri();
	static void visualizzaAudiolibri();
	static void noleggiaArticolo();
	static void restituisciArticolo();
	static void cercaArticolo();
	static void inserisciArticolo();
	static void inserisciLibro();
	static void inserisciAudio();
	static void inserisciRivista();
	static void inserisciAudiolibro();
	static void rimuoviArticolo();
	static void backToMenuScelta();

public:
	static void inizializzaMenu();
	static void startMenuScelta();
};

#endif /* MENUCLI_MENU_H_ */
