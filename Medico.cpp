#include "Medico.h"

// Constructor por defecto que inicializa la clase base y reserva memoria propia
Medico::Medico() : Empleado() {
	horasExtra = new int;
	bonoGuardias = new double;
}

// Constructor con parametros
Medico::Medico(string *id, string *nombre, string *cedula, double *salarioBase, int *departamentoId, int *horasExtra, double *bonoGuardias) 
	: Empleado(id, nombre, cedula, salarioBase, departamentoId) {
	this->horasExtra = horasExtra;
	this->bonoGuardias = bonoGuardias;
}

// Destructor de la clase Medico
Medico::~Medico() {
	
}

// Asigna las horas extra mediante un puntero
void Medico::setHorasExtra(int *horasExtra) {
	this->horasExtra = horasExtra;
}

// Retorna el valor entero de las horas extra
int Medico::getHorasExtra() {
	return *horasExtra;
}

// Asigna el bono por guardias mediante un puntero
void Medico::setBonoGuardias(double *bonoGuardias) {
	this->bonoGuardias = bonoGuardias;
}

// Retorna el valor del bono por guardias
double Medico::getBonoGuardias() {
	return *bonoGuardias;
}

// Calcula el salario neto sumando base, bono de guardias y pago por horas extra
double Medico::calcularSalarioNeto() {
	return *salarioBase + *bonoGuardias + (*horasExtra * 20.0);
}

// Retorna una cadena identificando el tipo de empleado
string Medico::obtenerTipo() {
	return "Medico";
}

// Retorna un string con la informacion completa del medico formateada
string Medico::toString() {
	stringstream x;
	x << "--- DATOS DEL MEDICO ---" << endl;
	x << Empleado::toString();
	x << "Horas Extra: " << *horasExtra << endl;
	x << "Bono Guardias: " << *bonoGuardias << endl;
	x << "Salario Neto: " << calcularSalarioNeto() << endl;
	return x.str();
}

// Guarda en el archivo indicando primero el tipo y luego los datos base y especificos
void Medico::autoGuardar(ofstream &estFile) {
	estFile << "Medico" << endl;
	Empleado::autoGuardar(estFile);
	estFile << *horasExtra << endl
		<< *bonoGuardias << endl;
}
