#include <iostream>
#include <vector>

using namespace std;

class Persona {
    string nombre, direccion;
    int edad;
public:
    Persona(string nombre, string direccion, int edad) {
        this->nombre = nombre;
        this->direccion = direccion;
        this->edad = edad;
    }
    string getNombre() {
        return nombre;
    }
    string getDireccion() {
        return direccion;
    }
    int getEdad() {
        return edad;
    }
};


int main() {
    vector<Persona> personas;
    personas.push_back(Persona("Juan", "Calle 1", 20));
    personas.push_back(Persona("Pedro", "Calle 2", 30));
    personas.push_back(Persona("Maria", "Calle 3", 40));
    personas.push_back(Persona("Jose", "Calle 4", 50));
}