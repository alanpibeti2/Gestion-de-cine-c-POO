#ifndef ICONTROLADOR_CREARRESERVA_H
#define ICONTROLADOR_CREARRESERVA_H

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

class IControlador_crearReserva {
	private:
		
	public:

		virtual set<DtPelicula> listarPelicula()=0;
		virtual DtPelicula seleccionarPelicula(string)=0;
		virtual void setTitulo(string)=0;
		virtual set<DtCine> listarCinesConPelicula()=0;
		virtual void seleccionarCine(int)=0;
		virtual void setIdCine(int)=0;
		virtual set<DtFuncion> listarFuncionAccesibles()=0;
		virtual void seleccionarFuncion(int,int)=0;
		virtual void setIdFuncion(int)=0;
		virtual void setCantEntradas(int)=0;
		virtual void ingresoDebito(string)=0;
		virtual void setBanco(string)=0;
		virtual void setTipoPago(string)=0;
		virtual float ingresarCredito(string)=0;
		virtual void setFinanciera(string)=0;
		virtual void setDescuento(float)=0;
		virtual float verPrecioTotal()=0;
		virtual void setPrecioTotal(float)=0;
		virtual void confirmar()=0;
		virtual void salir()=0;
		virtual void borrarTitulo()=0;
		virtual void borrarIdCine()=0;
		virtual void borrarIdFuncion()=0;
		virtual void borrarCantEntradas()=0;
		virtual void borrarBanco()=0;
		virtual void borrarTipoPago()=0;
		virtual void borrarFinanciera()=0;
		virtual void borrarDescuento()=0;
		virtual void borrarPrecioTotal()=0;
		virtual void ingresarFinanciera(string,float)=0;


};
#endif
