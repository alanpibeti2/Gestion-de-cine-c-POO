#ifndef DTFECHA_H
#define DTFECHA_H



class Fecha{
	private:
		int dia;
		int mes;
		int anio;
	public:
		Fecha(int,int,int);
		Fecha();
		int getDia()const;
		int getMes()const;
		int getAnio()const;
		bool esPosterior(Fecha);


};
#endif
