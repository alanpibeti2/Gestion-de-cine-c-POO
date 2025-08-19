#ifndef COMENTARIO_H
#define COMENTARIO_H

#include <string>
#include "usuario.h"
#include "pelicula.h"
#include "dtcomentario.h"
#include "comentario.h"
#include <set>
class Pelicula;
class Usuario;

using namespace std;

class Comentario{
	private:
		string texto;
		Usuario* usuario;
		Pelicula* pelicula;
		set<Comentario*> respuestas;
		Usuario* usuarioAResponder;
	public:
	Comentario(string, Usuario*, Usuario*);//para responder
	Comentario(string , Usuario*, Pelicula*);//para comentar la peli
	
	string getTexto();
	Usuario* getUsuario();
	string getNombreUsuario();
	Usuario* getUsuarioAResponder();
	bool tieneRespuestas();
	set<Comentario*> getRespuestas();
	DtComentario getDatos(Comentario*);
	string getUsuarioTexto();
	string getUsuarioAResponderTexto();
	string getPeliculaATexto();
	void agregarRespuesta(string, Usuario*, Usuario*);
	int tipoComentario(Comentario*);
	
};
#endif
