#include "dtpuntaje.h"
#include <iostream>
DtPuntaje::DtPuntaje(int pun,string user){
    puntos=pun;
    usuario=user;

    
}
 int DtPuntaje::getPuntaje()const {
    return puntos;
}

 string DtPuntaje::getUsuario()const {
    return usuario;
}

ostream& operator<<(ostream& os, const DtPuntaje& d) {
    os << "Usuario: " << d.getUsuario() << ", Puntaje: " << d.getPuntaje();
    return os;
}
