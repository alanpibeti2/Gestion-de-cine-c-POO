#ifndef ICONTROLADOR_EXTRAS_H
#define ICONTROLADOR_EXTRAS_H



class IControlador_extras{
	private:

	public:
	virtual set<DtPelicula> listarPeliculas()=0;
	virtual void seleccionarPelicula(string)=0;
	virtual void setTitulo(string)=0;
	virtual void setIdCine(int)=0;
	virtual bool fuePuntuada()=0;
	virtual int verPuntajePelicula()=0;
	virtual void puntuarPelicula(int)=0;
	virtual list<DtComentario> listarComentarios()=0;
	virtual void publicarComentario(string)=0;
	virtual void seleccionarComentarioParaResponder(int, string)=0;
	virtual pair <list<DtComentario>, list <DtPuntaje>> verPuntajeYComentariosPelicula()=0;
	virtual void salir()=0;
	virtual void borrarTitulo()=0;
	virtual void borrarCine()=0;
	virtual set<DtCine> infoAdicional()=0;
	virtual set<DtFuncion> listarFuncionesDeCineYPeliculas()=0;
   



};
#endif
