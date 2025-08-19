#ifndef HANDLERCINE_H
#define HANDLERCINE_H

#include <map>
#include <list>
#include "cine.h"

class HandlerCine{
	private:
	
		map<int,Cine*>cines;
		
		static HandlerCine* instancia;
		HandlerCine();
		~HandlerCine();
		
	public:

		static HandlerCine* getInstancia();

		list<Cine*> getCines();
        Cine* getCine(int);
        void removerCine(Cine*);
        void agregarCine(Cine*);
        bool existeCine(int);
};
#endif
