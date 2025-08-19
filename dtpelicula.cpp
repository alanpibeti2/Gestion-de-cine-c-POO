#include "dtpelicula.h"

DtPelicula::DtPelicula(string tit,string sin,float pp,string pos){

	titulo=tit;
	sinopsis=sin;
	puntajePromedio=pp;
	poster=pos;
}
DtPelicula::~DtPelicula(){}

ostream& operator<<(ostream& os, const DtPelicula& d) {
    os << d.getTitulo(); 
    return os;

}
bool DtPelicula::operator<(const DtPelicula& dtp)const{

	if(this->titulo<dtp.titulo){
	
		return true;
	}else{
	
		return false;
	}

}
string DtPelicula::getTitulo()const{

	return titulo;
}
string DtPelicula::getSinopsis()const{

	return sinopsis;
}
string DtPelicula::getPoster()const{

	return poster;
}
