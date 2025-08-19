#include "fechaSistema.h"

FechaSistema* FechaSistema::instancia=NULL;
FechaSistema::FechaSistema(){

	fechaActual=Fecha(1,1,2025);
	horarioActual="00:00";
}

FechaSistema* FechaSistema::getInstancia(){

	if(instancia==NULL){
	
		instancia= new FechaSistema();
	}
	return instancia;

}
bool FechaSistema::fechaEsPosterior(Fecha f,Horario h){

	if(f.getAnio()<fechaActual.getAnio()){
	
		return false;
	}else if(f.getAnio()>fechaActual.getAnio()){
	
		return true;
	}else{
	
		if(f.getMes()<fechaActual.getMes()){
		
			return false;
		}else if(f.getMes()>fechaActual.getMes()){	
	
			return true;	
		}else{
		
			if(f.getDia()<fechaActual.getDia()){
			
				return false;
			}else if(f.getDia()>fechaActual.getDia()){
			
				return true;
			}else{
			
				if(h.getHoraComienzo()>horarioActual){
				
					return true;
				}else{
				
					return false;
				}
			}
		}
	}
}
void FechaSistema::modificarFechaSistema(Fecha f,string h){

	fechaActual=f;
	horarioActual=h;
}
DtFechaSistema FechaSistema::getDatos(){

	DtFechaSistema dtfs=DtFechaSistema(fechaActual,horarioActual);
	
	return dtfs;	


}
