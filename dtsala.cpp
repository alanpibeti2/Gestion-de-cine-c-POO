#include "dtsala.h"

DtSala::DtSala(int unaid,int cap,list<DtFuncion> ldtf){
	id=unaid;
	capacidad=cap;
	dtfunciones=ldtf;
}
DtSala::~DtSala(){}
bool DtSala::operator<(const DtSala& dts) const{

	return this->id < dts.id;
}
int DtSala::getId()const{

	return id;
}
int DtSala::getCapacidad()const{

	return capacidad;
}
list<DtFuncion> DtSala::getDtFunciones()const{

	return dtfunciones;
}
