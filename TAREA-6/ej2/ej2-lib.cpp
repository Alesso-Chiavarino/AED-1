#include <iostream>
#include <list>
#include <string>

using namespace std;

class Estudiante {
    private:
        string nombre;
        int edad;
        string carrera;
    public: 
        Estudiante(string nombre, int edad, string carrera) {
            this->nombre = nombre;
            this->edad = edad;
            this->carrera = carrera;
        }
        string getNombre() {
            return this->nombre;
        }
        int getEdad() {
            return this->edad;
        }
        string getCarrera() {
            return this->carrera;
        }
};

list<Estudiante> lista;

void mostrarLista() {
    list<Estudiante>::iterator it;
    for (it = lista.begin(); it != lista.end(); it++) {
        cout << it->getNombre() << " ";
        cout << it->getEdad() << " ";
        cout << it->getCarrera() << " ";
    }
    cout << endl;
}

void addStudentToList() {
    string nombre;
    int edad;
    string carrera;
    cout << "Ingrese el nombre del estudiante: ";
    cin >> nombre;
    cout << "Ingrese la edad del estudiante: ";
    cin >> edad;
    cout << "Ingrese la carrera del estudiante: ";
    cin >> carrera;
    Estudiante estudiante(nombre, edad, carrera);
    lista.push_back(estudiante);
}

void deleteStudentFromList() {
    string nombre;
    cout << "Ingrese el nombre del estudiante a eliminar: ";
    cin >> nombre;
    list<Estudiante>::iterator it = lista.begin();
    while (it != lista.end()) {
        if (it->getNombre() == nombre) {
            it = lista.erase(it);
        } else {
            it++;
        }
    }
}

void searchStudentFromName() {
    string nombre;
    cout << "Ingrese el nombre del estudiante a buscar: ";
    cin >> nombre;
    list<Estudiante>::iterator it = lista.begin();
    while (it != lista.end()) {
        if (it->getNombre() == nombre) {
            cout << "Nombre: " << it->getNombre() << endl;
            cout << "Edad: " << it->getEdad() << endl;
            cout << "Carrera: " << it->getCarrera() << endl;
            break;
        } else {
            it++;
        }
    }
}

void menu() {
    cout << "1. Agregar estudiante" << endl;
    cout << "2. Eliminar estudiante" << endl;
    cout << "3. Buscar estudiante" << endl;
    cout << "4. Listar estudiantes" << endl;
    cout << "5. Salir" << endl;
    cout << "Ingrese una opcion: ";
    int opcion;
    cin >> opcion;
    switch (opcion) {
        case 1:
            addStudentToList();
            break;
        case 2:
            deleteStudentFromList();
            break;
        case 3:
            searchStudentFromName();
            break;
        case 4:
            mostrarLista();
            break;
        case 5:
            exit(0);
            break;
        default:
            cout << "Opcion invalida" << endl;
            break;
    }
}

int main() {
    while (true) {
        menu();
    }

    return 0;
}
