#include "dtfuncion.h"
#include "dthorario.h"
#include "dtfecha.h"

DtFuncion::DtFuncion(int unaid,int d,int m,int a,string hc,string hf){

	id=unaid;
	fecha=Fecha(d,m,a);
	horario=Horario(hc,hf);

}
bool DtFuncion::operator<(const DtFuncion& dtf)const{

	if(this->id<dtf.id){
	
		return true;
	}else{
	
		return false;
	}

}
DtFuncion::DtFuncion(int unaid,Fecha f,Horario h){

	id=unaid;
	fecha=f;
	horario=h;

}
DtFuncion::DtFuncion(int unaid,Fecha f,Horario h,set<DtReserva*> setdtr){

	id=unaid;
	fecha=f;
	horario=h;
	
	for(set<DtReserva*>::iterator it=setdtr.begin();it!=setdtr.end();it++){
	
		dtreservas.insert(*it);
	}

}
int DtFuncion::getId()const{

	return id;
}
Fecha DtFuncion::getFecha()const{

	return fecha;
}
Horario DtFuncion::getHorario()const{

	return horario;
}
set<DtReserva*> DtFuncion::getDtReservas()const{

	return dtreservas;
}
