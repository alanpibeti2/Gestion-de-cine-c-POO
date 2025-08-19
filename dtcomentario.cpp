
#include "dtcomentario.h"
#include <string>
DtComentario::DtComentario(string txt, string user, string userAResp, string peli) {
    this->texto = txt;
    this->usuario = user;
    this->userAResponder = userAResp;
    this->pelicula=peli;
}
string DtComentario::getTexto() const{
return texto;

}
string DtComentario::getUsuario() const{
    return usuario;

}
string DtComentario::getUserAResponder() const{
    return userAResponder;

}
  string DtComentario::getPelicula() const{

    return pelicula;

  }
ostream& operator<<(ostream& os, const DtComentario& d) {
    os << "<" << d.getUsuario()<< ">: ";

    if (!d.getUserAResponder().empty())
        os << "Comentario respuesta al comentario de " << d.getUserAResponder()<< ">"<<endl;

    os << "   " << d.getTexto();
    return os;
}