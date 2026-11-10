#ifndef LISTAEMPLEADOS_H
#define LISTAEMPLEADOS_H
#include "NodoEmpleado.h"
#include <fstream>

// Clase ListaEmpleados encargada de administrar los nodos y gestionar archivos planos
class ListaEmpleados {
public:
	// Constructor por defecto
	ListaEmpleados();
	
	// Destructor que libera toda la memoria de los nodos recursivamente
	~ListaEmpleados();
	
	// Metodos principales de mantenimiento de la lista
	void insertarEmpleado(Empleado *dato);
	void insertarEmpleadoSinGuardar(Empleado *dato); // Metodo auxiliar para carga inicial sin bucles
	string eliminarEmpleado(string cedula);
	string modificarEmpleado(string cedula, Empleado *dato);
	string consultarEmpleado(string cedula);
	string listarEmpleados();
	
	// Metodos auxiliares de verificacion y conteo
	bool vacio();
	int contar();
	
	// Metodos de persistencia masiva para guardar y cargar desde archivos de texto
	void guardarEnArchivo(string nombreArchivo);
	void cargarDesdeArchivo(string nombreArchivo);
	
private:
	// Punteros de control de la lista enlazada
	NodoEmpleado *cabeza;
	NodoEmpleado *actual;
	NodoEmpleado *cola;
};

#endif
