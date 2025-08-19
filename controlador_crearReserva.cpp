#include "controlador_crearReserva.h"

#define PRECIO 300

Controlador_crearReserva* Controlador_crearReserva::instancia=NULL;
Controlador_crearReserva::Controlador_crearReserva(){

	hp=HandlerPelicula::getInstancia();
	hc=HandlerCine::getInstancia();
	hu=HandlerUsuario::getInstancia();
}
Controlador_crearReserva::~Controlador_crearReserva(){}

Controlador_crearReserva* Controlador_crearReserva::getInstancia(){

	if(instancia==NULL){
	
		instancia = new Controlador_crearReserva();
	}
	return instancia;
}

set<DtPelicula> Controlador_crearReserva::listarPelicula(){

		list<Pelicula*> lp = hp->getPeliculas();
			set<DtPelicula> setdp;
			
			for(list<Pelicula*>::iterator it=lp.begin();it!=lp.end();it++){
				
				DtPelicula dtp=DtPelicula((*it)->getTitulo(),(*it)->getSinopsis(),(*it)->getPuntajePromedio(),(*it)->getPoster());
				setdp.insert(dtp);
			}
			
	return setdp;

}

DtPelicula Controlador_crearReserva::seleccionarPelicula(string unTitulo){

	setTitulo(unTitulo);
	
	Pelicula* p=hp->getPelicula(unTitulo);
	
	DtPelicula dtp= DtPelicula(p->getTitulo(),p->getSinopsis(),p->getPuntajePromedio(),p->getPoster());

	return dtp;

}
void Controlador_crearReserva::setTitulo(string unTitulo){

	titulo=unTitulo;
}
set<DtCine> Controlador_crearReserva::listarCinesConPelicula(){

	Pelicula* p=hp->getPelicula(titulo);
	
	set<DtCine> setdtc=p->accedoPeliculaCine();
	
	return setdtc;

}
void Controlador_crearReserva::seleccionarCine(int unaId){

	setIdCine(unaId);
}
void Controlador_crearReserva::setIdCine(int unaId){

	idCine=unaId;
}
set<DtFuncion> Controlador_crearReserva::listarFuncionAccesibles(){

	set<DtFuncion> setdf;
	
	Cine* c=hc->getCine(idCine);
	
	setdf=c->accedoCineParaFuncion(titulo);

	return setdf;

}
void Controlador_crearReserva::seleccionarFuncion(int unaId,int cantE){

	setIdFuncion(unaId);
	setCantEntradas(cantE);
}
void Controlador_crearReserva::setIdFuncion(int unaId){

	idFuncion=unaId;
}
void Controlador_crearReserva::setCantEntradas(int cantE){

	cantEntradas=cantE;
}
void Controlador_crearReserva::ingresoDebito(string banc){

	setBanco(banc);
	setTipoPago("debito");
}
void Controlador_crearReserva::setBanco(string banc){

	banco=banc;
}
void Controlador_crearReserva::setTipoPago(string tipo){

	tipoPago=tipo;
}
float Controlador_crearReserva::ingresarCredito(string financ){

	float desc;
	
	map<string,Financiera*>::iterator it=this->financieras.find(financ);
	
	if(it!=this->financieras.end()){
	
		desc=it->second->getDescuento();
		
	}else{
	
		desc=0;
	}
	setFinanciera(financ);
	setDescuento(desc);
	setTipoPago("credito");
	
	return desc*100;
	
}
void Controlador_crearReserva::setFinanciera(string financ){

	financiera=financ;
}
void Controlador_crearReserva::setDescuento(float desc){

	descuento=desc;
}
float Controlador_crearReserva::verPrecioTotal(){

	float pTotal;
	
	if(tipoPago=="credito"){
	
		pTotal=((float)cantEntradas*PRECIO)*(1-descuento);
	}else if(tipoPago=="debito"){
	
		pTotal=((float)cantEntradas*PRECIO);
	}
	
	setPrecioTotal(pTotal);
	
	return pTotal;
}
void Controlador_crearReserva::setPrecioTotal(float pt){

	precioTotal=pt;
}
void Controlador_crearReserva::confirmar(){

	list<Usuario*> lu=hu->getUsuarios();
	Usuario* u;
	Reserva* r;
	Pelicula* p=hp->getPelicula(titulo);
	
	for(list<Usuario*>::iterator it=lu.begin();it!=lu.end();it++){
	
		if((*it)->getIniciarSesion()){
		
			u=(*it);
		}
	}
	
	r=u->accederUsuario(precioTotal,cantEntradas,banco,financiera,descuento,tipoPago);
	r->setUsuario(u);
	p->accedoPeliculaParaFuncion(idFuncion,r);
}
void Controlador_crearReserva::salir(){

		borrarTitulo();
		borrarIdCine();
		borrarIdFuncion();
		borrarCantEntradas();
	 	borrarBanco();
		borrarTipoPago();
		borrarFinanciera();
		borrarDescuento();
		borrarPrecioTotal();
}
void Controlador_crearReserva::borrarTitulo(){

	titulo="";
}
void Controlador_crearReserva::borrarIdCine(){

	idCine=0;
}
void Controlador_crearReserva::borrarIdFuncion(){

	idFuncion=0;
}
void Controlador_crearReserva::borrarCantEntradas(){

	cantEntradas=0;
}
void Controlador_crearReserva::borrarBanco(){

	banco="";
}
void Controlador_crearReserva::borrarTipoPago(){

	tipoPago="";
}
void Controlador_crearReserva::borrarFinanciera(){

	financiera="";
}
void Controlador_crearReserva::borrarDescuento(){

	descuento=0;
}
void Controlador_crearReserva::borrarPrecioTotal(){

	precioTotal=0;
}
void Controlador_crearReserva::ingresarFinanciera(string nom,float desc){

	Financiera* fin= new Financiera(nom,desc);
	
	this->financieras.insert(pair<string,Financiera*>(fin->getNombre(),fin));
}







