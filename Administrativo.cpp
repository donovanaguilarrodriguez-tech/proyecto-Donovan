#include "Administrativo.h"

Administrativo::Administrativo() : Empleado() {
	incentivoProductividad = new double;
}

Administrativo::Administrativo(string *id, string *nombre, string *cedula, double *salarioBase, int *departamentoId, double *incentivoProductividad) 
	: Empleado(id, nombre, cedula, salarioBase, departamentoId) {
	this->incentivoProductividad = incentivoProductividad;
}

Administrativo::~Administrativo() {
	// destructor
}

void Administrativo::setIncentivoProductividad(double *incentivoProductividad) {
	this->incentivoProductividad = incentivoProductividad;
}

double Administrativo::getIncentivoProductividad() {
	return *incentivoProductividad;
}

// Calculo de salario neto sumando incentivo
double Administrativo::calcularSalarioNeto() {
	return *salarioBase + *incentivoProductividad;
}

string Administrativo::obtenerTipo() {
	return "Administrativo";
}

string Administrativo::toString() {
	stringstream x;
	x << "--- DATOS DEL ADMINISTRATIVO ---" << endl;
	x << Empleado::toString();
	x << "Incentivo Productividad: " << *incentivoProductividad << endl;
	x << "Salario Neto: " << calcularSalarioNeto() << endl;
	return x.str();
}

// Guarda en el archivo indicando la etiqueta de tipo y luego los datos
void Administrativo::autoGuardar(ofstream &estFile) {
	estFile << "Administrativo" << endl;
	Empleado::autoGuardar(estFile);
	estFile << *incentivoProductividad << endl;
}

Administrativo* Administrativo::autoLeer(ifstream &estFile) {
	string *id = new string();
	string *nom = new string();
	string *ced = new string();
	double *sal = new double;
	int *dep = new int;
	double *inc = new double;
	
	if (!(estFile >> *id)) { delete id; delete nom; delete ced; delete sal; delete dep; delete inc; return NULL; }
	if (!(estFile >> *nom)) { delete id; delete nom; delete ced; delete sal; delete dep; delete inc; return NULL; }
	if (!(estFile >> *ced)) { delete id; delete nom; delete ced; delete sal; delete dep; delete inc; return NULL; }
	if (!(estFile >> *sal)) { delete id; delete nom; delete ced; delete sal; delete dep; delete inc; return NULL; }
	if (!(estFile >> *dep)) { delete id; delete nom; delete ced; delete sal; delete dep; delete inc; return NULL; }
	if (!(estFile >> *inc)) { delete id; delete nom; delete ced; delete sal; delete dep; delete inc; return NULL; }
	
	cout << "   --Cargando registro de Administrativo..." << endl;
	return new Administrativo(id, nom, ced, sal, dep, inc);
}
