// Un programa que permita al usuario ingresar una lista de palabras y luego muestre las palabras ordenadas alfabéticamente.

#include <iostream>
#include <list>
#include <string>
#include <vector>

using namespace std;

void mostrarLista(list<string> lista) {
    list<string>::iterator it;
    for (it = lista.begin(); it != lista.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

void addWordToList(list<string> &lista) {
    string palabra;
    cout << "Ingrese una palabra: ";
    cin >> palabra;
    lista.push_back(palabra);
}

void orderWordAlphabetically(list<string> &lista) {
    lista.sort();
}

int main() {
    list<string> lista;
    int opcion;
    do {
        cout << "1. Agregar palabra" << endl;
        cout << "2. Mostrar lista" << endl;
        cout << "3. Ordenar lista" << endl;
        cout << "4. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        switch (opcion) {
            case 1:
                addWordToList(lista);
                break;
            case 2:
                mostrarLista(lista);
                break;
            case 3:
                orderWordAlphabetically(lista);
                break;
            case 4:
                cout << "Adios" << endl;
                break;
            default:
                cout << "Opcion invalida" << endl;
                break;
        }
    } while (opcion != 4);
    return 0;
}