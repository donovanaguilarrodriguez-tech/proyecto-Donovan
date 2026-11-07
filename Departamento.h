#ifndef DEPARTAMENTO_H
#define DEPARTAMENTO_H
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

// Clase Departamento que gestiona su informacion institucional
class Departamento {
public:
	Departamento();
	Departamento(int *codigo, string *nombreArea);
	virtual ~Departamento();
	
	void setCodigo(int *codigo);
	int getCodigo();
	void setNombreArea(string *nombreArea);
	string getNombreArea();
	
	string toString();
	void autoGuardar(ofstream &estFile);
	static Departamento* autoLeer(ifstream &estFile);
	
private:
	int *codigo;
	string *nombreArea;
};

#endif
