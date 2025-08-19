#ifndef DEBITO_H
#define DEBITO_H

#include <string>
#include "reserva.h"
#include "dtdebito.h"

using namespace std;

class Debito : public Reserva{
	private:
		string banco;
	public:
		
		Debito(int,float,string);
		DtReserva* getDatos();
		~Debito();
		void removerseDeUsuario();


};
#endif
