#include "dthorario.h"

Horario::Horario(string hc,string hf){

	horaComienzo=hc;
	horaFin=hf;
}
Horario::Horario(){}
string Horario::getHoraComienzo()const{

	return horaComienzo;
}
string Horario::getHoraFin()const{

	return horaFin;
}
