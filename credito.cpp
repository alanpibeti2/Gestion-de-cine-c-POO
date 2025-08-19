#include "credito.h"

Credito::Credito(int cantE,float pt,string financ,float pd):Reserva(cantE,pt){

	financiera=financ;
	porcentajeDescuento=pd;
}
DtReserva* Credito::getDatos(){

	return new DtCredito(getCantEntradas(),getCosto(),financiera,porcentajeDescuento);
}
Credito::~Credito(){}
void Credito::removerseDeUsuario(){

	usuario->removerReserva(this);
}
