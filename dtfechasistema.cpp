#include "dtfechasistema.h"

DtFechaSistema::DtFechaSistema(Fecha f,string h){

	fechaActual=f;
	horarioActual=h;
}
Fecha DtFechaSistema::getFechaActual(){

	return fechaActual;
}
string DtFechaSistema::getHorarioActual(){

	return horarioActual;
}
