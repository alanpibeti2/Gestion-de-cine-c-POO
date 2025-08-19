#include "pelicula.h"
#include "dtpelicula.h"
#include "handlerUsuario.h"
#include "handlerPelicula.h"
#include <iostream>

Pelicula::Pelicula(string unTitulo,string unaSinopsis,string unPoster){

	titulo=unTitulo;
	sinopsis=unaSinopsis;
	poster=unPoster;
	puntajePromedio=0;
	
}
Pelicula::~Pelicula(){
	
		//cout<<"antes del bucle en pelicula cpp"<<endl;
	for(map<int,Funcion*>::iterator it=funciones.begin();it!=funciones.end();it++){
		//cout<<"antes de remover sus funciones de la sala"<<endl;
		it->second->removerseDeSala();
		//cout<<"despues de remover sus funciones de la sala y antes del delete funcion"<<endl;
		delete it->second;
		//cout<<"despues del delete funcion"<<endl;
	}


}
string Pelicula:: getTitulo(){
return titulo;
}
string Pelicula::getSinopsis(){
return sinopsis;
}
float Pelicula::getPuntajePromedio(){
return puntajePromedio;
}
string Pelicula:: getPoster(){
return poster;

}
DtPelicula Pelicula::getDatos(){//devuelve un dtPelicula 
	return DtPelicula(getTitulo(), getSinopsis(), getPuntajePromedio(), getPoster());

}
bool Pelicula::verSiPeliculaPuntaje(){
set<Puntaje*>::iterator itpun;
bool esDelUsuario;
for(itpun = puntajes.begin(); itpun != puntajes.end(); itpun++){
   esDelUsuario=(*itpun)->esDelUsuario();
	if(esDelUsuario==true){
	return true;
		}
  }
        return false;
}
int Pelicula::verPuntajeDePelicula(){
	set<Puntaje*>::iterator itpun;
	bool esDelUsuario;
	for(itpun = puntajes.begin(); itpun != puntajes.end(); itpun++){
	   esDelUsuario=(*itpun)->esDelUsuario();
		if(esDelUsuario==true){
		int puntaje=(*itpun)->getPuntos();
		return puntaje;
		}
	}
	return 0;
}
void Pelicula::añadirPuntaje(int punt, Pelicula* p, Usuario* u){
if(verSiPeliculaPuntaje()){
	set<Puntaje*>::iterator itpun;
	bool esDelUsuario;
	for(itpun=puntajes.begin();itpun!=puntajes.end();){
		 esDelUsuario=(*itpun)->esDelUsuario();
		if(esDelUsuario==true){
		itpun = puntajes.erase(itpun);
		}else
		itpun++;
	}
}

Puntaje* pu= new Puntaje(punt, u, p);
puntajes.insert(pu);
}
void borrarPuntaje(Puntaje* punt){


}
void Pelicula::agregarFuncion(Funcion* f){
 
    this->funciones.insert(pair<int,Funcion*>(f->getId(),f));

}
set<DtCine> Pelicula::accedoPeliculaCine(){
	
	set<DtCine> setdc;
	
	for(map<int,Cine*>::iterator it=this->cines.begin();it!=this->cines.end();it++){
	
		DtCine dtc=DtCine(it->second->getId(),it->second->getDireccion().getCalle(),it->second->getDireccion().getNumero());
		setdc.insert(dtc);
	}
	return setdc;

}
bool Pelicula::esPelicula(string unTitulo){

	if(titulo==unTitulo){
	
		return true;
	}else{
	
		return false;
	}

}
void Pelicula::accedoPeliculaParaFuncion(int idF,Reserva* r){
	
	Funcion* f;
	
	map<int,Funcion*>::iterator it=this->funciones.find(idF);
	f=it->second;
	
	f->accedoFuncionParaReserva(r);

}
void Pelicula::agregarCine(Cine* c){ 
    this->cines.insert(pair<int,Cine*>(c->getId(),c));
}
set<DtFuncion> Pelicula::accedoPelicula(){

	set<DtFuncion> setdtf;
	
	for(map<int,Funcion*>::iterator it=funciones.begin();it!=funciones.end();it++){
	
		setdtf.insert(it->second->accedoFuncionConReserva());
	}
	
	return setdtf;

}	
	
set<Comentario*> Pelicula::getComentarios(){
	
		return comentarios;
	}

list<DtComentario> Pelicula::datosComentarioPelicula(set<Comentario*> comentarios) {
	
		list<DtComentario> resultado;
	
		for (set<Comentario*>::iterator it = comentarios.begin(); it != comentarios.end(); ++it) {
			resultado.push_back((*it)->getDatos((*it))); // guardo el valor en la lista
			// recursión con los hijos
			if ((*it)->tieneRespuestas()==true) {
				list<DtComentario> respuestas = datosComentarioPelicula((*it)->getRespuestas());
				resultado.insert(resultado.end(), respuestas.begin(), respuestas.end()); // copio los hijos
			}
			
		}	
		return resultado;	
	}
	

	
	
	void Pelicula::responderComentario(Comentario* comentario,string texto, Usuario* usuario, Usuario* usuarioAResp){
		comentario->agregarRespuesta(texto,usuario,usuarioAResp);
	}
	void Pelicula::añadirComentario(string texto, Usuario* user, Pelicula* pel){

		comentarios.insert(new Comentario(texto, user, pel));
		cout<< "Comentario creado exitosamente"<< endl;
	}


	list<DtPuntaje> Pelicula::verPuntajesDePelicula(){
		list<DtPuntaje> retorno;
		for(set<Puntaje*>::iterator itpun = puntajes.begin(); itpun != puntajes.end(); itpun++){
			DtPuntaje resultado = (*itpun)->getDatos();
			retorno.push_back(resultado);
			}
			return retorno;
		}
		Comentario* Pelicula::buscarComentario(set<Comentario*> comentarios, int numeroComentario,int& i){
		for (set<Comentario*>::iterator it = comentarios.begin(); it != comentarios.end(); ++it) {
			if(i==numeroComentario){
			return *it;
			}
			i++;
			// recursión con los hijos
			if ((*it)->tieneRespuestas()) {
			Comentario* resultado = buscarComentario((*it)->getRespuestas(), numeroComentario, i);
			if (resultado != nullptr) {
                return resultado;
		    }
		}	
	}
	return NULL;
	}