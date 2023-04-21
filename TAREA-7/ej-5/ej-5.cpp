#include <iostream>
#include <list>

using namespace std;

void insertElementFront(list<int>& lista) {
    int elements_cant = 0;
    cout << "Cantidad de elementos a ingresar: " << endl;
    cin >> elements_cant;
    

    for(int i=0; i<elements_cant; i++) {
        int element;
        cout << "Ingrese el elemento " << i + 1 << ": ";
        cin >> element;
        lista.push_front(element);
    }
}

void removeElementFront(list<int>& lista) {
    lista.pop_front();
    cout << "Elemento del inicio eliminado correctamente!" << endl;
}

void removeElementBack(list<int>& lista) {
    lista.pop_back();
    cout << "Elemento del final eliminado correctamente!" << endl;
}

void removeAll(list<int>& lista) {
    lista.clear();
}

void printPar(list<int>& lista) {
    cout << "numeros pares:" << endl;
    for(auto i = lista.begin(); i != lista.end(); i++) {
        if(*i % 2 == 0) {
            cout << *i << " ";
        } 
    }
}

void printImpar(list<int>& lista) {
    cout << "numeros impares:" << endl;
    for(auto i = lista.begin(); i != lista.end(); i++) {
        if(*i % 2 != 0) {
            cout << *i << " ";
        } 
    }
}

int main() {

    list<int> lista;

    do {
        cout << "1. Ingresar elemento al inicio de la lista";
        cout << "2. Eliminar elemento al inicio de la lista";
        cout << "3. Eliminar elemento al final de la lista";
        cout << "4. Eliminar todos los elementos de la lista";
        cout << "5. Mostrar los elementos pares de la lista";
        cout << "6. Mostrar los elementos impares de la lista";
        cout << "Ingrese una opcion: ";
        int op;
        cin >> op;

        switch(op) {
            case 1: {
                insertElementFront(lista);
                break;
            }
            case 2: {
                removeElementFront(lista);
                break;
            }
            case 3: {
                removeElementBack(lista);
                break;
            }
            case 4: {
                removeAll(lista);
                break;
            } 
            case 5: {
                printPar(lista);
                break;
            }
            case 6: {
                printImpar(lista);
                break;
            }
            default: {
                cout << "Opcion invalida" << endl;
                break;
            }
        }
    } while (true);

    return 0;
}