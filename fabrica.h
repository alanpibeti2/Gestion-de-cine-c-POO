#ifndef FABRICA_H
#define FABRICA_H


#include "iControlador_sesionUsuario.h"
#include "iControlador_pelicula.h"
#include "iControlador_extras.h"
#include "iControlador_altaFuncionyCine.h"
#include "iControlador_crearReserva.h"


using namespace std;

class Fabrica{
	private:
		static Fabrica* instancia;
		Fabrica();
		
	public:
		
		static Fabrica* getInstancia();
		IControlador_crearReserva* getIControlador_crearReserva();
		IControlador_pelicula* getIControlador_pelicula();
		IControlador_altaFuncionYCine* getIControlador_altaFuncionYCine();
		IControlador_extras* getIControlador_extras();
		IControlador_sesionUsuario* getIControlador_sesionUsuario();		
		~Fabrica();	
		
};
#endif
