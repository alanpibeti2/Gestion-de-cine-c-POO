#ifndef ICONTROLADOR_ALTAFUNCIONYCINE_H
#define ICONTROLADOR_ALTAFUNCIONYCINE_H

#include <set>
#include <string>
#include "dtpelicula.h"
#include "dtcine.h"
#include "dtsala.h"
#include "dtfuncion.h"
#include "dtdireccion.h" 

class IControlador_altaFuncionYCine{
	private:
		
	public:
			//operaciones de altafuncion
		virtual set<DtPelicula> listarPeliculas()=0;
		virtual void seleccionarPelicula(string)=0;
		virtual set<DtCine> listarCines()=0;
		virtual set<DtSala> seleccionarCine(int)=0;
		virtual void seleccionarSala(int)=0;
		virtual void ingresarNuevaFuncion(Fecha,Horario)=0;
		virtual void salirAltaFuncion()=0;
		virtual void setTitulo(string)=0;
		virtual void setIdCine(int)=0;
		virtual void setIdSala(int)=0;
		virtual void borrarTitulo()=0;
		virtual void borrarIdCine()=0;
		virtual void borrarIdSala()=0;
		//operaciones de altacine
		virtual void agregarCine(string call,int num)=0;
		virtual void agregarSalas(set<int>)=0;
		virtual void confirmarCine()=0;
		virtual void setCapacidades(set<int>)=0;
		virtual void setDireccion(Direccion)=0;
		virtual void borrarDireccion()=0;
		virtual void borrarCapacidades()=0;
		virtual void salirAltaCine()=0;
};

#endif
