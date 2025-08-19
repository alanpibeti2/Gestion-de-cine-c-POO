#include "handlerUsuario.h"

HandlerUsuario* HandlerUsuario::instancia=NULL;
HandlerUsuario::HandlerUsuario(){}
HandlerUsuario::~HandlerUsuario(){}

HandlerUsuario* HandlerUsuario::getInstancia(){

	if(instancia==NULL){
	
		instancia = new HandlerUsuario();
	}
	return instancia;
}

//list<Usuario*> getUsuarios();
list<Usuario*> HandlerUsuario::getUsuarios(){
    list<Usuario*> aux;
    for(map<string,Usuario*>::iterator it = this->usuarios.begin(); it != this->usuarios.end(); it++)
        aux.push_back(it->second);
    return aux;
}
//Usuario* getUsuario(string);
Usuario* HandlerUsuario::getUsuario(string name){
    map<string,Usuario*>::iterator it = this->usuarios.find(name);
    return it->second;

}
// void removerUsuario(Usuario*);
void HandlerUsuario::removerUsuario(Usuario* u){
    map<string,Usuario*>::iterator it = this->usuarios.find(u->getNickname());
    this->usuarios.erase(it);
}
//bool existeUsuario(string);
bool HandlerUsuario::existeUsuario(string name){
    map<string,Usuario*>::iterator it = this->usuarios.find(name);    
    return  (it != this->usuarios.end());
}//como funciona esta?

//void agregarUsuario(Usuario*);
void HandlerUsuario::agregarUsuario(Usuario* u){ 
    this->usuarios.insert(pair<string, Usuario*> (u->getNickname(),u));
}

