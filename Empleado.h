#ifndef EMPLEADO_H
#define EMPLEADO_H
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

// Clase base abstracta que representa a un empleado general del hospital
class Empleado {
public:
	// Constructor por defecto
	Empleado();
	
	// Constructor con parametros
	Empleado(string *id, string *nombre, string *cedula, double *salarioBase, int *departamentoId);
	
	// Destructor virtual para garantizar la correcta liberacion de clases hijas
	virtual ~Empleado();
	
	
	void setId(string *id);
	void setNombre(string *nombre);
	void setCedula(string *cedula);
	void setSalarioBase(double *salarioBase);
	void setDepartamentoId(int *departamentoId);
	
	
	string getId();
	string getNombre();
	string getCedula();
	double getSalarioBase();
	int getDepartamentoId();
	
	// Metodos virtuales puros para el polimorfismo
	virtual double calcularSalarioNeto() = 0;
	virtual string obtenerTipo() = 0;
	
	// Metodo toString virtual para concatenar la informacion
	virtual string toString();
	
	// Metodo virtual para guardar los datos en un archivo de texto plano
	virtual void autoGuardar(ofstream &estFile);
	
protected:
	// Atributos protegidos declarados como punteros
	string *id;
	string *nombre;
	string *cedula;
	double *salarioBase;
	int *departamentoId;
};

#endif
