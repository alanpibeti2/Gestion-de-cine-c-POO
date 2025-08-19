#include "handlerCine.h"

HandlerCine* HandlerCine::instancia=NULL;
HandlerCine::HandlerCine(){}
HandlerCine::~HandlerCine(){}

HandlerCine* HandlerCine::getInstancia(){

	if(instancia==NULL){
	
		instancia = new HandlerCine();
	}
	return instancia;
}

//list<Cine*> getCines();
list<Cine*> HandlerCine::getCines(){
    list<Cine*> aux;
    for(map<int,Cine*>::iterator it = this->cines.begin(); it != this->cines.end(); it++)
        aux.push_back(it->second);
    return aux;
}
//Cine* getCine(int);
Cine* HandlerCine::getCine(int id){
    map<int,Cine*>::iterator it = this->cines.find(id);
    return it->second;

}
//void removerCine(Cine*);
void HandlerCine::removerCine(Cine* c){
    map<int,Cine*>::iterator it = this->cines.find(c->getId());
    this->cines.erase(it);
}
//bool existeCine(int);
bool HandlerCine::existeCine(int id){
    map<int,Cine*>::iterator it = this->cines.find(id);    
    return  (it != this->cines.end());
}//como funciona esta?

//void agregarCine(Cine*);
void HandlerCine::agregarCine(Cine* c){ 
    this->cines.insert(pair<int,Cine*>(c->getId(),c));
}
