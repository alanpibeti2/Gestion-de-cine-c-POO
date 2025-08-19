#include "dtcine.h"

DtCine::DtCine(int unaid,string call, int num):direccion(call,num){

	id=unaid;
}
DtCine::~DtCine(){}
bool DtCine::operator<(const DtCine& dtc) const{

	
	if(this->id<dtc.id){
	
		return true;
	}else{
	
		return false;
	}
}
int DtCine::getId()const{

	return id;
}
Direccion DtCine::getDireccion()const{

	return direccion;
}
