#include "reserva.h"

Reserva::Reserva(int cantE,float pt){

	cantEntradas=cantE;
	costo=pt;
}
int Reserva::getCantEntradas(){

	return cantEntradas;
}
float Reserva::getCosto(){

	return costo;
}
void Reserva::setFuncion(Funcion* f){

	funcion=f;
}
void Reserva::setUsuario(Usuario* u){

	usuario=u;
}
Reserva::~Reserva(){}

