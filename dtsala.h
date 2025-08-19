#ifndef DTSALA_H
#define DTSALA_H

#include "dtfuncion.h"
#include <list>

class DtSala{
	private:
		int id;
		int capacidad;
		list<DtFuncion> dtfunciones;
	public:

		DtSala(int,int,list<DtFuncion>);
		~DtSala();
		bool operator<(const DtSala& dts) const;
		int getId()const;
		int getCapacidad()const;
		list<DtFuncion> getDtFunciones()const;


};
#endif
