#include "Departamento.h"

Departamento::Departamento() {
	codigo = new int;
	nombreArea = new string();
}

Departamento::Departamento(int *codigo, string *nombreArea) {
	this->codigo = codigo;
	this->nombreArea = nombreArea;
}

Departamento::~Departamento() {
	delete codigo;
	delete nombreArea;
}

void Departamento::setCodigo(int *codigo) {
	this->codigo = codigo;
}

int Departamento::getCodigo() {
	return *codigo;
}

void Departamento::setNombreArea(string *nombreArea) {
	this->nombreArea = nombreArea;
}

string Departamento::getNombreArea() {
	return *nombreArea;
}

string Departamento::toString() {
	stringstream x;
	x << "Codigo Departamento: " << *codigo << endl;
	x << "Area: " << *nombreArea << endl;
	return x.str();
}

void Departamento::autoGuardar(ofstream &estFile) {
	estFile << *codigo << endl
		<< *nombreArea << endl;
}

Departamento* Departamento::autoLeer(ifstream &estFile) {
	int *cod = new int;
	string *area = new string();
	
	if (!(estFile >> *cod)) { delete cod; delete area; return NULL; }
	if (!(estFile >> *area)) { delete cod; delete area; return NULL; }
	
	return new Departamento(cod, area);
}
