#ifndef CONTROLADOR_EXTRAS_H
#define CONTROLADOR_EXTRAS_H
#include <iostream>
#include "handlerPelicula.h"
#include "handlerCine.h"
#include "handlerUsuario.h"
#include "dtpelicula.h"
#include "dtcomentario.h"
#include "dtfuncion.h"
#include "dtcine.h"
#include "iControlador_extras.h"
#include <string>
#include <set>
#include <list>
using namespace std;

class Controlador_extras : public IControlador_extras{
	private:
		string titulo;
		int idCine;
		HandlerPelicula* hp;
		HandlerUsuario* hu;
		HandlerCine* hc;
		static Controlador_extras* instancia;	
		Controlador_extras();
		~Controlador_extras();
	public:
		 set<DtPelicula> listarPeliculas();
		 void seleccionarPelicula(string);
		 void setTitulo(string);
		 void setIdCine(int);
		 bool fuePuntuada();
		 int verPuntajePelicula();
		 void puntuarPelicula(int);
		 static Controlador_extras* getInstancia();
		 list<DtComentario> listarComentarios();
		 void publicarComentario(string);
		 void seleccionarComentarioParaResponder(int, string);
		 pair <list<DtComentario>, list <DtPuntaje>> verPuntajeYComentariosPelicula();
		 void salir();
		 void borrarTitulo();
		 void borrarCine();
		 set<DtCine> infoAdicional();
		 set<DtFuncion> listarFuncionesDeCineYPeliculas();
		
		 // verPuntajeYComentariosPelicula():
		 
/*		
		 void seleccionarCine(int);
		 set<DtCine> infoAdicional();
		 set<DtComentario> listarComentarios();
		 void setIdCine(int);
		 void borrarPelicula();	
		 DtPelicula verPuntajeYComentariosPelicula();
		 set<DtFuncion> listarFuncionesDeCineYPeliculas();
		 void seleccionarComentario(DtComentario,string);
		 void salir();
	*/


};
#endif
