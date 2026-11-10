#include "ListaEmpleados.h"
#include "Medico.h"
#include "Enfermero.h"
#include "Administrativo.h"

// Constructor que inicializa los punteros de la lista como vacios
ListaEmpleados::ListaEmpleados() {
	cabeza = cola = actual = NULL;
}

// Destructor que recorre la lista liberando cada nodo y su contenido con delete
ListaEmpleados::~ListaEmpleados() {
	while(cabeza != NULL) {
		actual = cabeza;
		cabeza = cabeza->getSig();
		delete actual->getDato();
		delete actual;
	}
}

// Retorna verdadero si la lista esta vacia
bool ListaEmpleados::vacio() {
	return cabeza == NULL;
}

// Cuenta la cantidad de nodos existentes en la lista
int ListaEmpleados::contar() {
	actual = cabeza;
	int cont = 0;
	while(actual != NULL) {
		actual = actual->getSig();
		cont++;
	}
	return cont;
}

// Inserta un nuevo empleado al final y guarda automaticamente en el archivo
void ListaEmpleados::insertarEmpleado(Empleado *dato) {
	NodoEmpleado *aux = new NodoEmpleado(dato);
	if(vacio()) {
		cabeza = aux;
	} else {
		actual = cabeza;
		while(actual->getSig() != NULL) {
			actual = actual->getSig();
		}
		actual->setSig(aux);
	}
	guardarEnArchivo("empleados.txt");
}

// Inserta un empleado al cargar el archivo sin disparar guardados circulares
void ListaEmpleados::insertarEmpleadoSinGuardar(Empleado *dato) {
	NodoEmpleado *aux = new NodoEmpleado(dato);
	if(vacio()) {
		cabeza = aux;
	} else {
		actual = cabeza;
		while(actual->getSig() != NULL) {
			actual = actual->getSig();
		}
		actual->setSig(aux);
	}
}

// Elimina un empleado por cedula y actualiza el archivo automaticamente
string ListaEmpleados::eliminarEmpleado(string cedula) {
	if(vacio()) {
		return "0"; // Codigo de estado: Lista vacia
	}
	
	actual = cabeza;
	NodoEmpleado *aux = cabeza;
	
	if(cabeza->getDato()->getCedula() == cedula) {
		cabeza = cabeza->getSig();
		delete aux->getDato();
		delete aux;
		guardarEnArchivo("empleados.txt");
		return "1"; // Eliminacion exitosa
	}
	
	bool encontrado = false;
	while(actual->getSig() != NULL && !encontrado) {
		if(actual->getSig()->getDato()->getCedula() == cedula) {
			aux = actual->getSig();
			actual->setSig(aux->getSig());
			encontrado = true;
		} else {
			actual = actual->getSig();
		}
	}
	
	if(!encontrado) {
		return "-1"; // No se encontro
	} else {
		delete aux->getDato();
		delete aux;
		guardarEnArchivo("empleados.txt");
		return "1";  // Eliminacion exitosa
	}
}

// Modifica un empleado por cedula y actualiza el archivo automaticamente
string ListaEmpleados::modificarEmpleado(string cedula, Empleado *dato) {
	actual = cabeza;
	if(vacio()) {
		return "0";
	} else {
		bool n = true;
		while(actual != NULL && n == true) {
			if(actual->getDato()->getCedula() == cedula) {
				n = false;
				delete actual->getDato();
				actual->setDato(dato);
			}
			actual = actual->getSig();
		}
		if(actual == NULL && n == true) {
			return "-1";
		} else {
			guardarEnArchivo("empleados.txt");
			return "1";
		}
	}
}

// Consulta la informacion de un empleado por cedula
string ListaEmpleados::consultarEmpleado(string cedula) {
	actual = cabeza;
	if(vacio()) {
		return "0";
	} else {
		bool n = true;
		while(actual != NULL && n == true) {
			if(actual->getDato()->getCedula() == cedula) {
				n = false;
				return actual->getDato()->toString();
			}
			actual = actual->getSig();
		}
		if(actual == NULL) {
			return "-1";
		}
	}
	return "0";
}

// Retorna un string con todos los empleados registrados
string ListaEmpleados::listarEmpleados() {
	string cadena = "";
	actual = cabeza;
	if(vacio()) {
		return "0";
	} else {
		while(actual != NULL) {
			cadena = cadena + actual->getDato()->toString() + "\n";
			actual = actual->getSig();
		}
		return cadena;
	}
}

// Guarda toda la lista en el archivo de texto plano
void ListaEmpleados::guardarEnArchivo(string nombreArchivo) {
	ofstream salida;
	salida.open(nombreArchivo.c_str(), ios::out);
	if(salida.is_open()) {
		actual = cabeza;
		while(actual != NULL) {
			actual->getDato()->autoGuardar(salida);
			actual = actual->getSig();
		}
		salida.close();
	}
}

// Carga polimorficamente los registros desde el archivo de texto al iniciar
void ListaEmpleados::cargarDesdeArchivo(string nombreArchivo) {
	ifstream entrada;
	entrada.open(nombreArchivo.c_str());
	if(!entrada.is_open()) {
		return;
	}
	
	string tipo = "";
	while(entrada >> tipo) {
		if(tipo == "Medico") {
			string *id = new string();
			string *nom = new string();
			string *ced = new string();
			double *sal = new double;
			int *dep = new int;
			int *hEx = new int;
			double *bGu = new double;
			
			entrada >> *id >> *nom >> *ced >> *sal >> *dep >> *hEx >> *bGu;
			Empleado *emp = new Medico(id, nom, ced, sal, dep, hEx, bGu);
			insertarEmpleadoSinGuardar(emp);
		} 
		else if(tipo == "Enfermero") {
			string *id = new string();
			string *nom = new string();
			string *ced = new string();
			double *sal = new double;
			int *dep = new int;
			int *hNoc = new int;
			double *bTur = new double;
			
			entrada >> *id >> *nom >> *ced >> *sal >> *dep >> *hNoc >> *bTur;
			Empleado *emp = new Enfermero(id, nom, ced, sal, dep, hNoc, bTur);
			insertarEmpleadoSinGuardar(emp);
		}
		else if(tipo == "Administrativo") {
			string *id = new string();
			string *nom = new string();
			string *ced = new string();
			double *sal = new double;
			int *dep = new int;
			double *inc = new double;
			
			entrada >> *id >> *nom >> *ced >> *sal >> *dep >> *inc;
			Empleado *emp = new Administrativo(id, nom, ced, sal, dep, inc);
			insertarEmpleadoSinGuardar(emp);
		}
	}
	entrada.close();
}
