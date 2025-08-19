#ifndef DTDIRECCION_H
#define DTDIRECCION_H

#include <string>

using namespace std;

class Direccion{
	private:
		string calle;
		int numero;
	public:
		Direccion(string,int);
		Direccion();
		~Direccion();
		string getCalle()const;
		int getNumero()const;
};
#endif
