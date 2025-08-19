#ifndef DTHORARIO_H
#define DTHORARIO_H

#include <string>

using namespace std;

class Horario{
	private:
		string horaComienzo;
		string horaFin;
	public:
		Horario(string,string);
		Horario();
		string getHoraComienzo()const;
		string getHoraFin()const;



};
#endif
