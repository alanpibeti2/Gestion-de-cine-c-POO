#ifndef CONTROLADOR_ALTAFUNCIONYCINE_H
#define CONTROLADOR_ALTAFUNCIONYCINE_H

#include "iControlador_altaFuncionyCine.h"
#include <set>
#include <list>
#include <string>
#include "handlerPelicula.h"
#include "handlerCine.h"
#include "pelicula.h"
#include "cine.h"
#include "sala.h"
#include "dtpelicula.h"
#include "dtcine.h"
#include "dtsala.h"
#include "dtfuncion.h"
#include "funcion.h"
#include "dtdireccion.h"

using namespace std;

class Controlador_altaFuncionYCine : public IControlador_altaFuncionYCine{
	private:
		string titulo;
		int idCine;
		int idSala;
		Direccion direccion;
		set<int>capacidades;
		int idFuncion;
		int idCineAutoInc;
		
		HandlerPelicula* hp;
		HandlerCine* hc;
		
		static Controlador_altaFuncionYCine* instancia;
		Controlador_altaFuncionYCine();
		~Controlador_altaFuncionYCine();
		
	public:

		static Controlador_altaFuncionYCine* getInstancia();
		
		//operaciones de altafuncion
		set<DtPelicula> listarPeliculas();
		void seleccionarPelicula(string);
		set<DtCine> listarCines();
		set<DtSala> seleccionarCine(int);
		void seleccionarSala(int);
		void ingresarNuevaFuncion(Fecha,Horario);
		void salirAltaFuncion();
		void setTitulo(string);
		void setIdCine(int);
		void setIdSala(int);
		void borrarTitulo();
		void borrarIdCine();
		void borrarIdSala();
		//operaciones de altacine
		void agregarCine(string call,int num);
		void agregarSalas(set<int>);
		void confirmarCine();
		void setCapacidades(set<int>);
		void setDireccion(Direccion);
		void borrarDireccion();
		void borrarCapacidades();
		void salirAltaCine();
		
};

#endif
