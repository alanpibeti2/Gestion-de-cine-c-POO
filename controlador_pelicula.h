#ifndef CONTROLADOR_PELICULA_H
#define CONTROLADOR_PELICULA_H

#include <string>
#include "handlerPelicula.h"
#include "handlerCine.h"
#include "iControlador_pelicula.h"
#include "dtfuncion.h"

using namespace std;

class Controlador_pelicula : public IControlador_pelicula{
	private:
		string titulo;
		int idCine;
		HandlerPelicula* hp;
		HandlerCine* hc;
		
		static Controlador_pelicula* instancia;
		Controlador_pelicula();
		~Controlador_pelicula();
	public:

		static Controlador_pelicula* getInstancia();
		
		void ingresarPelicula(string,string,string);
		bool existeLaPelicula(string);
		//caso de uso nuestro(enlazar pelicula con cine)
		set<DtPelicula> listarPeliculas();
		void seleccionarPelicula(string);
		void setTitulo(string);
		set<DtCine> listarCines();
		void seleccionarCine(int);
		void setIdCine(int);
		void confirmar();
		void salir();
		void borrarTitulo();
		void borrarIdCine();
		//fin del caso de uso
		set<DtFuncion> listarReservas(string);
		void confirmarBorrado(string);

};
#endif
