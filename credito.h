#ifndef CREDITO_H
#define CREDITO_H

#include <string>
#include "reserva.h"
#include "dtcredito.h"

using namespace std;

class Credito : public Reserva{
	private:
		string financiera;
		float porcentajeDescuento;
	public:
		
		Credito(int,float,string,float);
		DtReserva* getDatos();
		~Credito();
		void removerseDeUsuario();


};
#endif
