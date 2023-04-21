// 7. Mediante programación en C++, Hacer un programa que permita multiplicar los elementos de una lista.

#include <iostream>
#include <list>

using namespace std;

void multiplyElements(list<int>& lista) {

    int prevElement = lista.front();
    auto i = lista.begin();
    i++;

    for(; i != lista.end(); i++) {
        int currentElement = *i;
        *i = currentElement * prevElement;
        prevElement = currentElement;
    }

    cout << "Multiplicacion" << *i << endl;

}


void printList(list<int>& lista) {
    for(auto i = lista.begin(); i != lista.end(); i++) {
        cout << *i << " ";
    }
}

void insertElement(list<int>& lista) {
    int element;
    int cant_element = 0;
    cout << "Ingrese cantidad de elementos a ingresar: " << endl;
    cin >> cant_element;

    for(int i = 0; i < cant_element; i++) {
        cout << "Ingrese el elemento " << i + 1 << ": ";
        cin >> element;
        lista.push_back(element);
    }

    cout << "Elementos agregados correctamente!" << endl;
}

int main() {

    do {
        cout << "1. Insertar elementos" << endl;
        cout << "2. Multiplicar elementos" << endl;
        cout << "3. Imprimir lista" << endl;
        cout << "4. Salir" << endl;

        int option;
        cin >> option;

        list<int> lista;

        switch(option) {
            case 1: {
                insertElement(lista);
                break;
            }
            case 2: {
                multiplyElements(lista);
                break;
            }
            case 3: {
                printList(lista);
                break;
            }
            case 4:
                return 0;
            default:
                    {
                        cout << "Opción invalida" << endl;
                    }
        }

    } while(true);

    return 0;
}