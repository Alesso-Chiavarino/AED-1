// 9. Hacer un programa que permita ingresar dos listas, el programa debe mostrar las dos listas, intercalar la dos listas en una tercera lista, y debe calcular la resta de ambas listas y el resultado mostrarlo en una tercera lista.

#include <iostream>
#include <list>

using namespace std;

void insertElements(list<int>& lista) {
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

void printList(list<int>& lista) {
    cout << "Elementos de la lista: " << endl;
    for(int element : lista) {
        cout << element << " ";
    }
    cout << endl;
}

void intercalarListas(list<int>& lista1, list<int>& lista2, list<int>& lista3) {
    int i = 0;
    for(int element : lista1) {
        lista3.push_back(element);
        lista3.push_back(lista2.front());
        lista2.pop_front();
    }
}

void restaListas(list<int>& lista1, list<int>& lista2, list<int>& lista3) {
    int i = 0;
    for(int element : lista1) {
        lista3.push_back(element - lista2.front());
        lista2.pop_front();
    }
}

int main() {
    list<int> lista1;
    list<int> lista2;
    list<int> lista3;

    insertElements(lista1);
    insertElements(lista2);

    printList(lista1);
    printList(lista2);

    intercalarListas(lista1, lista2, lista3);
    printList(lista3);

    restaListas(lista1, lista2, lista3);
    printList(lista3);

    return 0;
}

