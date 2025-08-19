#ifndef RESERVA_H
#define RESERVA_H

#include "funcion.h"
#include "usuario.h"
#include "dtreserva.h"

class Funcion;
class Usuario;

class Reserva{
	private:
		int cantEntradas;
		float costo;
		Funcion* funcion;
		
	public:
	
		Usuario* usuario;
	
		Reserva(int,float);
		int getCantEntradas();
		float getCosto();
		void setFuncion(Funcion*);
		void setUsuario(Usuario*);
		virtual DtReserva* getDatos()=0;
		virtual ~Reserva()=0;
		virtual void removerseDeUsuario()=0;



};
#endif
