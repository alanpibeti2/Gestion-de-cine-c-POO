#include "cine.h"
#include <iostream>

int Cine::getId(){

	return id;
}
Direccion Cine::getDireccion(){

	return direccion;
}
list<Sala*> Cine::getSalas(){
    list<Sala*> aux;
    for(map<int,Sala*>::iterator it = this->salas.begin(); it != this->salas.end(); it++)
        aux.push_back(it->second);
    return aux;
}
Sala* Cine::getSala(int id){

	map<int,Sala*>::iterator it = this->salas.find(id);
    return it->second;

}
Cine::Cine(int unaid,Direccion dir){

	id=unaid;
	direccion=dir;
	idSalaAutoInc=0;
}
void Cine::agregarSala(Sala* s){ 
    this->salas.insert(pair<int,Sala*>(s->getId(),s));
}
int Cine::getIdSalaAutoInc(){
	idSalaAutoInc++;
	return idSalaAutoInc;
}
set<DtFuncion> Cine::accedoCineParaFuncion(string unTitulo){

	set<DtFuncion> setdf,setdsf;
	
	
	for(map<int,Sala*>::iterator it=this->salas.begin();it!=salas.end();it++){
	
			setdsf=it->second->accedoSalaParaFuncion(unTitulo);
			setdf.insert(setdsf.begin(),setdsf.end());
	}
	
	return setdf;
	
}
void Cine::agregarPelicula(Pelicula* p){ 
    this->peliculas.insert(pair<string,Pelicula*>(p->getTitulo(),p));
}
void Cine::removerPelicula(string tit){	
	
		//cout<<"entro al bucle en cine.cpp"<<endl;	
	  map<string,Pelicula*>::iterator it = this->peliculas.find(tit);
    	//cout<<"antes de remover la pelicula en cine.cpp"<<endl;
    	if(it != this->peliculas.end()){
    		this->peliculas.erase(it);
    	}
    	//cout<<"despues de remover la pelicula en cine.cpp"<<endl;
}
