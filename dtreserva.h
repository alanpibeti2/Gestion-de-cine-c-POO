#ifndef DTRESERVA_H
#define DTRESERVA_H

#include <string>

using namespace std;

class DtReserva{
	protected:
		float costo; 
		
	public:

		bool operator<(const DtReserva& dtr) const;
		virtual string tipoReserva() const =0;


};
#endif
