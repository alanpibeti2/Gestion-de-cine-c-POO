#include "controlador_pelicula.h"
#include "cine.h"
#include "pelicula.h"
#include <iostream>


Controlador_pelicula* Controlador_pelicula::instancia=NULL;
Controlador_pelicula::Controlador_pelicula(){
	
	hp=HandlerPelicula::getInstancia();
	hc=HandlerCine::getInstancia();
}
Controlador_pelicula::~Controlador_pelicula(){}

Controlador_pelicula* Controlador_pelicula::getInstancia(){

	if(instancia==NULL){
	
		instancia = new Controlador_pelicula();
	}
	return instancia;
}
void Controlador_pelicula::ingresarPelicula(string unTitulo,string unaSinopsis,string unPoster){

		Pelicula* p= new Pelicula(unTitulo,unaSinopsis,unPoster);
		hp->agregarPelicula(p);
	
}
bool Controlador_pelicula::existeLaPelicula(string unTitulo){

	return hp->existePelicula(unTitulo);
}
set<DtPelicula> Controlador_pelicula::listarPeliculas(){

		list<Pelicula*> lp = hp->getPeliculas();
		set<DtPelicula> setdp;
		
		for(list<Pelicula*>::iterator it=lp.begin();it!=lp.end();it++){
			
			DtPelicula dtp=DtPelicula((*it)->getTitulo(),(*it)->getSinopsis(),(*it)->getPuntajePromedio(),(*it)->getPoster());
			setdp.insert(dtp);
		}
		
	return setdp;

}
void Controlador_pelicula::seleccionarPelicula(string tit){

	setTitulo(tit);
}
void Controlador_pelicula::setTitulo(string tit){

	titulo=tit;
}
set<DtCine> Controlador_pelicula::listarCines(){

	list<Cine*> lc = hc->getCines();
	set<DtCine> setdc;
	
	for(list<Cine*>::iterator it=lc.begin();it!=lc.end();it++){
		
		DtCine dtc=DtCine((*it)->getId(),(*it)->getDireccion().getCalle(),(*it)->getDireccion().getNumero());
		setdc.insert(dtc);
	}
	
	return setdc;

}
void Controlador_pelicula::seleccionarCine(int unaid){

	setIdCine(unaid);
}
void Controlador_pelicula::setIdCine(int unaid){

	idCine=unaid;
}
void Controlador_pelicula::confirmar(){

	Pelicula* p=hp->getPelicula(titulo);
	Cine* c=hc->getCine(idCine);
	
	p->agregarCine(c);
	c->agregarPelicula(p);
}
void Controlador_pelicula::salir(){

	borrarTitulo();
	borrarIdCine();
}
void Controlador_pelicula::borrarTitulo(){

	titulo="";

}
void Controlador_pelicula::borrarIdCine(){

	idCine=0;
}
set<DtFuncion> Controlador_pelicula::listarReservas(string tit){

	Pelicula* p=hp->getPelicula(tit);

	return p->accedoPelicula();
}
void Controlador_pelicula::confirmarBorrado(string tit){

	list<Cine*> lc=hc->getCines();
	//cout<<"antes de remover de cine"<<endl;
	for(list<Cine*>::iterator it=lc.begin();it!=lc.end();it++){
		//cout<<"antes de remover en conPel"<<endl;
		(*it)->removerPelicula(tit);
		//cout<<"despues de remover en conPel"<<endl;
	}
	//cout<<"despues de remover de cine"<<endl;
	Pelicula* p=hp->getPelicula(tit);
	//cout<<"antes del delete pelicula"<<endl;
	
	hp->removerPelicula(p);
	delete p;
	
	//cout<<"depues del delete pelicula"<<endl;
	

}
