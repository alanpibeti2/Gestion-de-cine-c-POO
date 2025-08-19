#include "controlador_altaFuncionyCine.h"
#include <iostream>

Controlador_altaFuncionYCine* Controlador_altaFuncionYCine::instancia=NULL;
Controlador_altaFuncionYCine::Controlador_altaFuncionYCine(){

	hp=HandlerPelicula::getInstancia();
	hc=HandlerCine::getInstancia();
	idFuncion=1;
	idCineAutoInc=1;
}
Controlador_altaFuncionYCine::~Controlador_altaFuncionYCine(){}

Controlador_altaFuncionYCine* Controlador_altaFuncionYCine::getInstancia(){

	if(instancia==NULL){
	
		instancia = new Controlador_altaFuncionYCine();
	}
	return instancia;
}
set<DtPelicula> Controlador_altaFuncionYCine::listarPeliculas(){

	list<Pelicula*> lp = hp->getPeliculas();
	set<DtPelicula> setdp;
	
	for(list<Pelicula*>::iterator it=lp.begin();it!=lp.end();it++){
		
		DtPelicula dtp=DtPelicula((*it)->getTitulo(),(*it)->getSinopsis(),(*it)->getPuntajePromedio(),(*it)->getPoster());
		setdp.insert(dtp);
	}
	
	return setdp;
	
}
void Controlador_altaFuncionYCine::setTitulo(string tit){

	titulo=tit;
}
void Controlador_altaFuncionYCine::seleccionarPelicula(string tit){

	setTitulo(tit);
}

set<DtCine> Controlador_altaFuncionYCine::listarCines(){

	list<Cine*> lc = hc->getCines();
	set<DtCine> setdc;
	
	for(list<Cine*>::iterator it=lc.begin();it!=lc.end();it++){
		
		DtCine dtc=DtCine((*it)->getId(),(*it)->getDireccion().getCalle(),(*it)->getDireccion().getNumero());
		setdc.insert(dtc);
	}
	
	return setdc;

}
set<DtSala> Controlador_altaFuncionYCine::seleccionarCine(int unaid){
	
	setIdCine(unaid);
	Cine* c = hc->getCine(idCine);
	
	list<Sala*> ls = c->getSalas(); 
	set<DtSala> setds;
	
	for(list<Sala*>::iterator it=ls.begin();it!=ls.end();it++){
		
		list<Funcion*> lf=(*it)->getFunciones();
		list<DtFuncion> setdf;
		for(list<Funcion*>::iterator itf=lf.begin();itf!=lf.end();itf++){
			
			DtFuncion dtf=DtFuncion((*itf)->getId(),(*itf)->getFecha(),(*itf)->getHorario());
			setdf.push_back(dtf);
			
		}
		DtSala dts=DtSala((*it)->getId(),(*it)->getCapacidad(),setdf);
		setds.insert(dts);
	}
	
	return setds;
}
void Controlador_altaFuncionYCine::setIdCine(int unaid){

	idCine=unaid;
}
void Controlador_altaFuncionYCine::seleccionarSala(int unaid){

	setIdSala(unaid);
}
void Controlador_altaFuncionYCine::setIdSala(int unaid){

	idSala=unaid;	
}
void Controlador_altaFuncionYCine::ingresarNuevaFuncion(Fecha f,Horario h){

	Cine* c = hc->getCine(idCine);
	Sala* s = c->getSala(idSala);
	Pelicula* p = hp->getPelicula(titulo);
	
	Funcion* fun= new Funcion(idFuncion,f,h);
	idFuncion++;
	
	s->agregarFuncion(fun);
	p->agregarFuncion(fun);
	
	fun->setPelicula(p);
	fun->setSala(s);
	
}
void Controlador_altaFuncionYCine::salirAltaFuncion(){

	borrarTitulo();
	borrarIdCine();
	borrarIdSala();	

}
void Controlador_altaFuncionYCine::borrarTitulo(){

	titulo="";
}
void Controlador_altaFuncionYCine::borrarIdCine(){

	idCine=0;
}
void Controlador_altaFuncionYCine::borrarIdSala(){

	idSala=0;
}
void Controlador_altaFuncionYCine::agregarCine(string call,int num){

	Direccion dir(call,num);
	setDireccion(dir);
}
void Controlador_altaFuncionYCine::setDireccion(Direccion dir){

	direccion=dir;
}
void Controlador_altaFuncionYCine::agregarSalas(set<int> caps){

	setCapacidades(caps);

}
void Controlador_altaFuncionYCine::setCapacidades(set<int> caps){

	capacidades=caps;

}
void Controlador_altaFuncionYCine::confirmarCine(){

	Cine* c = new Cine(idCineAutoInc,direccion);
	hc->agregarCine(c);
	idCineAutoInc++;
	
	for(set<int>::iterator it=this->capacidades.begin();it!=capacidades.end();it++){
	
		Sala* s = new Sala(c->getIdSalaAutoInc(),*it);
		c->agregarSala(s);
	}

}
void Controlador_altaFuncionYCine::borrarDireccion(){

	direccion=Direccion();
}
void Controlador_altaFuncionYCine::borrarCapacidades(){

	capacidades.clear();
}
void Controlador_altaFuncionYCine::salirAltaCine(){


	borrarDireccion();
	borrarCapacidades();
}


