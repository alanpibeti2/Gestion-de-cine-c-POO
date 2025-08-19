#include "puntaje.h"
#include "pelicula.h"
#include "usuario.h"

using namespace std;
Puntaje::Puntaje(int punt, Usuario* user, Pelicula* pel){
		puntos=punt;
		usuario=user;
		pelicula=pel;
}
bool Puntaje::esDelUsuario(){
	if(usuario->getIniciarSesion()==true)
	return true;
	else
	return false;
}
int  Puntaje::getPuntos(){
	return puntos;

}
DtPuntaje Puntaje::getDatos(){
string nickname= usuario->getNickname();
return DtPuntaje(puntos,nickname);

}