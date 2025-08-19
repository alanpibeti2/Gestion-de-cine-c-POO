#include "financiera.h"

Financiera::Financiera(string nom,float desc){

	nombre=nom;
	descuento=desc;
}
string Financiera::getNombre(){

	return nombre;
}
float Financiera::getDescuento(){

	return descuento;
}
