#ifndef DTCOMENTARIO_H
#define DTCOMENTARIO_H
#include <iostream>
#include <string>

using namespace std;

class DtComentario{
	private:
		string texto;
		string usuario;
		string userAResponder;
		string pelicula;
	public:
DtComentario(string,string,string,string);
 string getTexto() const;
 string getUsuario() const;
 string getUserAResponder() const;
 string getPelicula() const;
 friend ostream& operator<<(ostream& os, const DtComentario& d);
};
#endif