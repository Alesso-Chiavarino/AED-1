#include <iostream>
#include <list>

// Un programa que permita al usuario ingresar una lista de números enteros y, a continuación, elimine de la lista todos los números pares.

using namespace std;

void mostrarLista(list<int> lista) {
    list<int>::iterator it;
    for (it = lista.begin(); it != lista.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

int main() {
    list<int> lista;
    lista.push_front(2);
    lista.push_front(1);
    lista.push_back(4);
    lista.push_back(3);
    mostrarLista(lista);
    list<int>::iterator it = lista.begin();

    //delete par
    it = lista.begin();
    while (it != lista.end()) {
        if (*it % 2 == 0) {
            it = lista.erase(it);
        } else {
            it++;
        }
    }
    mostrarLista(lista);

    return 0;
}