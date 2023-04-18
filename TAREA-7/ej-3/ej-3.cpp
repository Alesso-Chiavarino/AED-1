#include <iostream>
#include <list>

using namespace std;

int main() {
    list<int> lista;
    int elements_num;
    int element;
    cout << "Ingrese el numero de elementos: ";
    cin >> elements_num;

    for (int i = 0; i < elements_num; i++) {
        int element;
        cout << "Ingrese el elemento " << i + 1 << ": ";
        cin >> element;
        lista.push_back(element);
    }

    cout << "Los elementos de la lista son: ";

    for (auto i = lista.begin(); i != lista.end(); i++) {
        cout << *i << " ";
    }

    cout << endl;

    int element_num;
    char option;
    
    //elimino primer e de la lista
    lista.pop_front();
    
    cout << "Los elementos de la lista son: " <<endl;

    for (auto i = lista.begin(); i != lista.end(); i++) {
        cout << *i << " ";
    }

    cout << "Ingrese elemento a insertar al inicio: " <<endl;
    cin >> element;
    lista.push_front(element);

    cout << "Los elementos de la lista son: ";

    for (auto i = lista.begin(); i != lista.end(); i++) {
        cout << *i << " ";
    }

    //calcula promedio
    int sum = 0;
    float average;
    for (auto i = lista.begin(); i != lista.end(); i++) {
        sum += *i;
    }
    average = sum / lista.size();
    cout << "El promedio de la lista es: " << average << endl;

    cout << "Ingrese el elemento a buscar: " << endl;
    for(auto i = lista.begin(); i != lista.end(); i++) {
        if (*i == element) {
            cout << "El elemento " << element << " se encuentra en la lista" << endl;
        }
    }

    return 0;
}