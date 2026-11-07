#ifndef ADMINISTRATIVO_H
#define ADMINISTRATIVO_H
#include "Empleado.h"

// Clase Administrativo que hereda de la clase base abstracta Empleado[cite: 32]
class Administrativo : public Empleado {
public:
	Administrativo();
	Administrativo(string *id, string *nombre, string *cedula, double *salarioBase, int *departamentoId, double *incentivoProductividad);
	virtual ~Administrativo();
	
	void setIncentivoProductividad(double *incentivoProductividad);
	double getIncentivoProductividad();
	
	// Sobrescritura de metodos polimorficos
	double calcularSalarioNeto() override;
	string obtenerTipo() override;
	string toString() override;
	
	// Persistencia en archivo
	void autoGuardar(ofstream &estFile) override;
	static Administrativo* autoLeer(ifstream &estFile);
	
private:
	double *incentivoProductividad;
};

#endif
