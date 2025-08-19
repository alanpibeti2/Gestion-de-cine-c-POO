#ifndef DTCREDITO_H
#define DTCREDITO_H

#include <string>
#include "dtreserva.h"

using namespace std;

class DtCredito : public DtReserva{
	private:
		int cantEntradas;
		string financiera;
		float porcentajeDescuento;
	public:
		
		DtCredito(int,float,string,float);
		string tipoReserva()const;
		float getCosto()const;
		int getCantEntradas()const;
		string getFinanciera()const;
		float getPorcentajeDescuento()const;


};
#endif
