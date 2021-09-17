/*
 * main.cpp
 *
 *      Author: Luca Parimbelli
 */

#include "menuCLI/menu.h"

int main(int argc, char **argv) {

	Menu::inizializzaMenu();
	Menu::startMenuScelta(); //metodo loop fino a inserimento numero 0

	return 0;
}
