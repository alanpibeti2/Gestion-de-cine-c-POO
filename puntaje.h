#ifndef PUNTAJE_H
#define PUNTAJE_H

#include "dtpuntaje.h"
#include "usuario.h"
#include "pelicula.h"
#include <string>

using namespace std;

class Pelicula;
class Usuario;

class Puntaje{
	private:
		int puntos;
		Usuario* usuario;
		Pelicula* pelicula;
	public:
	Puntaje(int, Usuario*, Pelicula*);
	bool esDelUsuario();
	int  getPuntos();
	DtPuntaje getDatos();



};
#endif
