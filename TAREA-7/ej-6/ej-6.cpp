#include <iostream>
#include <list>

using namespace std;

void searchElement(list<int>& lista) {
    int element;
    cout << "Ingrese elemento a buscar: " << endl;
    cin >> element;

    for(auto i = lista.begin(); i != lista.end(); i++) {
        if(*i == element) {
            cout << "El elemento es: " << *i << endl;
        }
    }

}

void printList(list<int>& lista) {
    for(auto i = lista.begin(); i != lista.end(); i++) {
        cout << *i << " ";
    }
}

void invertList(list<int>& lista) {
    lista.reverse();
    cout << "Lista invertida: " << endl;
    printList(lista);
}

void printCentralElement(list<int>& lista) {
    int size = lista.size();
    auto i = lista.begin();
    advance(i, size / 2); // avanzo hasta la mitad de la lista
    cout << "Elemento central: " << *i << endl;
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

    list<int> lista;

    do {
        cout << "1. Insertar elemento" << endl;
        cout << "2. Buscar elemento" << endl;
        cout << "3. Invertir lista" << endl;
        cout << "4. Mostrar elemento central " << endl;
        cout << "5. Salir" << endl;
        cout << "Ingrese una opción: " << endl;
        int op;
        cin >> op;
        switch(op) {
            case 1: {
                insertElement(lista);
                break;
            }
            case 2: {
                searchElement(lista);
                break;
            }
            case 3: {
                invertList(lista);
                break;
            }
            case 4: {
                printCentralElement(lista);
                break;
            }
            case 5: {
                return 0;
            }
            default: {
                cout << "Ingrese una opción correcta" << endl;
                break;
            }
        }

    } while (true);

    return 0;
} 