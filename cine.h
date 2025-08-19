#ifndef CINE_H
#define CINE_H

#include <map>
#include <set>
#include <list>
#include "dtdireccion.h"
#include "pelicula.h"
#include "sala.h"
#include "dtfuncion.h"

class Pelicula;
class Sala;

class Cine{
	private:
		int id;
		Direccion direccion;
		int idSalaAutoInc;
		map<string,Pelicula*>peliculas;
		map<int,Sala*>salas;
		
	public:
		
		Cine(int,Direccion);
		int getId();
		Direccion getDireccion();
		list<Sala*> getSalas();
		Sala* getSala(int);
		void agregarSala(Sala*);
		int getIdSalaAutoInc();
		set<DtFuncion> accedoCineParaFuncion(string);
		void agregarPelicula(Pelicula*);
		void removerPelicula(string);
};
#endif
