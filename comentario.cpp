#include "comentario.h"
#include "dtcomentario.h"
#include "usuario.h"
#include "pelicula.h"
#include <string>
//constructor para una respuesta(no me interesa la peli)
Comentario::Comentario(string txt, Usuario* user, Usuario* userAResp){
    this->texto=txt;
    this->usuario=user;
    this->usuarioAResponder=userAResp;
}
//constructor para un comentario de una pelicula
Comentario::Comentario(string txt, Usuario* user, Pelicula* pel){
    this->texto=txt;
    this->usuario=user;
    this->pelicula=pel;
    }
int Comentario ::tipoComentario(Comentario* comentario){
    if (usuarioAResponder== nullptr)
    return 0;
    else
    return 1;

}
DtComentario Comentario::getDatos(Comentario* comentario){  
    if(tipoComentario(comentario)==1)
       return DtComentario (getTexto(), getUsuarioTexto(), getUsuarioAResponderTexto()," ");
    else 
      return DtComentario(getTexto(), getUsuarioTexto()," ", getPeliculaATexto());
     
}
set<Comentario*> Comentario::getRespuestas(){
    cout<<"Entro a las respuestas del comentario"<<endl;
return respuestas;
}
string Comentario::getUsuarioTexto(){
string nomUsuario= usuario->getNickname();
return nomUsuario;
}
string Comentario::getPeliculaATexto(){
string titulo=pelicula->getTitulo();
return titulo;
}

string Comentario::getUsuarioAResponderTexto(){
    string usuarioResponder= usuarioAResponder->getNickname();
    return usuarioResponder;
}
void Comentario::agregarRespuesta(string texto, Usuario* user,Usuario* usuarioAResp){
    respuestas.insert(new Comentario(texto, user, usuarioAResp));
}
Usuario*  Comentario::getUsuario(){
return usuario;

}
bool Comentario::tieneRespuestas() {
    if(!respuestas.empty())
    return true;
    else 
    return false;
}
std::string Comentario::getTexto() {
    return texto;
}