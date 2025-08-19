# FLAGS
CXX = g++
CXXFLAGS = -Wall -g -fPIE
LDFLAGS = -pie

# REGLA PRINCIPAL
all: main.o controlador_crearReserva.o controlador_extras.o controlador_pelicula.o controlador_sesionUsuario.o controlador_altaFuncionyCine.o fabrica.o usuario.o pelicula.o cine.o sala.o funcion.o reserva.o debito.o credito.o comentario.o puntaje.o financiera.o dtpelicula.o dtcine.o dtfuncion.o dtsala.o dtreserva.o dtpuntaje.o dtusuario.o dtcomentario.o dtfecha.o dtdireccion.o dthorario.o handlerUsuario.o handlerCine.o handlerPelicula.o fechaSistema.o dtfechasistema.o dtdebito.o dtcredito.o
	$(CXX) $(LDFLAGS) -o main $^

# OBJETOS INDIVIDUALES
main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

controlador_crearReserva.o: controlador_crearReserva.h controlador_crearReserva.cpp
	$(CXX) $(CXXFLAGS) -c controlador_crearReserva.cpp

controlador_extras.o: controlador_extras.h controlador_extras.cpp
	$(CXX) $(CXXFLAGS) -c controlador_extras.cpp

controlador_pelicula.o: controlador_pelicula.h controlador_pelicula.cpp
	$(CXX) $(CXXFLAGS) -c controlador_pelicula.cpp

controlador_sesionUsuario.o: controlador_sesionUsuario.h controlador_sesionUsuario.cpp
	$(CXX) $(CXXFLAGS) -c controlador_sesionUsuario.cpp

controlador_altaFuncionyCine.o: controlador_altaFuncionyCine.h controlador_altaFuncionyCine.cpp
	$(CXX) $(CXXFLAGS) -c controlador_altaFuncionyCine.cpp

fabrica.o: fabrica.h fabrica.cpp
	$(CXX) $(CXXFLAGS) -c fabrica.cpp

usuario.o: usuario.h usuario.cpp
	$(CXX) $(CXXFLAGS) -c usuario.cpp

pelicula.o: pelicula.h pelicula.cpp
	$(CXX) $(CXXFLAGS) -c pelicula.cpp

cine.o: cine.h cine.cpp
	$(CXX) $(CXXFLAGS) -c cine.cpp

sala.o: sala.h sala.cpp
	$(CXX) $(CXXFLAGS) -c sala.cpp

funcion.o: funcion.h funcion.cpp
	$(CXX) $(CXXFLAGS) -c funcion.cpp

reserva.o: reserva.h reserva.cpp
	$(CXX) $(CXXFLAGS) -c reserva.cpp

debito.o: debito.h debito.cpp
	$(CXX) $(CXXFLAGS) -c debito.cpp

credito.o: credito.h credito.cpp
	$(CXX) $(CXXFLAGS) -c credito.cpp

comentario.o: comentario.h comentario.cpp
	$(CXX) $(CXXFLAGS) -c comentario.cpp

puntaje.o: puntaje.h puntaje.cpp
	$(CXX) $(CXXFLAGS) -c puntaje.cpp

financiera.o: financiera.h financiera.cpp
	$(CXX) $(CXXFLAGS) -c financiera.cpp

dtpelicula.o: dtpelicula.h dtpelicula.cpp
	$(CXX) $(CXXFLAGS) -c dtpelicula.cpp

dtcine.o: dtcine.h dtcine.cpp
	$(CXX) $(CXXFLAGS) -c dtcine.cpp

dtfuncion.o: dtfuncion.h dtfuncion.cpp
	$(CXX) $(CXXFLAGS) -c dtfuncion.cpp

dtsala.o: dtsala.h dtsala.cpp
	$(CXX) $(CXXFLAGS) -c dtsala.cpp

dtreserva.o: dtreserva.h dtreserva.cpp
	$(CXX) $(CXXFLAGS) -c dtreserva.cpp

dtpuntaje.o: dtpuntaje.h dtpuntaje.cpp
	$(CXX) $(CXXFLAGS) -c dtpuntaje.cpp

dtusuario.o: dtusuario.h dtusuario.cpp
	$(CXX) $(CXXFLAGS) -c dtusuario.cpp

dtcomentario.o: dtcomentario.h dtcomentario.cpp
	$(CXX) $(CXXFLAGS) -c dtcomentario.cpp

dtfecha.o: dtfecha.h dtfecha.cpp
	$(CXX) $(CXXFLAGS) -c dtfecha.cpp

dtdireccion.o: dtdireccion.h dtdireccion.cpp
	$(CXX) $(CXXFLAGS) -c dtdireccion.cpp

dthorario.o: dthorario.h dthorario.cpp
	$(CXX) $(CXXFLAGS) -c dthorario.cpp

handlerUsuario.o: handlerUsuario.h handlerUsuario.cpp
	$(CXX) $(CXXFLAGS) -c handlerUsuario.cpp

handlerCine.o: handlerCine.h handlerCine.cpp
	$(CXX) $(CXXFLAGS) -c handlerCine.cpp

handlerPelicula.o: handlerPelicula.h handlerPelicula.cpp
	$(CXX) $(CXXFLAGS) -c handlerPelicula.cpp

fechaSistema.o: fechaSistema.h fechaSistema.cpp
	$(CXX) $(CXXFLAGS) -c fechaSistema.cpp

dtfechasistema.o: dtfechasistema.h dtfechasistema.cpp
	$(CXX) $(CXXFLAGS) -c dtfechasistema.cpp

dtdebito.o: dtdebito.h dtdebito.cpp
	$(CXX) $(CXXFLAGS) -c dtdebito.cpp

dtcredito.o: dtcredito.h dtcredito.cpp
	$(CXX) $(CXXFLAGS) -c dtcredito.cpp

clean:
	rm -f main
	rm -f *.o

