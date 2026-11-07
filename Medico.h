#ifndef MEDICO_H
#define MEDICO_H
#include "Empleado.h"

// Clase Medico que hereda de la clase base Empleado
class Medico : public Empleado {
public:
	// Constructor por defecto
	Medico();
	
	// Constructor con parametros
	Medico(string *id, string *nombre, string *cedula, double *salarioBase, int *departamentoId, int *horasExtra, double *bonoGuardias);
	
	// Destructor virtual
	virtual ~Medico();
	
	// Metodos modificadores y consultores especificos de Medico
	void setHorasExtra(int *horasExtra);
	int getHorasExtra();
	void setBonoGuardias(double *bonoGuardias);
	double getBonoGuardias();
	
	// Sobrescritura de metodos virtuales heredados
	double calcularSalarioNeto() override;
	string obtenerTipo() override;
	string toString() override;
	
	// Sobrescritura de metodos para persistencia en archivos planos
	void autoGuardar(ofstream &estFile) override;
	static Medico* autoLeer(ifstream &estFile);
	
private:
	// Atributos exclusivos de Medico implementados con punteros
	int *horasExtra;
	double *bonoGuardias;
};

#endif
