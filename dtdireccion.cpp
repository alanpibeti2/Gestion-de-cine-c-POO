#include "dtdireccion.h"

Direccion::Direccion(string call,int num){

	calle=call;
	numero=num;
}
Direccion::Direccion(){}
Direccion::~Direccion(){}
string Direccion::getCalle()const{

	return calle;
}
int Direccion::getNumero()const{

	return numero;
}
