 #include "controlador_extras.h"
#include <list>
#include <set>
#include <string>
#include "handlerPelicula.h"
#include "cine.h"
#include "handlerUsuario.h"
#include "dtpelicula.h"
#include "pelicula.h"
#include "usuario.h"
#include "comentario.h"
#include "dtpuntaje.h"

Controlador_extras* Controlador_extras::instancia=NULL;

Controlador_extras::Controlador_extras(){

	hp=HandlerPelicula::getInstancia();
	hu=HandlerUsuario::getInstancia();
	hc=HandlerCine::getInstancia();
}
Controlador_extras::~Controlador_extras(){}

Controlador_extras* Controlador_extras::getInstancia(){

	if(instancia==NULL){
	
		instancia = new Controlador_extras();
	}
	return instancia;
}




/*controlador_extras::~controlador_extras();

Controlador_extras:: Controlador_extras(){

}
*/



set<DtPelicula> Controlador_extras::listarPeliculas(){

	list<Pelicula*> lp = hp->getPeliculas();
		set<DtPelicula> setdp;
		
		for(list<Pelicula*>::iterator it=lp.begin();it!=lp.end();it++){
			
			DtPelicula dtp=DtPelicula((*it)->getTitulo(),(*it)->getSinopsis(),(*it)->getPuntajePromedio(),(*it)->getPoster());
			setdp.insert(dtp);
		}
		
return setdp;

}

void Controlador_extras:: seleccionarPelicula(string titulo){

	setTitulo(titulo);
}
void Controlador_extras:: setTitulo(string titulo){

	this->titulo=titulo;
}
void Controlador_extras::setIdCine(int id){

	this->idCine=id;

}
bool Controlador_extras:: fuePuntuada(){
        Pelicula* p= hp->getPelicula(titulo);
  	bool resultado= p->verSiPeliculaPuntaje();
	 return resultado;	
}


 int Controlador_extras::verPuntajePelicula(){
	Pelicula* p= hp->getPelicula(titulo);
        int puntaje=p->verPuntajeDePelicula();
        return puntaje;

}
 void Controlador_extras::puntuarPelicula(int puntaje){
	Usuario* user;
	list<Usuario*> users = hu->getUsuarios();
	for(list<Usuario*>::iterator it=users.begin();it!=users.end();it++){
        if((*it)->getIniciarSesion())
         user=(*it);
 	Pelicula* p= hp->getPelicula(titulo);

 	p->añadirPuntaje(puntaje, p, user);
 
 }

 }

 list<DtComentario> Controlador_extras::listarComentarios(){

	Pelicula* pel= hp->getPelicula(titulo);
    list<DtComentario> retorno;
	retorno=pel->datosComentarioPelicula(pel->getComentarios());
	
	return retorno;
 }

//si es un comentario para una pelicula
void Controlador_extras:: publicarComentario(string texto){
	Pelicula* pel= hp->getPelicula(titulo);
	Usuario* user;
		list<Usuario*> users = hu->getUsuarios();
		for(list<Usuario*>::iterator it=users.begin();it!=users.end();it++){
			if((*it)->getIniciarSesion())
			user=(*it);
		}
	pel->añadirComentario(texto, user, pel);
		



}
//si es una respuesta a un comentario de una pelicula
void Controlador_extras::seleccionarComentarioParaResponder(int numeroComentario, string texto){
	int i=1;//int para ver la recursion
	Pelicula* pel= hp->getPelicula(titulo);
	set<Comentario*> comentarios= pel->getComentarios();
	Comentario* comentario = pel->buscarComentario(comentarios,numeroComentario, i);
	Usuario* usuarioAResponder;
	usuarioAResponder= comentario->getUsuario();
	Usuario* user;
	//buscar cual es el usuario actual
		list<Usuario*> users = hu->getUsuarios();
		for(list<Usuario*>::iterator it=users.begin();it!=users.end();it++){
			if((*it)->getIniciarSesion())
			user=(*it);
		}
	//responder a comentario
	pel->responderComentario(comentario,texto, user, usuarioAResponder);
}

pair <list<DtComentario>, list <DtPuntaje>> Controlador_extras::verPuntajeYComentariosPelicula(){

	Pelicula* pel= hp->getPelicula(titulo);
    list<DtComentario> retornoC;		
	list<DtPuntaje> retornoP;
	retornoC=pel->datosComentarioPelicula(pel->getComentarios());
	retornoP=pel->verPuntajesDePelicula();	
	return make_pair(retornoC,retornoP);


}
void Controlador_extras::salir(){
	borrarTitulo();
	borrarCine();
	
	}	

void Controlador_extras::borrarTitulo(){
titulo=' ';

}	
void Controlador_extras::borrarCine(){
	idCine=0;
	
	}
set<DtCine> Controlador_extras::infoAdicional(){

		Pelicula* p=hp->getPelicula(titulo);
		
		set<DtCine> setdtc=p->accedoPeliculaCine();
		
		return setdtc;
}
set<DtFuncion> Controlador_extras::listarFuncionesDeCineYPeliculas(){

	set<DtFuncion> setdf;
	
	Cine* c=hc->getCine(idCine);
	
	setdf=c->accedoCineParaFuncion(titulo);

	return setdf;

}
 /*
controlador_extras:: void seleccionarCine(int id);


controlador_extras:: set <DtCine> infoAdicional();



controlador_extras:: void puntuarPelicula(int puntaje);



controlador_extras:: void setIdCine(int id);



controlador_extras:: void borrarPelicula();


controlador_extras:: DtPelicula verPuntajeYComentariosPelicula();


controlador_extras:: set<DtFuncion> listarFuncionesDeCineYPeliculas();


controlador_extras:: void seleccionarComentario(DtComentario comentario,string texto);


controlador_extras:: void salir();



}
*/
