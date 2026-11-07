#include "Empleado.h"

// Constructor por defecto que reserva memoria dinamica para los atributos base
Empleado::Empleado() {
	id = new string();
	nombre = new string();
	cedula = new string();
	salarioBase = new double;
	departamentoId = new int;
}

// Constructor parametrizado que asigna los punteros recibidos
Empleado::Empleado(string *id, string *nombre, string *cedula, double *salarioBase, int *departamentoId) {
	this->id = id;
	this->nombre = nombre;
	this->cedula = cedula;
	this->salarioBase = salarioBase;
	this->departamentoId = departamentoId;
}

// Destructor base
Empleado::~Empleado() {

}

// Asigna un nuevo puntero para el id
void Empleado::setId(string *id) {
	this->id = id;
}

// Retorna el valor del id desreferenciando el puntero
string Empleado::getId() {
	return *id;
}

// Asigna un nuevo puntero para el nombre
void Empleado::setNombre(string *nombre) {
	this->nombre = nombre;
}

// Retorna el valor del nombre
string Empleado::getNombre() {
	return *nombre;
}

// Asigna un nuevo puntero para la cedula
void Empleado::setCedula(string *cedula) {
	this->cedula = cedula;
}

// Retorna el valor de la cedula
string Empleado::getCedula() {
	return *cedula;
}

// Asigna un nuevo puntero para el salario base
void Empleado::setSalarioBase(double *salarioBase) {
	this->salarioBase = salarioBase;
}

// Retorna el valor del salario base
double Empleado::getSalarioBase() {
	return *salarioBase;
}

// Asigna un nuevo puntero para el id del departamento
void Empleado::setDepartamentoId(int *departamentoId) {
	this->departamentoId = departamentoId;
}

// Retorna el valor del id del departamento
int Empleado::getDepartamentoId() {
	return *departamentoId;
}

// Retorna un string formateado con todos los datos generales del empleado
string Empleado::toString() {
	stringstream x;
	x << "ID: " << *id << endl;
	x << "Nombre: " << *nombre << endl;
	x << "Cedula: " << *cedula << endl;
	x << "Salario Base: " << *salarioBase << endl;
	x << "Departamento ID: " << *departamentoId << endl;
	return x.str();
}

// Escribe los atributos basicos linea por linea en el archivo de texto plano
void Empleado::autoGuardar(ofstream &estFile) {
	estFile << *id << endl
		<< *nombre << endl
		<< *cedula << endl
		<< *salarioBase << endl
		<< *departamentoId << endl;
}
