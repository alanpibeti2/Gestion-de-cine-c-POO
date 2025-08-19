#ifndef FECHASISTEMA_H
#define FECHASISTEMA_H

#include "dtfecha.h"
#include "dthorario.h"
#include "dtfechasistema.h"

class Pelicula;
class Reserva;

class FechaSistema{
	private:
	
		Fecha fechaActual;
		string horarioActual;
		
		static FechaSistema* instancia;
		FechaSistema();
		
	public:
		
		static FechaSistema* getInstancia();
		
		bool fechaEsPosterior(Fecha,Horario);
		void modificarFechaSistema(Fecha,string);
		DtFechaSistema getDatos();
		
		


};
#endif
