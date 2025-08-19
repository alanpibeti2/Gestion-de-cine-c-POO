#ifndef DTCINE_H
#define DTCINE_H

#include "dtdireccion.h"

class DtCine{
	private:
		int id;
		Direccion direccion;
	public:

		DtCine(int,string,int);
		~DtCine();
		bool operator<(const DtCine& dtc) const;
		int getId()const;
		Direccion getDireccion()const;

};
#endif
