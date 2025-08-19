#include "dtfecha.h"

Fecha::Fecha(int d,int m,int a){

	dia=d;
	mes=m;
	anio=a;

}
Fecha::Fecha(){}
int Fecha::getDia()const{

	return dia;
}
int Fecha::getMes()const{

	return mes;
}
int Fecha::getAnio()const{

	return anio;
}
