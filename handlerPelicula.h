#ifndef HANDLERPELICULA_H
#define HANDLERPELICULA_H

#include <map>
#include <list>
#include "pelicula.h"
#include <string>

using namespace std;

class HandlerPelicula{
	private:
		map<string,Pelicula*>peliculas;
		
		static HandlerPelicula* instancia;
		HandlerPelicula();
		~HandlerPelicula();
	public:

		static HandlerPelicula* getInstancia();

		list<Pelicula*> getPeliculas();
		Pelicula* getPelicula(string);
		void removerPelicula(Pelicula*);
		void agregarPelicula(Pelicula*);
		bool existePelicula(string);
};
#endif
