#ifndef SALA_H
#define SALA_H

#include <map>
#include <set>
#include "funcion.h"
#include "dtfuncion.h"

class Funcion;

class Sala{
	private:
		int id;
		int capacidad;
		map<int,Funcion*>funciones;
	public:
	
		Sala(int,int);	
		int getId();
		int getCapacidad();
		list<Funcion*> getFunciones();
		void agregarFuncion(Funcion*);
		set<DtFuncion> accedoSalaParaFuncion(string);
		void removerFuncion(Funcion*);



};
#endif
