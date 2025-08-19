#ifndef CONTROLADOR_CREARRESERVA_H
#define CONTROLADOR_CREARRESERVA_H

#include "iControlador_crearReserva.h"
#include <map>
#include <set>
#include <list>
#include "handlerPelicula.h"
#include "handlerUsuario.h"
#include "handlerCine.h"
#include <string>
#include "financiera.h"
#include "dtcine.h"
#include "dtpelicula.h"
#include "dtfuncion.h"
#include "pelicula.h"

using namespace std;

class Controlador_crearReserva : public IControlador_crearReserva{
	private:
		string titulo;
		int idCine;
		int idFuncion;
		int cantEntradas;
		string banco;
		string tipoPago;
		string financiera;
		float descuento;
		float precioTotal;
		
		HandlerPelicula* hp;
		HandlerUsuario* hu;
		HandlerCine* hc;
		map<string,Financiera*>financieras;
		
		static Controlador_crearReserva* instancia;
		Controlador_crearReserva();
		~Controlador_crearReserva();
	public:

		static Controlador_crearReserva* getInstancia();
		
		set<DtPelicula> listarPelicula();
		DtPelicula seleccionarPelicula(string);
		void setTitulo(string);
		set<DtCine> listarCinesConPelicula();
		void seleccionarCine(int);
		void setIdCine(int);
		set<DtFuncion> listarFuncionAccesibles();
		void seleccionarFuncion(int,int);
		void setIdFuncion(int);
		void setCantEntradas(int);
		void ingresoDebito(string);
		void setBanco(string);
		void setTipoPago(string);
		float ingresarCredito(string);
		void setFinanciera(string);
		void setDescuento(float);
		float verPrecioTotal();
		void setPrecioTotal(float);
		void confirmar();
		void salir();
		void borrarTitulo();
		void borrarIdCine();
		void borrarIdFuncion();
		void borrarCantEntradas();
		void borrarBanco();
		void borrarTipoPago();
		void borrarFinanciera();
		void borrarDescuento();
		void borrarPrecioTotal();
		void ingresarFinanciera(string,float);
		
};
#endif
