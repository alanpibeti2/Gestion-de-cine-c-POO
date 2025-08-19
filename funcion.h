#ifndef FUNCION_H
#define FUNCION_H

#include "pelicula.h"
#include "reserva.h"
#include "dtfecha.h"
#include "dthorario.h"
#include "dtfuncion.h"
#include "dtreserva.h"
#include "fechaSistema.h"
#include "sala.h"

class Pelicula;
class Reserva;
class Sala;

class Funcion{
	private:
		int id;
		Fecha fecha;
		Horario horario;
		FechaSistema* fs;
		
		Pelicula* pelicula;
		Sala* sala;
		set<Reserva*>reservas;
	public:
		Funcion(int,Fecha,Horario);
		
		int getId();
		Fecha getFecha();
		Horario getHorario();
		void setPelicula(Pelicula* p);
		void setSala(Sala*);
		DtFuncion getDatosConPelicula(string);
		void accedoFuncionParaReserva(Reserva*);
		DtFuncion accedoFuncionConReserva();
		~Funcion();
		void removerseDeSala();

};
#endif
