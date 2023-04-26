#include <iostream>
#include <list>

using namespace std;

void insertFront(list<int>& lista) {
	int element;
    int cant_element = 0;
    cout << "Ingrese cantidad de elementos a ingresar: " << endl;
    cin >> cant_element;

    for(int i = 0; i < cant_element; i++) {
        cout << "Ingrese el elemento " << i + 1 << ": ";
        cin >> element;
        lista.push_front(element);
    }

    cout << "Elementos agregados correctamente!" << endl;
}

void insertBack(list<int>& lista) {
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

void insertInPosition(list<int>& lista) {
    int position;
    int element;
    cout << "Ingrese la posición donde desea insertar el elemento: ";
    cin >> position;
    cout << "Ingrese el elemento: ";
    cin >> element;
    for(int i = 0; i < position; i++) {
        lista.pop_front();
    }
    lista.push_front(element);
    cout << "Elemento agregado correctamente!" << endl;
}

void printList(list<int>& lista) {
    cout << "Elementos de la lista: " << endl;
    for(int element : lista) {
        cout << element << " ";
    }
    cout << endl;
}

void sumElements(list<int>& lista) {
    int sum = 0;
    for(int element : lista) {
        sum += element;
    }
    cout << "La suma de los elementos es: " << sum << endl;
}

int main() {

	 list<int> lista;

	 do {
        int option;
        cout << "1. Insertar al inicio" << endl;
        cout << "2. Insertar al final" << endl;
        cout << "3. Insertar en posición" << endl;
        cout << "4. Imprimir lista" << endl;
        cout << "5. Sumar elementos" << endl;
        cout << "6. Salir" << endl;
        cout << "Ingrese una opción: ";
        cin >> option;

        switch(option) {
            case 1:
                insertFront(lista);
                break;
            case 2:
                insertBack(lista);
                break;
            case 3:
                insertInPosition(lista);
                break;
            case 4:
                printList(lista);
                break;
            case 5:
                sumElements(lista);
                break;
            case 6:
                return 0;
            default:
                cout << "Opción inválida!" << endl;
                break;
        }
    } while(true);

    return 0;
}