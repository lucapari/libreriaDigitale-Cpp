/*
 * datetimepub.h
 *
 *      Author: Luca Parimbelli
 */

#ifndef LIBRERIA_DATETIMEPUB_H_
#define LIBRERIA_DATETIMEPUB_H_

#include<string>
using namespace std;

class DateTimePub {
private:
	//data di pubblicazione (input in formato: DD/MM/YY)
	string data;
	//durata in min, sec, ore (input in formato: HHMMSS)
	//time inserito non deve inziare con 0 altrimenti il compilatore lo tratta in ottale
	int time;

	void checkInsertData(string data);
	void checkInsertTime(int time);

public:
	DateTimePub(string data, int time);
	DateTimePub(string data);
	DateTimePub(int time);
	virtual ~DateTimePub();

	string getDatePub();
	string getDurata();

};

#endif /* LIBRERIA_DATETIMEPUB_H_ */
