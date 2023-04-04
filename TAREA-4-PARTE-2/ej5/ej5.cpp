#include <iostream>

using namespace std;

class Estudiante {
    private: 
        string nombre;
        int edad;
        float nota;
    public:
        int getNota() {
            return nota;
        }

};

class Grupo {
    private:
        Estudiante estudiantes[10];
    public:
        float promedio() {
            float suma = 0;
            for (int i = 0; i < 10; i++) {
                suma += estudiantes[i].getNota();
            }
            return suma / 10;
        }
};

int main() {
    Grupo grupo;

    cout << "El promedio del grupo es: " << grupo.promedio() << endl;

    return 0;
}
