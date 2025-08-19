#ifndef DTPUNTAJE_H
#define DTPUNTAJE_H
#include <string>

using namespace std;
class DtPuntaje{
	private:
		int puntos;
		string usuario;
	public:
	DtPuntaje(int,string);
	friend ostream& operator<<(ostream& os, const DtPuntaje& d);
	int getPuntaje() const;
	string getUsuario()const;
};
#endif