#ifndef NODOEMPLEADO_H
#define NODOEMPLEADO_H
#include "Empleado.h"

// Clase Nodo para almacenar cada elemento dentro de la lista enlazada dinamica
class NodoEmpleado {
public:
	// Constructor que recibe un objeto Empleado y deja el siguiente en NULL
	NodoEmpleado(Empleado *dato);
	
	// Destructor del nodo
	virtual ~NodoEmpleado();
	
	// Metodos modificadores y consultores del nodo
	void setDato(Empleado *dato);
	Empleado* getDato();
	void setSig(NodoEmpleado *sig);
	NodoEmpleado* getSig();
	
private:
	// Puntero al empleado almacenado en el nodo
	Empleado *dato;
	
	// Puntero que apunta al siguiente nodo de la lista
	NodoEmpleado *sig;
};

#endif
