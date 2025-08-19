#include "sala.h"


Sala::Sala(int unaid,int cap){

	id=unaid;
	capacidad=cap;

}
int Sala::getId(){

	return id;
}
int Sala::getCapacidad(){

	return capacidad;
}
list<Funcion*> Sala::getFunciones(){

    list<Funcion*> aux;
    for(map<int,Funcion*>::iterator it = this->funciones.begin(); it != this->funciones.end(); it++)
        aux.push_back(it->second);
    return aux;
}
void Sala::agregarFuncion(Funcion* f){

    this->funciones.insert(pair<int,Funcion*>(f->getId(),f));
}
set<DtFuncion> Sala::accedoSalaParaFuncion(string unTitulo){

	set<DtFuncion> setdf;
	
	for(map<int,Funcion*>::iterator it=this->funciones.begin();it!=this->funciones.end();it++){
		
		DtFuncion dtf=it->second->getDatosConPelicula(unTitulo);
		
		if(dtf.getId()!=0){
			setdf.insert(dtf);
		}
	}
	
	return setdf;

}
void Sala::removerFuncion(Funcion* f){

	map<int,Funcion*>::iterator it= this->funciones.find(f->getId());
	if(it!=this->funciones.end()){
		this->funciones.erase(it);
	}

}








