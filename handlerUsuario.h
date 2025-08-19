#ifndef HANDLERUSUARIO_H
#define HANDLERUSUARIO_H

#include <map>
#include <list>
#include <string>
#include "usuario.h"

using namespace std;

class HandlerUsuario{
	private:
		map<string,Usuario*>usuarios;
		
		static HandlerUsuario* instancia;
		HandlerUsuario();
		~HandlerUsuario();
	public:
		
		static HandlerUsuario* getInstancia();
		
		list<Usuario*> getUsuarios();
		Usuario* getUsuario(string);
		void removerUsuario(Usuario*);
		void agregarUsuario(Usuario*);
		bool existeUsuario(string);

};
#endif

  
