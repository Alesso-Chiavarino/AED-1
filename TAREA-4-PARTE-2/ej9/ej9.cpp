#include <iostream>

using namespace std;

class Persona {
    private:
        string nombre;
        string genero;
        int edad;
};

class Trabajador {
    private:
        Persona persona;
        float salario;
        int horasDiarias;
    public:
        float calcularSalario() {
            return salario * horasDiarias;
        }
};

int main() {
    Trabajador trabajador;
    cout << trabajador.calcularSalario() << endl;
    return 0;
} 