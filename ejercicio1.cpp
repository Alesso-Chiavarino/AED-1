#include <iostream>
#include <fstream>
using namespace std;

struct datosEmpleado {
    string nombre;
    float sueldo;
};

void cargar() {
    int usuariosBajo = 0;
    int usuariosMedio = 0;
    int usuariosAlto = 0;
    int cantEmpleados;
    datosEmpleado listaEmpleados[3];
    ofstream archivo;

    archivo.open("registrosEmpleados.txt", ios::out | ios::app);
    if(archivo.fail()) {
        cout << "El archivo no se encontró \n"; 
    }

    cout << "Ingrese la cantidad de empleados que desea ingresar: " << endl;
    cin >> cantEmpleados;
    for(int i=0; i < cantEmpleados; i++) {
        cout << "Ingrese nombre" << endl;
        cin >> listaEmpleados[i].nombre;
        cout << "Ingrese sueldo" << endl;
        cin >> listaEmpleados[i].sueldo;

        //estadistica
        if((listaEmpleados[i].sueldo >= 1000 && listaEmpleados[i].sueldo <= 2000)) {
            usuariosBajo++;
        }
        if((listaEmpleados[i].sueldo >= 2001 && listaEmpleados[i].sueldo <= 3000)) {
            usuariosMedio++;
        }
        if((listaEmpleados[i].sueldo > 3000 && listaEmpleados[i].sueldo <= 5000)) {
            usuariosAlto++;
        }

        
        archivo << listaEmpleados[i].nombre << " ";
        archivo << listaEmpleados[i].sueldo;
        archivo << "\n";
    }
    cout << "Estadisticas de los empleados ingresados el dia de hoy:" << endl << endl;
    cout << "Empleados entre 1000 y 2000 pesos: " << usuariosBajo << endl;
    cout << "Empleados entre 2001 y 3000 pesos: " << usuariosMedio << endl;
    cout << "Empleados entre 3000 y 5000 pesos: " << usuariosAlto << endl;
    cout << "Total general de la empresa: " << usuariosAlto + usuariosMedio + usuariosBajo << endl;
}

int main() {

    cargar();
    system("PAUSE");
    return 0;
}
