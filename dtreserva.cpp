#include "dtreserva.h"

bool DtReserva::operator<(const DtReserva& dtr)const{

	if(this->costo<dtr.costo){
	
		return true;
	}else{
	
		return false;
	}

}
