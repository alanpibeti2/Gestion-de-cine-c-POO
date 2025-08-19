#include "usuario.h"
#include "reserva.h"
#include "debito.h"
#include "credito.h"

bool Usuario::contraseniaCorrecta(string con){

	if(con==contrasenia){
	
		return true;
	}else{
		return false;
	}

}
void Usuario::setIniciarSesion(bool x){		

	iniciarSesion=x;
}
string Usuario::getNickname(){

	return nickname;
}
bool Usuario::getIniciarSesion(){
	return iniciarSesion;
}
Usuario::Usuario(string unNickname,string unaContrasenia,string unaFoto){

	nickname=unNickname;
	contrasenia=unaContrasenia;
	urlFoto=unaFoto;
	iniciarSesion=false;
}
Reserva* Usuario::accederUsuario(float pt,int cantE,string banc,string financ,float desc,string tipo){

	if(tipo=="credito"){
	
		Credito* c= new Credito(cantE,pt,financ,desc);
		reservas.insert(c);
		
		return c;
	
	}else{
	
		Debito* d= new Debito(cantE,pt,banc);
		reservas.insert(d);
		
		return d;
	}


}
void Usuario::removerReserva(Reserva* r){

	this->reservas.erase(r);
}
