#include "Enfermero.h"

Enfermero::Enfermero() : Empleado() {
	horasNocturnas = new int;
	bonoTurno = new double;
}

Enfermero::Enfermero(string *id, string *nombre, string *cedula, double *salarioBase, int *departamentoId, int *horasNocturnas, double *bonoTurno) 
	: Empleado(id, nombre, cedula, salarioBase, departamentoId) {
	this->horasNocturnas = horasNocturnas;
	this->bonoTurno = bonoTurno;
}

Enfermero::~Enfermero() {
	// destructor
}

void Enfermero::setHorasNocturnas(int *horasNocturnas) {
	this->horasNocturnas = horasNocturnas;
}

int Enfermero::getHorasNocturnas() {
	return *horasNocturnas;
}

void Enfermero::setBonoTurno(double *bonoTurno) {
	this->bonoTurno = bonoTurno;
}

double Enfermero::getBonoTurno() {
	return *bonoTurno;
}

// Calculo de salario neto incluyendo turnos nocturnos y bono
double Enfermero::calcularSalarioNeto() {
	return *salarioBase + *bonoTurno + (*horasNocturnas * 15.0);
}

string Enfermero::obtenerTipo() {
	return "Enfermero";
}

string Enfermero::toString() {
	stringstream x;
	x << "--- DATOS DEL ENFERMERO ---" << endl;
	x << Empleado::toString();
	x << "Horas Nocturnas: " << *horasNocturnas << endl;
	x << "Bono Turno: " << *bonoTurno << endl;
	x << "Salario Neto: " << calcularSalarioNeto() << endl;
	return x.str();
}

// Guarda en el archivo indicando la etiqueta de tipo y luego los datos
void Enfermero::autoGuardar(ofstream &estFile) {
	estFile << "Enfermero" << endl;
	Empleado::autoGuardar(estFile);
	estFile << *horasNocturnas << endl
		<< *bonoTurno << endl;
}

Enfermero* Enfermero::autoLeer(ifstream &estFile) {
	string *id = new string();
	string *nom = new string();
	string *ced = new string();
	double *sal = new double;
	int *dep = new int;
	int *hNoc = new int;
	double *bTur = new double;
	
	if (!(estFile >> *id)) { delete id; delete nom; delete ced; delete sal; delete dep; delete hNoc; delete bTur; return NULL; }
	if (!(estFile >> *nom)) { delete id; delete nom; delete ced; delete sal; delete dep; delete hNoc; delete bTur; return NULL; }
	if (!(estFile >> *ced)) { delete id; delete nom; delete ced; delete sal; delete dep; delete hNoc; delete bTur; return NULL; }
	if (!(estFile >> *sal)) { delete id; delete nom; delete ced; delete sal; delete dep; delete hNoc; delete bTur; return NULL; }
	if (!(estFile >> *dep)) { delete id; delete nom; delete ced; delete sal; delete dep; delete hNoc; delete bTur; return NULL; }
	if (!(estFile >> *hNoc)) { delete id; delete nom; delete ced; delete sal; delete dep; delete hNoc; delete bTur; return NULL; }
	if (!(estFile >> *bTur)) { delete id; delete nom; delete ced; delete sal; delete dep; delete hNoc; delete bTur; return NULL; }
	
	cout << "   --Cargando registro de Enfermero..." << endl;
	return new Enfermero(id, nom, ced, sal, dep, hNoc, bTur);
}
