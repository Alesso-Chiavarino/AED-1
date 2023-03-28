#include <iostream>
#include <vector>

using namespace std;

class Empleado {
    string nombre, fechaContratacion;
    double salario;
public:
    Empleado(string nombre, string fechaContratacion, double salario) {
        this->nombre = nombre;
        this->fechaContratacion = fechaContratacion;
        this->salario = salario;
    }
    string getNombre() {
        return nombre;
    }
    string getFechaContratacion() {
        return fechaContratacion;
    }
    double getSalario() {
        return salario;
    }
};

int main() {
    vector<Empleado> empleados;
    empleados.push_back(Empleado("Juan", "01/01/2010", 1000));
    empleados.push_back(Empleado("Pedro", "01/01/2011", 2000));
    for (int i = 0; i < empleados.size(); i++) {
        cout << "Empleado " << i + 1 << endl;
        cout << "Nombre: " << empleados[i].getNombre() << endl;
        cout << "Fecha de contratación: " << empleados[i].getFechaContratacion() << endl;
        cout << "Salario: " << empleados[i].getSalario() << endl;
        cout << endl;
    }
}