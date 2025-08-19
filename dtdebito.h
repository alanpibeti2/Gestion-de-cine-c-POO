#ifndef DTDEBITO_H
#define DTDEBITO_H

#include <string>
#include "dtreserva.h"

using namespace std;

class DtDebito : public DtReserva{
	private:
		
		int cantEntradas;
		string banco;
	public:
		
		DtDebito(int,float,string);
		string tipoReserva()const;
		float getCosto()const;
		int getCantEntradas()const;
		string getBanco()const;



};
#endif
