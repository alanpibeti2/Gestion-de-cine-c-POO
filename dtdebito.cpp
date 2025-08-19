#include "dtdebito.h"

DtDebito::DtDebito(int cant,float cost,string banc){

	cantEntradas=cant;
	costo=cost;
	banco=banc;

}
string DtDebito::tipoReserva()const{

	return "debito";
}
float DtDebito::getCosto()const{

	return costo;
}
int DtDebito::getCantEntradas()const{

	return cantEntradas;
}
string DtDebito::getBanco()const{

	return banco;
}
