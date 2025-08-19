#ifndef DTFECHASISTEMA_H
#define DTFECHASISTEMA_H

#include <string>
#include "dtfecha.h"

using namespace std;

class DtFechaSistema {
	private:
		Fecha fechaActual;
		string horarioActual;
	public:
		DtFechaSistema(Fecha,string);
		Fecha getFechaActual();
		string getHorarioActual();


};
#endif
