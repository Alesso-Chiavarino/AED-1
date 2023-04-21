#include <iostream>
#include <list>

using namespace std;

void insertElement(list<int>& lista) {
    int elements_num;
    cout << "Ingrese el numero de elementos: ";
    cin >> elements_num;

    for (int i = 0; i < elements_num; i++) {
        int element;
        cout << "Ingrese el elemento " << i + 1 << ": ";
        cin >> element;
        lista.push_back(element);
    }

    cout << "Elementos agregados correctamente!" << endl;
}

void mergeList(list<int>& lista1, list<int>& lista2) {
    // Une las listas y muestra los elementos
    lista1.splice(lista1.end(), lista2);
    cout << "Lista unida: ";
    for (auto i = lista1.begin(); i != lista1.end(); i++) {
        cout << *i << " ";
    }
    cout << endl;
}

void printList(const list<int>& lista) {
    for (auto i = lista.begin(); i != lista.end(); i++) {
        cout << *i << " ";
    }
    cout << endl;
}

int main() {
    list<int> lista1, lista2;

    do {
        cout << "1. Insertar elementos a la lista" << endl;
        cout << "2. Unir listas" << endl;
        cout << "3. Mostrar elementos de la lista" << endl;
        cout << "4. Salir" << endl;
        cout << "Ingrese una opcion: ";
        int op;
        cin >> op;

        switch (op) {
            case 1: {
                int list_num;
                cout << "Ingrese lista a utilizar, 1ºlista (1), 2ºlista (2): ";
                cin >> list_num;
                if (list_num == 1) {
                    insertElement(lista1);
                } else if (list_num == 2) {
                    insertElement(lista2);
                } else {
                    cout << "La lista numero " << list_num << " no existe" << endl;
                }
                break;
            }
            case 2: {
                mergeList(lista1, lista2);
                break;
            }
            case 3: {
                int list_num;
                cout << "Ingrese lista a utilizar, 1ºlista (1), 2ºlista (2): ";
                cin >> list_num;
                if (list_num == 1) {
                    printList(lista1);
                } else if (list_num == 2) {
                    printList(lista2);
                } else {
                    cout << "La lista numero " << list_num << " no existe" << endl;
                }
                break;
            }
            case 4: {
                return 0;
            }
            default:
                cout << "Opcion invalida" << endl;
                break;
        }
    } while (true);

    return 0;
}
