#include "Medico.h"
#include "Enfermero.h"
#include "Administrativo.h"
#include "ListaEmpleados.h"

using namespace std;

int main() {
	
	int menu = 0;
	
	// Punteros para la captura y gestion de datos ingresados por consola
	string *id = NULL;
	string *nombre = NULL;
	string *cedula = NULL;
	double *salarioBase = NULL;
	int *departamentoId = NULL;
	
	int *horasExtra = NULL;
	double *bonoGuardias = NULL;
	int *horasNocturnas = NULL;
	double *bonoTurno = NULL;
	double *incentivoProductividad = NULL;
	
	// Instanciacion dinamica de la lista de empleados y puntero polimorfico
	ListaEmpleados *lista = new ListaEmpleados();
	Empleado *emp = NULL;
	string ux; // Variable auxiliar para evaluar codigos de estado devueltos
	
	// Carga automatica desde el archivo de texto plano al iniciar el programa
	lista->cargarDesdeArchivo("empleados.txt");
	
	
	for(;;) {
		cout << "\n=================================================" << endl;
		cout << " SISTEMA DE PLANILLA HOSPITALARIA" << endl;
		cout << "=================================================" << endl;
		cout << "1. Insertar Medico" << endl;
		cout << "2. Insertar Enfermero" << endl;
		cout << "3. Insertar Administrativo" << endl;
		cout << "4. Consultar Empleado" << endl;
		cout << "5. Modificar Empleado" << endl;
		cout << "6. Eliminar Empleado" << endl;
		cout << "7. Listar Empleados" << endl;
		cout << "8. Salir" << endl;
		cout << "Opcion: ";
		cin >> menu;
		
		switch(menu) {
		case 1: { // Opcion para insertar un nuevo medico
			id = new string();
			nombre = new string();
			cedula = new string();
			salarioBase = new double;
			departamentoId = new int;
			horasExtra = new int;
			bonoGuardias = new double;
			
			cout << "\n--- INSERTAR MEDICO ---" << endl;
			cout << "Ingrese ID: "; cin >> *id;
			cout << "Ingrese Nombre: "; cin >> *nombre;
			cout << "Ingrese Cedula: "; cin >> *cedula;
			cout << "Ingrese Salario Base: "; cin >> *salarioBase;
			cout << "Ingrese Departamento ID: "; cin >> *departamentoId;
			cout << "Ingrese Horas Extra: "; cin >> *horasExtra;
			cout << "Ingrese Bono de Guardias: "; cin >> *bonoGuardias;
			
			// Creacion dinamica del objeto polimorfico e insercion (con autoguardado)
			emp = new Medico(id, nombre, cedula, salarioBase, departamentoId, horasExtra, bonoGuardias);
			lista->insertarEmpleado(emp);
			cout << "\nMedico agregado y guardado automaticamente en el archivo." << endl;
			break;
		}
		
		case 2: { // Opcion para insertar un nuevo enfermero
			id = new string();
			nombre = new string();
			cedula = new string();
			salarioBase = new double;
			departamentoId = new int;
			horasNocturnas = new int;
			bonoTurno = new double;
			
			cout << "\n--- INSERTAR ENFERMERO ---" << endl;
			cout << "Ingrese ID: "; cin >> *id;
			cout << "Ingrese Nombre: "; cin >> *nombre;
			cout << "Ingrese Cedula: "; cin >> *cedula;
			cout << "Ingrese Salario Base: "; cin >> *salarioBase;
			cout << "Ingrese Departamento ID: "; cin >> *departamentoId;
			cout << "Ingrese Horas Nocturnas: "; cin >> *horasNocturnas;
			cout << "Ingrese Bono de Turno: "; cin >> *bonoTurno;
			
			emp = new Enfermero(id, nombre, cedula, salarioBase, departamentoId, horasNocturnas, bonoTurno);
			lista->insertarEmpleado(emp);
			cout << "\nEnfermero agregado y guardado automaticamente en el archivo." << endl;
			break;
		}
		
		case 3: { // Opcion para insertar un nuevo administrativo
			id = new string();
			nombre = new string();
			cedula = new string();
			salarioBase = new double;
			departamentoId = new int;
			incentivoProductividad = new double;
			
			cout << "\n--- INSERTAR ADMINISTRATIVO ---" << endl;
			cout << "Ingrese ID: "; cin >> *id;
			cout << "Ingrese Nombre: "; cin >> *nombre;
			cout << "Ingrese Cedula: "; cin >> *cedula;
			cout << "Ingrese Salario Base: "; cin >> *salarioBase;
			cout << "Ingrese Departamento ID: "; cin >> *departamentoId;
			cout << "Ingrese Incentivo de Productividad: "; cin >> *incentivoProductividad;
			
			emp = new Administrativo(id, nombre, cedula, salarioBase, departamentoId, incentivoProductividad);
			lista->insertarEmpleado(emp);
			cout << "\nAdministrativo agregado y guardado automaticamente en el archivo." << endl;
			break;
		}
		
		case 4: { // Opcion para consultar empleado por numero de cedula
			cout << "\n--- CONSULTAR EMPLEADO ---" << endl;
			string *busCed = new string();
			cout << "Digite la cedula a consultar: "; cin >> *busCed;
			ux = lista->consultarEmpleado(*busCed);
			delete busCed;
			
			if(ux == "0") {
				cout << "El registro esta vacio." << endl;
			} else if(ux == "-1") {
				cout << "Error: No existe dicho empleado." << endl;
			} else {
				cout << "\nDatos del empleado:\n" << ux << endl;
			}
			break;
		}
		
		case 5: { // Opcion para modificar un empleado existente
			cout << "\n--- MODIFICAR EMPLEADO ---" << endl;
			string *busCed = new string();
			cout << "Digite la cedula del empleado a modificar: "; cin >> *busCed;
			if(lista->consultarEmpleado(*busCed) == "0") {
				cout << "El registro esta vacio." << endl;
				delete busCed;
			} else if(lista->consultarEmpleado(*busCed) == "-1") {
				cout << "Error: No existe un empleado con esa cedula." << endl;
				delete busCed;
			} else {
				id = new string();
				nombre = new string();
				salarioBase = new double;
				departamentoId = new int;
				horasExtra = new int;
				bonoGuardias = new double;
				
				cout << "Ingrese nuevo ID: "; cin >> *id;
				cout << "Ingrese nuevo Nombre: "; cin >> *nombre;
				cout << "Ingrese nuevo Salario Base: "; cin >> *salarioBase;
				cout << "Ingrese nuevo Departamento ID: "; cin >> *departamentoId;
				cout << "Ingrese nuevas Horas Extra (o 0): "; cin >> *horasExtra;
				cout << "Ingrese nuevo Bono Guardias (o 0): "; cin >> *bonoGuardias;
				
				emp = new Medico(id, nombre, busCed, salarioBase, departamentoId, horasExtra, bonoGuardias);
				lista->modificarEmpleado(*busCed, emp);
				cout << "\nEmpleado modificado y actualizado automaticamente en el archivo." << endl;
			}
			break;
		}
		
		case 6: { // Opcion para eliminar un empleado por cedula
			cout << "\n--- ELIMINAR EMPLEADO ---" << endl;
			string *busCed = new string();
			cout << "Digite la cedula a eliminar: "; cin >> *busCed;
			ux = lista->eliminarEmpleado(*busCed);
			delete busCed;
			
			if(ux == "0") {
				cout << "El registro esta vacio." << endl;
			} else if(ux == "-1") {
				cout << "Error: No existe dicho empleado." << endl;
			} else {
				cout << "Empleado eliminado y archivo actualizado automaticamente." << endl;
			}
			break;
		}
		
		case 7: { // Opcion para listar todos los empleados registrados
			cout << "\n--- LISTA DE EMPLEADOS ---" << endl;
			ux = lista->listarEmpleados();
			if(ux == "0") {
				cout << "El registro esta vacio." << endl;
			} else {
				cout << ux << endl;
			}
			break;
		}
		
		case 8: { // Opcion para salir del programa liberando memoria
			delete lista;
			cout << "\nSaliendo del sistema..." << endl;
			exit(0);
		}
		
		default:
			cout << "\nOpcion invalida, intente de nuevo." << endl;
			break;
		}
	}
	
	return 0;
}
