#ifndef CONTROLADOR_SESIONUSUARIO_H
#define CONTROLADOR_SESIONUSUARIO_H

#include "handlerUsuario.h"
#include <string>
#include "usuario.h"
#include "fechaSistema.h"
#include "iControlador_sesionUsuario.h"

using namespace std;

class Controlador_sesionUsuario : public IControlador_sesionUsuario{
	private:
		string nickname;
		HandlerUsuario* hu;
		FechaSistema* fs;
		
		static Controlador_sesionUsuario* instancia;
		Controlador_sesionUsuario();
		~Controlador_sesionUsuario();
	public:
	
		static Controlador_sesionUsuario* getInstancia();
		
		void ingresarNickname(string);
		void setNickname(string);
		bool ingresarContrasenia(string);
		void borrarNickname();
		void salir();
		void finalizarSesion();
		bool crearUsuario(string,string,string);
		//casos extra de fechaSistema
		void modificarFechaS(Fecha,string);
		DtFechaSistema consultarFechaS();
		//operaciones para corroborar que esten las sesiones iniciadas
		bool adminIniciado();
		bool usuarioIniciado();


};
#endif
