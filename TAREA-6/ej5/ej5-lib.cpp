// Un programa que permita al usuario ingresar una lista de nombres y luego muestre los nombres en orden inverso.

#include <iostream>
#include <list>
#include <string>

using namespace std;

void showList(list<string> lista) {
    list<string>::iterator it;
    for (it = lista.begin(); it != lista.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

void showNameInReverseOrder(list<string> lista) {
    lista.reverse();
    showList(lista);
}

void addNameToList(list<string> &lista) {
    string name;
    cout << "Ingrese un nombre: ";
    cin.ignore();
    getline(cin, name);
    lista.push_back(name);
}

void deleteTaskFromList(list<string> &lista) {
    string name;
    cout << "Ingrese un nombre a eliminar: ";
    cin.ignore();
    getline(cin, name);
    list<string>::iterator it = lista.begin();
    while (it != lista.end()) {
        if (*it == name) {
            it = lista.erase(it);
        } else {
            it++;
        }
    }
}

int main() {
    list<string> lista;
    int opcion;
    do {
        cout << "1. Agregar nombre" << endl;
        cout << "2. Mostrar lista" << endl;
        cout << "3. Mostrar lista en orden inverso" << endl;
        cout << "4. Eliminar nombre" << endl;
        cout << "5. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        switch (opcion) {
            case 1:
                addNameToList(lista);
                break;
            case 2:
                showList(lista);
                break;
            case 3:
                showNameInReverseOrder(lista);
                break;
            case 4:
                deleteTaskFromList(lista);
                break;
            case 5:
                cout << "Adios" << endl;
                break;
            default:
                cout << "Opcion invalida" << endl;
        }
    } while (opcion != 5);
}