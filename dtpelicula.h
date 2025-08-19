#ifndef DTPELICULA_H
#define DTPELICULA_H

#include <string>
#include <set>

using namespace std;

class DtPelicula{
	private:
		string titulo;
		string sinopsis;
		float puntajePromedio;
		string poster;
		
	public:
	
		DtPelicula(string,string,float,string);
		bool operator<(const DtPelicula& dtp) const;
		~DtPelicula();
		string getTitulo()const;
		string getSinopsis()const;
		string getPoster()const;
		friend ostream& operator<<(ostream& os, const DtPelicula& d);



};
#endif
