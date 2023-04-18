// 1. Haciendo uso de Listas enlazadas ingresamos y mostramos elementos en el programa. Esto nos permite tener una lista de elementos llamados nodos de forma organizada.

#include <iostream>
#include <list>

using namespace std;

int main()
{
    list<int> lista;
    int n;
    
    cout << "Ingrese el numero de elementos: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cout << "Ingrese el elemento " << i + 1 << ": ";
        cin >> x;
        lista.push_back(x);
    }

    cout << "Los elementos de la lista son: ";

    for (auto i = lista.begin(); i != lista.end(); i++) {
        cout << *i << " ";
    }

    cout << endl;
    return 0;
}