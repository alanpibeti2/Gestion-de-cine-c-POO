#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <set>
#include "comentario.h"
#include "puntaje.h"

class Reserva;
class Comentario;
class Puntaje;
class Credito;
class Debito;

using namespace std;

class Usuario{
	private:
		string nickname;
		string contrasenia;
		string urlFoto;
		bool iniciarSesion;
		
		set<Reserva*>reservas;
		set<Comentario*>comentarios;
		set<Puntaje*>puntajes;
	public:
		Usuario(string,string,string);
		bool contraseniaCorrecta(string);
		void setIniciarSesion(bool);
		string getNickname();
		bool getIniciarSesion();
		Reserva* accederUsuario(float,int,string,string,float,string);
		void removerReserva(Reserva*);

};
#endif
