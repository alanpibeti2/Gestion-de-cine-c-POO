#include "debito.h"

Debito::Debito(int cantE,float pt,string banc):Reserva(cantE,pt){

	banco=banc;
}
DtReserva* Debito::getDatos(){

	return new DtDebito(getCantEntradas(),getCosto(),banco);
}
Debito::~Debito(){}
void Debito::removerseDeUsuario(){

	usuario->removerReserva(this);
}
