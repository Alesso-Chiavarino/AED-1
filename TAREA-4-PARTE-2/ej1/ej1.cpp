#include <iostream>
#include <string>

using namespace std;

class Persona {
    private:
        string nombre;
        int edad;
        string genero;
        string direccion;
        string telefono;
    public:
        Persona(string nombre, int edad, string genero, string direccion, string telefono) {
            this->nombre = nombre;
            this->edad = edad;
            this->genero = genero;
            this->direccion = direccion;
            this->telefono = telefono;
        }
        string getNombre() {
            return nombre;
        }
        int getEdad() {
            return edad;
        }
        string getGenero() {
            return genero;
        }
        string getDireccion() {
            return direccion;
        }
        string getTelefono() {
            return telefono;
        }
        void setNombre(string nombre) {
            this->nombre = nombre;
        }
        void setEdad(int edad) {
            this->edad = edad;
        }
        void setGenero(string genero) {
            this->genero = genero;
        }
        void setDireccion(string direccion) {
            this->direccion = direccion;
        }
        void setTelefono(string telefono) {
            this->telefono = telefono;
        }
};

class Empleado : public Persona {
    private:
        double salario;
        string cargo;
    public:
        Empleado(string nombre, int edad, string genero, string direccion, string telefono, double salario, string cargo) : Persona(nombre, edad, genero, direccion, telefono) {
            this->salario = salario;
            this->cargo = cargo;
        }
        double getSalario() {
            return salario;
        }
        string getCargo() {
            return cargo;
        }
        void setSalario(double salario) {
            this->salario = salario;
        }
        void setCargo(string cargo) {
            this->cargo = cargo;
        }
};

int main() {
    Empleado empleado("Juan", 20, "Masculino", "Calle 1", "123456789", 1000, "Programador");
    cout << "Nombre: " << empleado.getNombre() << endl;
    cout << "Edad: " << empleado.getEdad() << endl;
    cout << "Género: " << empleado.getGenero() << endl;
    cout << "Dirección: " << empleado.getDireccion() << endl;
    cout << "Teléfono: " << empleado.getTelefono() << endl;
    cout << "Salario: " << empleado.getSalario() << endl;
    cout << "Cargo: " << empleado.getCargo() << endl;
    return 0;
}