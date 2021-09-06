/*
 * ArticoloLibreria.h
 *
 *      Author: Luca Parimbelli
 */

#include<string>
using namespace std;

class ArticoloLibreria {
private:
	//staticID = campo statico per incrementare automaticamente articoloID
	static int staticID;
	int articoloID;

public:
	ArticoloLibreria();
	virtual ~ArticoloLibreria();

	//metodi pure virtual da implementare nelle sottoclassi
	virtual void toString()=0;
	virtual string getType()=0;
};

