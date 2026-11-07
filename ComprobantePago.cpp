#include "ComprobantePago.h"

ComprobantePago::ComprobantePago(Empleado *empleado, Departamento *departamento) {
	this->empleadoRef = empleado;
	this->departamentoRef = departamento;
}

ComprobantePago::~ComprobantePago() {
	
}

string ComprobantePago::generarComprobante() {
	stringstream x;
	x << "========================================" << endl;
	x << "        COMPROBANTE DE PLANILLA         " << endl;
	x << "========================================" << endl;
	x << empleadoRef->toString() << endl;
	x << departamentoRef->toString() << endl;
	x << "----------------------------------------" << endl;
	return x.str();
}

void ComprobantePago::autoGuardar(ofstream &estFile) {
	estFile << "COMPROBANTE_PAGO" << endl;
	empleadoRef->autoGuardar(estFile);
	departamentoRef->autoGuardar(estFile);
}
