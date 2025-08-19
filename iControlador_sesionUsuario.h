#ifndef ICONTROLADOR_SESIONUSUARIO_H
#define ICONTROLADOR_SESIONUSUARIO_H

//#include "handlerUsuario.h"
#include <string>
#include "usuario.h"

class Controlador_sesionUsuario;

using namespace std;

class IControlador_sesionUsuario{

	public:
	//	virtual static Controlador_sesionUsuario* getInstancia()=0;
		
		virtual void ingresarNickname(string)=0;
		virtual void setNickname(string)=0;
		virtual bool ingresarContrasenia(string)=0;
		virtual void borrarNickname()=0;
		virtual void salir()=0;
		virtual void finalizarSesion()=0;
		virtual bool crearUsuario(string,string,string)=0;
		virtual void modificarFechaS(Fecha,string)=0;
		virtual DtFechaSistema consultarFechaS()=0;
		virtual bool adminIniciado()=0;
		virtual bool usuarioIniciado()=0;


};
#endif
