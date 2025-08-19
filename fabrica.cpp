#include "fabrica.h"
#include "controlador_sesionUsuario.h"
#include "controlador_pelicula.h"
#include "controlador_extras.h"
#include "controlador_altaFuncionyCine.h"
#include "controlador_crearReserva.h"


Fabrica* Fabrica::instancia=NULL;
Fabrica::Fabrica(){}
Fabrica::~Fabrica(){}

Fabrica* Fabrica::getInstancia(){

	if(instancia==NULL){
	
		instancia = new Fabrica();
	}
	return instancia;
}
IControlador_sesionUsuario* Fabrica::getIControlador_sesionUsuario(){
	
	Controlador_sesionUsuario* controlador = Controlador_sesionUsuario::getInstancia();
	return controlador;
}
IControlador_pelicula* Fabrica::getIControlador_pelicula(){
	Controlador_pelicula* controlador = Controlador_pelicula::getInstancia();
	return controlador;
}
IControlador_extras* Fabrica::getIControlador_extras(){
	Controlador_extras* controlador = Controlador_extras::getInstancia();
	return controlador;
}
IControlador_altaFuncionYCine* Fabrica::getIControlador_altaFuncionYCine(){
	Controlador_altaFuncionYCine* controlador = Controlador_altaFuncionYCine::getInstancia();
	return controlador;
}
IControlador_crearReserva* Fabrica::getIControlador_crearReserva(){
	Controlador_crearReserva* controlador = Controlador_crearReserva::getInstancia();
	return controlador;
}
