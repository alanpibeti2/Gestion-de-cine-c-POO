#include "funcion.h"
#include <iostream>
#include "debito.h"
#include "credito.h"

Funcion::Funcion(int unaid,Fecha f,Horario h){

	id=unaid;
	fecha=f;
	horario=h;
	fs=FechaSistema::getInstancia();
}
int Funcion::getId(){

	return id;
}
Fecha Funcion::getFecha(){

	return fecha;
}
Horario Funcion::getHorario(){

	return horario;
}
void Funcion::setPelicula(Pelicula* p){

	pelicula=p;
}
void Funcion::setSala(Sala* s){

	sala=s;
}
DtFuncion Funcion::getDatosConPelicula(string unTitulo){

	DtFuncion dtf=DtFuncion(0,0,0,0,"0","0");
	
	if((fs->fechaEsPosterior(fecha,horario))&&(pelicula->esPelicula(unTitulo))){
	
		dtf=DtFuncion(id,fecha,horario);
	}
	
	return dtf;

}
void Funcion::accedoFuncionParaReserva(Reserva* r){

	reservas.insert(r);
}
DtFuncion Funcion::accedoFuncionConReserva(){

	set<DtReserva*> setdtr;
	
	for(set<Reserva*>::iterator it=reservas.begin();it!=reservas.end();it++){
	
		setdtr.insert((*it)->getDatos());
	}
	
	DtFuncion dtf=DtFuncion(id,fecha,horario,setdtr);
	
	return dtf;

}
Funcion::~Funcion(){

	for(set<Reserva*>::iterator it=reservas.begin();it!=reservas.end();it++){
			(*it)->removerseDeUsuario();
			delete (*it);
	}
}
void Funcion::removerseDeSala(){

	sala->removerFuncion(this);

}
