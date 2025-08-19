#include "controlador_sesionUsuario.h"

#include <iostream>

Controlador_sesionUsuario* Controlador_sesionUsuario::instancia=NULL;
Controlador_sesionUsuario::Controlador_sesionUsuario(){

	hu=HandlerUsuario::getInstancia();
	fs=FechaSistema::getInstancia();
}
Controlador_sesionUsuario::~Controlador_sesionUsuario(){}

Controlador_sesionUsuario* Controlador_sesionUsuario::getInstancia(){

	if(instancia==NULL){
	
		instancia = new Controlador_sesionUsuario();
	}
	return instancia;
}

void Controlador_sesionUsuario::setNickname(string nombre){

	nickname=nombre;
}
void Controlador_sesionUsuario::ingresarNickname(string nombre){

	setNickname(nombre);
}

bool Controlador_sesionUsuario::ingresarContrasenia(string con){
	
	Usuario* u;
	
	if(hu->existeUsuario(nickname)){
	
	u=hu->getUsuario(nickname);
	
	}else{
	
		return false;
	}
	
	
	if(u->contraseniaCorrecta(con)){
		u->setIniciarSesion(true);
		return true;
	}else{
	
		return false;
	}
	
}
void Controlador_sesionUsuario::borrarNickname(){

	nickname="";

}		
void Controlador_sesionUsuario::salir(){

	borrarNickname();
}
void Controlador_sesionUsuario::finalizarSesion(){

	list<Usuario*> lu=hu->getUsuarios();
	
	for(list<Usuario*>::iterator it=lu.begin();it!=lu.end();it++){
	
		if((*it)->getIniciarSesion()){
			(*it)->setIniciarSesion(false);
		}
	
	}

}
bool Controlador_sesionUsuario::crearUsuario(string name,string con,string fp){

	if(hu->existeUsuario(name)){
	
		return false;
	}else{
	
		Usuario* u= new Usuario(name,con,fp);
		hu->agregarUsuario(u);
		
		return true;
	}

}
void Controlador_sesionUsuario::modificarFechaS(Fecha f,string h){

	fs->modificarFechaSistema(f,h);

}
DtFechaSistema Controlador_sesionUsuario::consultarFechaS(){


	return fs->getDatos();
}
bool Controlador_sesionUsuario::adminIniciado(){

	Usuario* u=hu->getUsuario("admin");
	
	return u->getIniciarSesion();
}
bool Controlador_sesionUsuario::usuarioIniciado(){

	bool inicioS=false;

	list<Usuario*> lu=hu->getUsuarios();
	
	for(list<Usuario*>::iterator it=lu.begin();it!=lu.end();it++){
	
		if((*it)->getIniciarSesion()){
			inicioS=true;
		}
	
	}
	
	return inicioS;

}


