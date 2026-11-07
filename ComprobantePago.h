#ifndef COMPROBANTEPAGO_H
#define COMPROBANTEPAGO_H
#include "Empleado.h"
#include "Departamento.h"

// Clase ComprobantePago que relaciona empleado y departamento mediante agregacion
class ComprobantePago {
public:
	ComprobantePago(Empleado *empleado, Departamento *departamento);
	virtual ~ComprobantePago();
	
	string generarComprobante();
	void autoGuardar(ofstream &estFile);
	
private:
	Empleado *empleadoRef;       // Agregacion
	Departamento *departamentoRef; // Agregacion
};

#endif
