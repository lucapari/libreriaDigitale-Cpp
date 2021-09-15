/*
 * datetimepub.cpp
 *
 *      Author: Luca Parimbelli
 */

#include "datetimepub.h"

//initilializer-list
DateTimePub::DateTimePub(string data, int time) {
	checkInsertData(data);
	checkInsertTime(time);
}

DateTimePub::DateTimePub(string data) :
		DateTimePub(data, 0) {
}

DateTimePub::DateTimePub(int time) :
		DateTimePub("", time) {
}

DateTimePub::~DateTimePub() {
}

//controlla che il formato della data sia DD|MM|YYYY
//se qualcosa è sbagliato inserisce "99|99|9999"
void DateTimePub::checkInsertData(string data) {

	if (data.length() != 10 || data[2] != '|' || data[5] != '|')
		DateTimePub::data = "99|99|9999";

	int dd = stoi(data.substr(0, 2));
	int mm = stoi(data.substr(3, 5));
	int yy = stoi(data.substr(6, 11));

	if (mm < 1 || mm > 12)
		mm = 99;
	if (dd < 1 || dd > 31)
		dd = 99;
	switch (mm) {
	//mesi da 30dd: aprile (4), giugno (6), settembre (9), novembre (11)
	case 11:
	case 9:
	case 6:
	case 4:
		if (dd > 30)
			dd = 99;
		break;
		//mesi da 28dd: febbraio (2), non controllo bisestile
	case 2:
		if (dd > 28)
			dd = 99;
		break;
	}

	if (dd == 99 || mm == 99 || yy == 99)
		DateTimePub::data = "99|99|9999";
	else
		DateTimePub::data = data;
}

//funzione tail recursive: restituisce il numero di cifre di cui è composto num
//usata solo in questo .cpp, uso "static" per limitare la sua visibilità a questo modulo
static int countDigitTail(int num, int sum) {
	if (num / 10 == 0)
		return sum + 1;
	return countDigitTail(num / 10, sum + 1);
}

//controlla che time abbia meno di 6 cifre
void DateTimePub::checkInsertTime(int time) {
	if (countDigitTail(time, 0) > 6)
		DateTimePub::time = 999999;
	else
		DateTimePub::time = time;
}

string DateTimePub::getDatePub() {
	return data;
}

//ritorna la durata nel formato HH:MM:SS
string DateTimePub::getDurata() {

	const int numDigit = countDigitTail(time, 0);
	string res;
	int mm, ss;

	//gli zeri a sinistra non contano
	switch (numDigit) {
	case 0:
		res = "00:00:00";
		break;
	case 1:
		res = "00:00:0" + to_string(time);
		break;
	case 2:
		res = "00:00:" + to_string(time);
		break;
	case 3:
		ss = time % 100;
		time = time / 100;
		res = "00:0" + to_string(time) + ":" + to_string(ss);
		break;
	case 4:
		ss = time % 100;
		time = time / 100;
		res = "00:" + to_string(time) + ":" + to_string(ss);
		break;
	case 5:
		ss = time % 100;
		time = time / 100;
		mm = time % 100;
		time = time / 100;
		res = "0" + to_string(time) + ":" + to_string(mm) + ":" + to_string(ss);
		break;
	case 6:
		ss = time % 100;
		time = time / 100;
		mm = time % 100;
		time = time / 100;
		res = to_string(time) + ":" + to_string(mm) + ":" + to_string(ss);
		break;
	}
	return res;

}
