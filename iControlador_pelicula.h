#ifndef ICONTROLADOR_PELICULA_H
#define ICONTROLADOR_PELICULA_H



class IControlador_pelicula{
	private:
	public:

		virtual void ingresarPelicula(string,string,string)=0;
		virtual bool existeLaPelicula(string)=0;
		virtual set<DtPelicula> listarPeliculas()=0;
		virtual void seleccionarPelicula(string)=0;
		virtual void setTitulo(string)=0;
		virtual set<DtCine> listarCines()=0;
		virtual void seleccionarCine(int)=0;
		virtual void setIdCine(int)=0;
		virtual void confirmar()=0;
		virtual void salir()=0;
		virtual void borrarTitulo()=0;
		virtual void borrarIdCine()=0;
		virtual set<DtFuncion> listarReservas(string)=0;
		virtual void confirmarBorrado(string)=0;

};
#endif
