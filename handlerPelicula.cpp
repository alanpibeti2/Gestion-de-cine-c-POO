#include "handlerPelicula.h"

HandlerPelicula* HandlerPelicula::instancia=NULL;
HandlerPelicula::HandlerPelicula(){}
HandlerPelicula::~HandlerPelicula(){}

HandlerPelicula* HandlerPelicula::getInstancia(){

	if(instancia==NULL){
	
		instancia = new HandlerPelicula();
	}
	return instancia;
}

//list<Pelicula*> getPeliculas();
list<Pelicula*> HandlerPelicula::getPeliculas(){
    list<Pelicula*> aux;
    for(map<string,Pelicula*>::iterator it = this->peliculas.begin(); it != this->peliculas.end(); it++)
        aux.push_back(it->second);
    return aux;
}
//Pelicula* getPelicula(string);
Pelicula* HandlerPelicula::getPelicula(string titulo){
    map<string,Pelicula*>::iterator it = this->peliculas.find(titulo);
    return it->second;

}
//void removerPelicula(Pelicula*);
void HandlerPelicula::removerPelicula(Pelicula* p){
    map<string,Pelicula*>::iterator it = this->peliculas.find(p->getTitulo());
    this->peliculas.erase(it);
}
//bool existePelicula(string);
bool HandlerPelicula::existePelicula(string titulo){
    map<string,Pelicula*>::iterator it = this->peliculas.find(titulo);    
    return  (it != this->peliculas.end());
}//como funciona esta?

//void agregarPelicula(Pelicula*);
void HandlerPelicula::agregarPelicula(Pelicula* p){ 
    this->peliculas.insert(pair<string,Pelicula*>(p->getTitulo(),p));
}
  
        
