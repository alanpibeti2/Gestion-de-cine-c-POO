#ifndef DTFUNCION_H
#define DTFUNCION_H

#include "dtfecha.h"
#include "dthorario.h"
#include "dtreserva.h"
#include <set>

class DtFuncion{
	private:
		int id;
		Fecha fecha;
		Horario horario;
		
		set<DtReserva*>dtreservas;
		
	public:
	
		DtFuncion(int,int,int,int,string,string);
		bool operator<(const DtFuncion& dtf) const;
		DtFuncion(int,Fecha,Horario);
		DtFuncion(int,Fecha,Horario,set<DtReserva*>);
		int getId()const;
		Fecha getFecha()const;
		Horario getHorario()const;
		set<DtReserva*> getDtReservas() const;



};
#endif
