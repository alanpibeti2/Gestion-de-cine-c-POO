#include <iostream>
#include <string>
#include "fabrica.h"
#include "iControlador_sesionUsuario.h"
#include "iControlador_pelicula.h"
#include "iControlador_extras.h"
#include "iControlador_altaFuncionyCine.h"
#include "iControlador_crearReserva.h"
#include "dtdebito.h"
#include "dtcredito.h"

using namespace std;

Fabrica *f;
IControlador_sesionUsuario *iConSesUsu;
IControlador_pelicula *iConPel;
IControlador_extras *iConExt;
IControlador_altaFuncionYCine *iConAltFunCin;
IControlador_crearReserva *iConCreRes;

void iniciarSesion();
void cerrarSesion();
void altaUsuario();
void altaPelicula();
void altaCine();
void altaFuncion();
void crearReserva();
void verReservasDePelicula();
void eliminarPelicula();
void modificarFecha();
void consultarFecha();
void enlazarPeliculaYCine();
void imprimirPeliculas(set<DtPelicula>);
void imprimirPelicula(DtPelicula);
void imprimirTituloPeliculas(set<DtPelicula>);
void imprimirCines(set<DtCine>);
void imprimirSalasConFuncion(set<DtSala>);
void imprimirFuncionesConReservas(set<DtFuncion>);
void imprimirFunciones(set<DtFuncion>);
void imprimirFechaSistema(DtFechaSistema);
void inicializarValores();
void puntuarPelicula();
void comentarPelicula();
void verInfoDePelicula();
void verComYPunDePel();
void imprimirPuntajes(list<DtPuntaje>);
void imprimirComentarios(list<DtComentario>, int);
void imprimirComentariosYPuntajes(pair<list<DtComentario>, list<DtPuntaje>>);


int main(){

	f = Fabrica::getInstancia();
	iConSesUsu = f->getIControlador_sesionUsuario();
	iConPel = f->getIControlador_pelicula();
	iConExt = f->getIControlador_extras();
	iConAltFunCin = f->getIControlador_altaFuncionYCine();
	iConCreRes = f->getIControlador_crearReserva();
	
	int operador=0;
	bool unaVez=true;
	
	iConSesUsu->crearUsuario("admin","000","qwer");
	iConCreRes->ingresarFinanciera("blanco",0.1);
	iConCreRes->ingresarFinanciera("azul",0.15);
	iConCreRes->ingresarFinanciera("rojo",0.2);


	while(operador!=18){
		
		cout<<endl;
		cout<<"Seleccione la operacion a realizar: "<<endl;
		cout<<"1.Iniciar sesion."<<endl;
		cout<<"2.Cerrar sesion."<<endl;
		cout<<"3.Alta usuario."<<endl;
		cout<<"4.Alta pelicula."<<endl;
		cout<<"5.Alta cine."<<endl;
		cout<<"6.Alta funcion."<<endl;
		cout<<"7.Crear reserva."<<endl;
		cout<<"8.Ver reservas de pelicula."<<endl;
		cout<<"9.Eliminar pelicula."<<endl;
		cout<<"10.Modificar fecha."<<endl;
		cout<<"11.Consultar fecha."<<endl;
		cout<<"12.Enlazar pelicula y cine."<<endl;
		cout<<"13.Inicializar Valores."<<endl;
		cout<<"14.Puntuar pelicula."<<endl;
		cout<<"15.Comentar pelicula."<<endl;
		cout<<"16.Ver info de pelicula."<<endl;
		cout<<"17.Ver comentarios y puntajes de pelicula"<<endl;
		cout<<"18.Salir."<<endl;
		cout<<"Opcion: ";
		cin>>operador;
		cout<<endl;
		
		switch(operador){
		
		case 1:
		
			if(iConSesUsu->usuarioIniciado()){
			
				cout<<"Ya se inicio sesion."<<endl;
			}else{
				iniciarSesion();
			}
			break;
		case 2:
			if(iConSesUsu->usuarioIniciado()){
			
				cerrarSesion();
			}else{
				cout<<"Para acceder a esta operacion tiene que iniciar sesion."<<endl;
			}
			break;
		case 3:
			if(iConSesUsu->adminIniciado()){
			
				altaUsuario();
			}else{
				cout<<"Para acceder a esta operacion tiene que iniciar sesion el administrador."<<endl;
			}
			break;
		case 4:
			if(iConSesUsu->adminIniciado()){
			
				altaPelicula();
			}else{
				cout<<"Para acceder a esta operacion tiene que iniciar sesion el administrador."<<endl;
			}
			break;
		case 5:
			if(iConSesUsu->adminIniciado()){
			
				altaCine();
			}else{
				cout<<"Para acceder a esta operacion tiene que iniciar sesion el administrador."<<endl;
			}
			break;
		case 6:
			if(iConSesUsu->adminIniciado()){
			
				altaFuncion();
			}else{
				cout<<"Para acceder a esta operacion tiene que iniciar sesion el administrador."<<endl;
			}
			break;
		case 7:
			if(iConSesUsu->usuarioIniciado()){
			
				crearReserva();
			}else{
				cout<<"Para acceder a esta operacion tiene que iniciar sesion."<<endl;
			}
			break;
		case 8:
			if(iConSesUsu->adminIniciado()){
			
				verReservasDePelicula();	
			}else{
				cout<<"Para acceder a esta operacion tiene que iniciar sesion el administrador."<<endl;
			}
			break;
		case 9:
			if(iConSesUsu->adminIniciado()){
			
				eliminarPelicula();//anda mal, el programa queda colgado.
			}else{
				cout<<"Para acceder a esta operacion tiene que iniciar sesion el administrador."<<endl;
			}
			break;
		case 10:
			if(iConSesUsu->usuarioIniciado()){
			
				modificarFecha();
			}else{
				cout<<"Para acceder a esta operacion tiene que iniciar sesion."<<endl;
			}
			break;
		case 11:
			if(iConSesUsu->usuarioIniciado()){
			
				consultarFecha();
			}else{
				cout<<"Para acceder a esta operacion tiene que iniciar sesion."<<endl;
			}
			break;
		case 12:
			if(iConSesUsu->adminIniciado()){
			
				enlazarPeliculaYCine();
			}else{
				cout<<"Para acceder a esta operacion tiene que iniciar sesion el administrador."<<endl;
			}
			break;
		case 13:
			cout<<"antes de inicializarValores() "<<endl;
			if(unaVez){
				inicializarValores();
				cout<<"Se inicializaron los valores correctamente."<<endl;
				unaVez=false;
			}else{
			cout<<"Esta operacion solo puede efectuarse una vez."<<endl;
			}
			break;
		case 14:
		if(iConSesUsu->adminIniciado()){
			 puntuarPelicula();

			}else{
				cout<<"Para acceder a esta operacion tiene que iniciar sesion."<<endl;
			}
			break;
		case 15:
		if(iConSesUsu->adminIniciado()){
			 comentarPelicula();

			}else{
				cout<<"Para acceder a esta operacion tiene que iniciar sesion."<<endl;
			}
			break;
		case 16:	
		if(iConSesUsu->adminIniciado()){
			  verInfoDePelicula();

			}else{
				cout<<"Para acceder a esta operacion tiene que iniciar sesion."<<endl;
			}
			break;	
		case 17:		
		cout<<"en el case 17 "<<endl;
		if(iConSesUsu->adminIniciado()){
		cout<<"antes de verComYPunDePel() "<<endl;
			  verComYPunDePel();
			cout<<"despues de verComYPunDePel() "<<endl;
			}else{
				cout<<"Para acceder a esta operacion tiene que iniciar sesion."<<endl;
			}
			break;
		case 18:
		break;			
		}
	}
	


				
	
	
return 0;
}

void iniciarSesion(){

	string nombre,contra;
	bool seguir=true;
	int num;
	
	cout<<"Ingrese su Nickname: ";
	cin>>nombre;
	
	iConSesUsu->ingresarNickname(nombre);
	
	cout<<"Ingrese su contrasenia: ";
	cin>>contra;
	
	while(seguir){	
		
		if(iConSesUsu->ingresarContrasenia(contra)){
		
			cout<<"Sesion iniciada."<<endl;
			seguir=false;
		}else{
			cout<<"contrasenia Incorrecta:"<<endl;
			cout<<"Si desea intentarlo nuevamente digite 1 sino digite 2.";
			cin>>num;
			
			if(num==1){
				cout<<"Ingrese su contrasenia: ";
				cin>>contra;
			}else{
				seguir=false;
			}
		}
	}
	
	iConSesUsu->salir();

}
void cerrarSesion(){

	iConSesUsu->finalizarSesion();
	cout<<"Sesion Finalizada."<<endl;
}
void altaUsuario(){

	string nombre,contra,foto;
	cout<<"Ingrese su nickname: ";
	cin>>nombre;
	cout<<"Ingrese su contrasenia: ";
	cin>>contra;
	cout<<"Ingrese su foto de perfil: ";
	cin>>foto;
	
	if(iConSesUsu->crearUsuario(nombre,contra,foto)){
		cout<<"El usuariose ingreso correctamente"<<endl;
	}else{
	
		cout<<"El usuario ingresado ya existe."<<endl;
	}
}
void altaCine(){

	bool masCines=true,masSalas;
	string calle;
	int numero,capacidad,oper;
	set<int>caps;
	
	while(masCines){
	
		cout<<endl<<"Ingrese la calle del cine: ";
		cin>>calle;
		cout<<"Ingrese el numero de cine: ";
		cin>>numero;
		
		iConAltFunCin->agregarCine(calle,numero);
		
		masSalas=true;
		while(masSalas){
			
			cout<<"Ingrese la capacidad de la sala: ";
			cin>>capacidad;
			caps.insert(capacidad);
			
			cout<<"Si quiere agregar otra sala digite 1, de lo contrario digite 2: ";
			cin>>oper;
			
			if(oper!=1){
			
				masSalas=false;
			}
		}
		
		iConAltFunCin->agregarSalas(caps);
	
		cout<<"Si desea confirmar digite 1 de lo contrario digite 2: ";
		cin>>oper;
		
		if(oper==1){
		
			iConAltFunCin->confirmarCine();
			cout<<"El cine con sus salas se ingreso correctamente."<<endl<<endl;
		}else{
		
			cout<<"No se ingreso el cine."<<endl<<endl;
		}
		
		iConAltFunCin->salirAltaCine();
		
		cout<<"SI quiere agregar mas cines digite 1, de lo contrario digite 2: ";
		cin>>oper;
		
		if(oper!=1){
		
			masCines=false;
		}
	}
}
void imprimirPeliculas(set<DtPelicula> setdtp){

	for(set<DtPelicula>::iterator it=setdtp.begin();it!=setdtp.end();it++){	
		
		const DtPelicula p=*it;
		
		cout<<"Titulo: "<<p.getTitulo()<<endl;
		cout<<"Sinopsis: "<<p.getSinopsis()<<endl;
		cout<<"Poster: "<<p.getPoster()<<endl<<endl;
	
	}
}
void imprimirPelicula(DtPelicula dtp){

		cout<<"Titulo: "<<dtp.getTitulo()<<endl;
		cout<<"Sinopsis: "<<dtp.getSinopsis()<<endl;
		cout<<"Poster: "<<dtp.getPoster()<<endl<<endl;

}
void imprimirTituloPeliculas(set<DtPelicula> setdtp){
	

	for(set<DtPelicula>::iterator it=setdtp.begin();it!=setdtp.end();it++){	
	
		const DtPelicula p=*it;

		cout<<"Titulo: "<<p.getTitulo()<<endl;
	}
	cout<<endl;
}
void imprimirCines(set<DtCine> setdtc){

	for(set<DtCine>::iterator it=setdtc.begin();it!=setdtc.end();it++){	
		
		const DtCine c=*it;
		
		cout<<"Id: "<<c.getId()<<endl;
		cout<<"Direccion: "<<c.getDireccion().getCalle()<<" "<<c.getDireccion().getNumero()<<endl<<endl;
	}
}

void imprimirSalasConFuncion(set<DtSala> setdts){


	for(set<DtSala>::iterator it=setdts.begin();it!=setdts.end();it++){	
		
		const DtSala s=*it;
		
		cout<<"Id: "<<s.getId()<<endl;
		cout<<"Capacidad: "<<s.getCapacidad()<<endl<<endl;
		
		list<DtFuncion> ldtf = s.getDtFunciones();
		
		for(list<DtFuncion>::iterator itf=ldtf.begin();itf!=ldtf.end();itf++){
		
			const DtFuncion f=*itf;
			
			cout<<f.getFecha().getDia()<<"/"<<f.getFecha().getMes()<<"/"<<f.getFecha().getAnio()<<endl;
			cout<<"Hora de Inicio: "<<f.getHorario().getHoraComienzo()<<endl;
			cout<<"Hora de Finalizacion: "<<f.getHorario().getHoraFin()<<endl<<endl;		
		}
	}
}
void imprimirFuncionesConReservas(set<DtFuncion> setdtf){


	for(set<DtFuncion>::iterator it=setdtf.begin();it!=setdtf.end();it++){	
		
		const DtFuncion f=*it;
		
		cout<<"Id: "<<f.getId()<<endl;
		cout<<f.getFecha().getDia()<<"/"<<f.getFecha().getMes()<<"/"<<f.getFecha().getAnio()<<endl;
		cout<<"Hora de Inicio: "<<f.getHorario().getHoraComienzo()<<endl;
		cout<<"Hora de Finalizacion: "<<f.getHorario().getHoraFin()<<endl<<endl;
		
		set<DtReserva*> setdtr = f.getDtReservas();
		
		for(set<DtReserva*>::iterator itr=setdtr.begin();itr!=setdtr.end();itr++){
		
			const DtReserva* r=*itr;
			
			if(r->tipoReserva()=="debito"){
			
				const DtDebito* d=dynamic_cast<const DtDebito*>(r);
			
				cout<<"Cantidad de entradas: "<<d->getCantEntradas()<<endl;
				cout<<"Costo: "<<d->getCosto()<<endl;
				cout<<"Banco: "<<d->getBanco()<<endl<<endl;
			}else if(r->tipoReserva()=="credito"){
				
				const DtCredito* c=dynamic_cast<const DtCredito*>(r);
				
				cout<<"Cantidad de entradas: "<<c->getCantEntradas()<<endl;
				cout<<"Costo: "<<c->getCosto()<<endl;
				cout<<"Financiera: "<<c->getFinanciera()<<endl;
				cout<<"Porcentaje de Descuento: "<<c->getPorcentajeDescuento()<<endl<<endl;
			}		
		}
	}

}
void imprimirFunciones(set<DtFuncion> setdtf){

		for(set<DtFuncion>::iterator itf=setdtf.begin();itf!=setdtf.end();itf++){
		
			const DtFuncion f=*itf;
			
			cout<<"Id: "<<f.getId()<<endl;
			cout<<f.getFecha().getDia()<<"/"<<f.getFecha().getMes()<<"/"<<f.getFecha().getAnio()<<endl;
			cout<<"Hora de Inicio: "<<f.getHorario().getHoraComienzo()<<endl;
			cout<<"Hora de Finalizacion: "<<f.getHorario().getHoraFin()<<endl<<endl;		
		}
}
void imprimirFechaSistema(DtFechaSistema dtfs){

	cout<<dtfs.getFechaActual().getDia()<<"/"<<dtfs.getFechaActual().getMes()<<"/"<<dtfs.getFechaActual().getAnio()<<endl;
	cout<<"Hora: "<<dtfs.getHorarioActual()<<endl;
}
void altaFuncion(){

	string tit;
	int idCine,idSala,oper;
	int d,m,a;
	string HI,HF;
	bool masFun,masSal,masFunSal;
	
	cout<<endl;
	imprimirPeliculas(iConAltFunCin->listarPeliculas());

	cout<<"Ingrese el titulo de la pelicula: ";
	cin>>tit;
	
	iConAltFunCin->seleccionarPelicula(tit);
	
	cout<<endl;
	
	masFun=true;
	while(masFun){
		
		cout<<"Cines:"<<endl;
		imprimirCines(iConAltFunCin->listarCines());
		
		cout<<"Ingrese el id del cine: ";
		cin>>idCine;
		cout<<endl<<"Salas con sus funciones:"<<endl;
		
		imprimirSalasConFuncion(iConAltFunCin->seleccionarCine(idCine));
		
		masSal=true;
		while(masSal){
		
			cout<<"Ingrese el id de la sala: ";
			cin>>idSala;
			
			iConAltFunCin->seleccionarSala(idSala);
			
			masFunSal=true;
			while(masFunSal){
			
				cout<<"Ingrese el dia: ";
				cin>>d;
				cout<<"Ingrese el mes: ";
				cin>>m;
				cout<<"Ingrese el anio: ";
				cin>>a;
				
				Fecha fech= Fecha(d,m,a);
				
				cout<<"Ingrese la hora de inicio: ";
				cin>>HI;
				cout<<"Ingrese la hora de finalizacion: ";
				cin>>HF;
				
				Horario hor= Horario(HI,HF);
				
				iConAltFunCin->ingresarNuevaFuncion(fech,hor);
				cout<<"La funcion se ingreso correctamente."<<endl<<endl;
				
				//enlaza las peliculas con los cines.
				iConPel->seleccionarPelicula(tit);
				iConPel->seleccionarCine(idCine);
				iConPel->confirmar();
				iConPel->salir();
				
				cout<<"Si desea ingresar otra funcion en la misma sala digite 1, de lo contrario digite 2: ";
				cin>>oper;
				cout<<endl;
			
				if(oper!=1){
		
					masFunSal=false;
				}
				
			}
			
			cout<<"Si desea ingresar otra funcion en otra sala digite 1, de lo contrario digite 2: ";
			cin>>oper;
			cout<<endl;
			
			if(oper!=1){
		
				masSal=false;
			}
			
		}
		
		cout<<"Si desea ingresar otra funcion en otro cine digite 1, de lo contrario digite 2: ";
		cin>>oper;
		cout<<endl;
		
		if(oper!=1){
		
			masFun=false;
		}
	}
	
	iConAltFunCin->salirAltaFuncion();
}
void altaPelicula(){

	string tit,sinop,post;
	bool masPel;
	int oper;
	
	masPel=true;
	while(masPel){
		cout<<"Ingrese el titulo: ";
		cin>>tit;
		cout<<"Ingrese la sinopsis: ";
		cin>>sinop;
		cout<<"Ingrese el poster: ";
		cin>>post;
		
		if(iConPel->existeLaPelicula(tit)){
		
			cout<<"El titulo ingresado ya existe."<<endl;
			cout<<"Si quiere volover a intentarlo digite 1, de lo contrario digite 2: ";
			cin>>oper;
			
			if(oper!=1){
			
				masPel=false;
			} 
		}else{
		
			iConPel->ingresarPelicula(tit,sinop,post);
			masPel=false;
		}
	}
	
	iConPel->salir();
}
void crearReserva(){

	bool selecPelis=true,selecFun=false;
	int oper,idCine,idFuncion,cantE;
	string tit,tp,banc,financ;
	
	while(selecPelis){
		
		
		imprimirTituloPeliculas(iConCreRes->listarPelicula());

		cout<<"Si desea seleccionar una pelicula digite 1, de lo contrario digite 2: ";
		cin>>oper;
		cout<<endl;
		
		if(oper==1){
		
			cout<<"Ingrese el titulo: ";
			cin>>tit;
			cout<<endl;
			
			imprimirPelicula(iConCreRes->seleccionarPelicula(tit));
			
			cout<<"Si desea ver informacion adicional digite 1, de lo contrario digite 2: ";
			cin>>oper;
			cout<<endl;
			
			if(oper==1){
				cout<<"Cine:"<<endl;
				imprimirCines(iConCreRes->listarCinesConPelicula());
				
				cout<<"Si desea seleccionar un cine digite 1, de lo contrario digite 2: ";
				cin>>oper;
				
				if(oper==1){
				
					cout<<"Ingrese el id del cine que quiere seleccionar: ";
					cin>>idCine;
					
					iConCreRes->seleccionarCine(idCine);
					imprimirFunciones(iConCreRes->listarFuncionAccesibles());
					
					cout<<"Si quiere elegir una funcion para el cine y la pelicula previamente ingresada degite 1,"<<endl;
					cout<<"Si desea seleccionar otra pelicula digite 2, de lo contrario digite 3: ";
					cin>>oper;
					
					if(oper==1){
					
						selecFun=true;
						selecPelis=false;
					}else if(oper==2){
					
					
					}else{
					
						selecPelis=false;
					}
					
				}else{
				
					selecPelis=false;
				}
			
			}else{
			
				selecPelis=false;
			}
			
		
		}else{
			
			selecPelis=false;
		}
	
	
	}
	
	if(selecFun){
	
		cout<<"Ingrese la id de la funcion que desea ver: ";
		cin>>idFuncion;
		cout<<"Ingrese la cantidad de asientos que dese reservar: ";
		cin>>cantE;
		
		iConCreRes->seleccionarFuncion(idFuncion,cantE);
		
		cout<<"Si paga con debito digite 1,si paga con credito digite 2: ";
		cin>>oper;
		
		if(oper==1){
			
			cout<<"Ingrese el banco: ";
			cin>>banc;
			
			iConCreRes->ingresoDebito(banc);
		}else if(oper==2){
		
			cout<<"Ingrese la financiera: ";
			cin>>financ;
			
			cout<<"Descuento: "<<iConCreRes->ingresarCredito(financ)<<endl;
			
		}
		cout<<"Precio Total: "<<iConCreRes->verPrecioTotal()<<endl;
		
		cout<<"Digite 1 si desea confirmar la reserva,2 en caso contrario: ";
		cin>>oper;
		
		if(oper==1){
		
			iConCreRes->confirmar();
			cout<<"La reserva se ingreso con exito."<<endl;
		}
	}
	
	iConCreRes->salir();
	 

}
void enlazarPeliculaYCine(){

	string tit;
	int idc,oper;

	imprimirPeliculas(iConPel->listarPeliculas());
	
	cout<<"Ingrese el titulo a enlazar: ";
	cin>>tit;
	
	iConPel->seleccionarPelicula(tit);
	
	imprimirCines(iConPel->listarCines());
	
	cout<<"Ingrese el id del cine a enlazar: ";
	cin>>idc;
	
	iConPel->seleccionarCine(idc);
	
	cout<<"Digite 1 si desea confiramar, de lo contrario digite 2: ";
	cin>>oper;
	
	if(oper==1){
	
		iConPel->confirmar();
	}
	
	iConPel->salir();


}
void modificarFecha(){

	int d,m,a;
	string hor;
	
	cout<<"Ingrese el dia: ";
	cin>>d;
	cout<<"Ingrese el mes: ";
	cin>>m;
	cout<<"Ingrese el anio. ";
	cin>>a;
	
	Fecha fech=Fecha(d,m,a);
	
	cout<<"Ingrese la hora: ";
	cin>>hor;
	
	iConSesUsu->modificarFechaS(fech,hor);
	cout<<"Fecha del sistema modificada con exito."<<endl;

}
void consultarFecha(){

	imprimirFechaSistema(iConSesUsu->consultarFechaS());
}
void verReservasDePelicula(){
	
	string tit;
	
	imprimirPeliculas(iConPel->listarPeliculas());
	
	cout<<"Ingrese el titulo de la pelicula seleccionada: ";
	cin>>tit;
	
	iConPel->seleccionarPelicula(tit);

	imprimirFuncionesConReservas(iConPel->listarReservas(tit));

}
void eliminarPelicula(){

	string tit;
	int oper;
	
	imprimirPeliculas(iConPel->listarPeliculas());
	
	cout<<"Ingrese el titulo de la pelicula a eliminar: ";
	cin>>tit;
	
	iConPel->seleccionarPelicula(tit);
	
	cout<<"si desea confirmar digite 1, de lo contrario digite 2: ";
	cin>>oper;
	if(oper==1){
		iConPel->confirmarBorrado(tit);
		cout<<"La pelicula se borro correctamente."<<endl;
	}
	
	iConPel->salir();

}

void puntuarPelicula(){
string pel;
int op;
bool puntuada;
int puntuacion;
int nuevaPuntuacion;
imprimirPeliculas(iConExt->listarPeliculas());
cout<<"Elija una pelicula: ";
cin>>pel;
iConExt->seleccionarPelicula(pel);
puntuada=iConExt->fuePuntuada();

if(puntuada){
	puntuacion = iConExt->verPuntajePelicula();
	cout<<"Tu Puntaje es: "<<puntuacion<<endl;
	do{
	cout<<"Desea cambiarlo? 1 si 2 no: "<<endl;
	cin>>op;
	}while(op != 1 && op != 2);
	if(op==1){
	  cout<<"Cual es el puntaje? del 1 al 10: "<<endl;
	  cin>>nuevaPuntuacion;
		iConExt->puntuarPelicula(nuevaPuntuacion);
	}else if(op==2){
		cout<<"No se cambio la puntuacion"<<endl;
	}
}else{
	  cout<<"Cual es el puntaje? del 1 al 10: ";
	  cin>>nuevaPuntuacion;
		iConExt->puntuarPelicula(nuevaPuntuacion);	
		
}
}
void comentarPelicula(){
	string pel;
	string texto;
	set<DtPelicula> pelis;
	int op;
	imprimirPeliculas(iConExt->listarPeliculas());
	cout<<"Elija una pelicula: ";
	cin>>pel;
	iConExt->seleccionarPelicula(pel);
	int numC=1;
	imprimirComentarios(iConExt->listarComentarios(),numC);
	do{
	cout<<"Desea comentar? '1' si, '2' no: ";
	cin>>op;
	}while(op != 1 && op != 2);
	if(op==1){
		cout<<"Desea comentar o responder? '1' para comentar, '2' para responder: ";
		cin>>op;
		if(op==1){
			cout<<"Ingrese comentario: "<< endl;
			cin>>texto;
			iConExt->publicarComentario(texto);
			
		}else if(op==2){
			int numC;
			cout<<"Numero del comentario a responder: "<< endl;
			cin>>numC;
			cout<<"Ingrese respuesta: "<< endl;
			cin>>texto;
			iConExt->seleccionarComentarioParaResponder(numC, texto);
		
		}
}else{
	iConExt->salir();
}
}
void verInfoDePelicula(){

	string pel;
	int idCine;
	int op;
	imprimirTituloPeliculas(iConCreRes->listarPelicula());

	
 		do{
		cout<<"Si desea seleccionar una pelicula digite 1, de lo contrario digite 2: ";
		cin>>op;
		}while(op != 1 && op != 2);
		
		if(op==1){
		
			cout<<"Ingrese el titulo: ";
			cin>>pel;
			cout<<endl;
			
			imprimirPelicula(iConCreRes->seleccionarPelicula(pel));
			do{
			cout<<"Si desea ver informacion adicional digite 1, de lo contrario digite 2: ";
			cin>>op;
			}while(op != 1 && op != 2);
			cout<<endl;
			
			if(op==1){
				cout<<"Cine:"<<endl;
				imprimirCines(iConCreRes->listarCinesConPelicula());
				do{
				cout<<"Si desea seleccionar un cine digite 1, de lo contrario digite 2: ";
				cin>>op;
				}while(op != 1 && op != 2);
				if(op==1){
				
					cout<<"Ingrese el ID del cine que quiere seleccionar: ";
					cin>>idCine;
					
					iConCreRes->seleccionarCine(idCine);
					imprimirFunciones(iConCreRes->listarFuncionAccesibles());
				}
			}
		}

}
void verComYPunDePel(){
		set<DtPelicula> pelis;
		string pel;
		int op;
	pelis=iConExt->listarPeliculas();
	imprimirPeliculas(iConExt->listarPeliculas());
		cout<<"Elija una pelicula: ";
		cin>>pel;
	iConExt->seleccionarPelicula(pel);
	imprimirComentariosYPuntajes(iConExt->verPuntajeYComentariosPelicula());
	do{
		cout<<"Desea salir? 1 si, 2 no"<< endl;
		cin>>op;
	}while(op != 1 && op != 2);
	if(op==1)
		iConExt->salir();
		
}

void imprimirPuntajes(list<DtPuntaje> puntajes){
	for(list<DtPuntaje>::iterator itp=puntajes.begin();itp!=puntajes.end();itp++){
		 cout <<*itp<< endl;
	}
}

void imprimirComentarios(list<DtComentario> comentarios, int numC){
		for(list<DtComentario>::iterator itc=comentarios.begin();itc!=comentarios.end();itc++){
		 if(itc->getPelicula()==" "){//es respuesta
			cout << numC << ". "<< *itc << endl;
		}else{
			cout << numC << ". "<< "<"<<itc->getUsuario()<<">: "<< itc->getTexto()<<endl;
			
		 }
		 numC++;
		}

}
/*void imprimirComentarios(list<DtComentario> comentarios, int numC){
		for(list<DtComentario>::iterator itc=comentarios.begin();itc!=comentarios.end();itc++){
		 cout << numC << ". "<< *itc << endl;
		 numC++;
		}
el que funciona
}*/

void imprimirComentariosYPuntajes(pair<list<DtComentario>, list<DtPuntaje>> datos){
	int numC=1;
	list<DtComentario> comentarios = datos.first;
	list<DtPuntaje> puntajes = datos.second;
		imprimirComentarios(comentarios, numC);
		imprimirPuntajes(puntajes);
	


}
void inicializarValores(){
	
	Fecha fech1={27,6,2025},fech2={28,6,2025},fech3={29,6,2025};
	Horario hor1={"17:00","19:00"},hor2={"19:00","20:30"},hor3={"21:00","22:20"},hor4={"15:00","17:00"};
	set<int>caps1={25,35,45,55},caps2={30},caps3={22,33,44};
	
	//ingreso usuarios
	iConSesUsu->crearUsuario("mateo","123","asdf");
	iConSesUsu->crearUsuario("alan","321","fdsa");
	iConSesUsu->salir();
	
	//ingreso peliculas
	iConPel->ingresarPelicula("cars","autos","abc123");
	iConPel->ingresarPelicula("wally","robots","www234");	
	iConPel->ingresarPelicula("shrek","ogro","ogr098");
	
	//ingreso cines
	iConAltFunCin->agregarCine("Rivera",3135);//id1
	iConAltFunCin->agregarSalas(caps1);//id1,id2,id3,id4
	iConAltFunCin->confirmarCine();
	iConAltFunCin->salirAltaCine();

	iConAltFunCin->agregarCine("Garibaldi",2211);//id2
	iConAltFunCin->agregarSalas(caps2);//id1
	iConAltFunCin->confirmarCine();
	iConAltFunCin->salirAltaCine();
	
	iConAltFunCin->agregarCine("Bulevar_Artigas",3243);//id3
	iConAltFunCin->agregarSalas(caps3);//id1,id2,id3
	iConAltFunCin->confirmarCine();
	iConAltFunCin->salirAltaCine();
	
	//ingreso funciones
	iConAltFunCin->seleccionarPelicula("cars");
	iConAltFunCin->seleccionarCine(1);
	iConAltFunCin->seleccionarSala(3);
	iConAltFunCin->ingresarNuevaFuncion(fech1,hor4);//id1
	//enlaza cine con pelicula.
	iConPel->seleccionarPelicula("cars");
	iConPel->seleccionarCine(1);
	iConPel->confirmar();
	iConPel->salir();
	iConAltFunCin->salirAltaFuncion();
	
	iConAltFunCin->seleccionarPelicula("cars");
	iConAltFunCin->seleccionarCine(2);
	iConAltFunCin->seleccionarSala(1);
	iConAltFunCin->ingresarNuevaFuncion(fech1,hor4);//id2
	//enlaza cine con pelicula.
	iConPel->seleccionarPelicula("cars");
	iConPel->seleccionarCine(2);
	iConPel->confirmar();
	iConPel->salir();
	iConAltFunCin->salirAltaFuncion();
	
	iConAltFunCin->seleccionarPelicula("wally");
	iConAltFunCin->seleccionarCine(3);
	iConAltFunCin->seleccionarSala(3);
	iConAltFunCin->ingresarNuevaFuncion(fech2,hor1);//id3
	//enlaza cine con pelicula.
	iConPel->seleccionarPelicula("wally");
	iConPel->seleccionarCine(3);
	iConPel->confirmar();
	iConPel->salir();
	iConAltFunCin->salirAltaFuncion();
	
	iConAltFunCin->seleccionarPelicula("wally");
	iConAltFunCin->seleccionarCine(3);
	iConAltFunCin->seleccionarSala(3);
	iConAltFunCin->ingresarNuevaFuncion(fech2,hor2);//id4
	//enlaza cine con pelicula.
	iConPel->seleccionarPelicula("wally");
	iConPel->seleccionarCine(3);
	iConPel->confirmar();
	iConPel->salir();
	iConAltFunCin->salirAltaFuncion();	
	
	iConAltFunCin->seleccionarPelicula("wally");
	iConAltFunCin->seleccionarCine(1);
	iConAltFunCin->seleccionarSala(1);
	iConAltFunCin->ingresarNuevaFuncion(fech1,hor3);//id5
	//enlaza cine con pelicula.
	iConPel->seleccionarPelicula("wally");
	iConPel->seleccionarCine(1);
	iConPel->confirmar();
	iConPel->salir();
	iConAltFunCin->salirAltaFuncion();
	
	iConAltFunCin->seleccionarPelicula("shrek");
	iConAltFunCin->seleccionarCine(2);
	iConAltFunCin->seleccionarSala(1);
	iConAltFunCin->ingresarNuevaFuncion(fech1,hor4);//id6
	//enlaza cine con pelicula.
	iConPel->seleccionarPelicula("shrek");
	iConPel->seleccionarCine(2);
	iConPel->confirmar();
	iConPel->salir();
	iConAltFunCin->salirAltaFuncion();
	
	iConAltFunCin->seleccionarPelicula("shrek");
	iConAltFunCin->seleccionarCine(2);
	iConAltFunCin->seleccionarSala(1);
	iConAltFunCin->ingresarNuevaFuncion(fech1,hor2);//id7
	//enlaza cine con pelicula.
	iConPel->seleccionarPelicula("shrek");
	iConPel->seleccionarCine(2);
	iConPel->confirmar();
	iConPel->salir();
	iConAltFunCin->salirAltaFuncion();
	
}
//pair <list<DtComentario>, list <DtPuntaje>> Controlador_extras:

