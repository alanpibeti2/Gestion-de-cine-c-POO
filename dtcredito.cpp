#include "dtcredito.h"

DtCredito::DtCredito(int cant,float cost,string finan,float pd){

	cantEntradas=cant;
	costo=cost;
	financiera=finan;
	porcentajeDescuento;
}
string DtCredito::tipoReserva()const{

	return "credito";
}
float DtCredito::getCosto()const{

	return costo;
}
int DtCredito::getCantEntradas()const{

	return cantEntradas;
}
string DtCredito::getFinanciera()const{

	return financiera;
}
float DtCredito::getPorcentajeDescuento()const{

	return porcentajeDescuento;
}
