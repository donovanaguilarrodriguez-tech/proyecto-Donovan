#include "NodoEmpleado.h"

// Constructor que asigna el empleado y coloca el puntero siguiente en nulo
NodoEmpleado::NodoEmpleado(Empleado *dato) {
	this->setDato(dato);
	this->sig = NULL;
}

// Destructor del nodo
NodoEmpleado::~NodoEmpleado() {
	
}

// Asigna un empleado al nodo
void NodoEmpleado::setDato(Empleado *dato) {
	this->dato = dato;
}

// Retorna el empleado almacenado en el nodo
Empleado* NodoEmpleado::getDato() {
	return this->dato;
}

// Asigna el enlace al siguiente nodo
void NodoEmpleado::setSig(NodoEmpleado *sig) {
	this->sig = sig;
}

// Retorna el puntero al siguiente nodo
NodoEmpleado* NodoEmpleado::getSig() {
	return this->sig;
}
