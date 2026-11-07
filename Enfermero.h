#ifndef ENFERMERO_H
#define ENFERMERO_H
#include "Empleado.h"

// Clase Enfermero que hereda de la clase base abstracta Empleado
class Enfermero : public Empleado {
public:
	Enfermero();
	Enfermero(string *id, string *nombre, string *cedula, double *salarioBase, int *departamentoId, int *horasNocturnas, double *bonoTurno);
	virtual ~Enfermero();
	
	void setHorasNocturnas(int *horasNocturnas);
	int getHorasNocturnas();
	void setBonoTurno(double *bonoTurno);
	double getBonoTurno();
	
	// Sobrescritura de metodos polimorficos
	double calcularSalarioNeto() override;
	string obtenerTipo() override;
	string toString() override;
	
	// Persistencia en archivo
	void autoGuardar(ofstream &estFile) override;
	static Enfermero* autoLeer(ifstream &estFile);
	
private:
	int *horasNocturnas;
	double *bonoTurno;
};

#endif
