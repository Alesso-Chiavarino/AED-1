#include <iostream>
#include <list>

using namespace std;

void insertElementsInList(list<int> &lista) {

    int elements_num;
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
}

void deleteElementOfList(list<int> &lista) {
    int element_num;
    char option;
    
    cout << "Eliminar elemento en particular (p) o eliminar elemento al inicio (i) o al final (f):" <<endl;
    if (option == 'p') {
        cout << "Ingrese el numero de elemento a eliminar: ";
        cin >> element_num;
        return lista.remove(element_num);
    }
    if (option == 'i') {
        return lista.pop_front();
    }
    if (option == 'f') {
        return lista.pop_back();
    }
    
}

void removeList(list<int> &lista) {
    return lista.clear();
}

void removeRepeatedNumbers(list<int> &lista) {
    return lista.unique(); //unique elimina los elementos repetidos
}

void removeParNumbers(list<int> &lista) {
    return lista.remove_if([](int n) { return n % 2 == 0; });
}

int calculateMedia(list<int> &lista) {
    int sum = 0;
    float media = 0.0;

    for (auto i = lista.begin(); i != lista.end(); i++) {
        sum += *i;
    }

    media = sum / lista.size();

    cout << "La media es: " << media << endl;
}

void calculateMayor(list<int> &lista) {
    int mayor = 0;

    for(auto i = lista.begin(); i != lista.end(); i++) {
        if (*i > mayor) {
            mayor = *i;
        }
    }

    cout << "El elemento mayor es:" << mayor << endl;
}

void calculateMinor(list<int> &lista) {

    int menor = 0;

    for(auto i = lista.begin(); i != lista.end(); i++) {
        if (*i < menor) {
            menor = *i;
        }
    }

    cout << "El elemento menor es:" << menor << endl;
}

void listPrimes(list<int> &lista) {
    for (auto i = lista.begin(); i != lista.end(); i++) {
        int cont = 0;
        for (int j = 1; j <= *i; j++) {
            if (*i % j == 0) {
                cont++;
            }
        }
        if (cont == 2) {
            cout << *i << " ";
        }
    }
}

void orderElements(list<int> &lista) {
    return lista.sort();
}

void listElement(list<int> &lista) {
    int element;
    cout << "Ingrese el elemento a buscar: ";
    cin >> element;
    
    for(auto i = lista.begin(); i != lista.end(); i++) {
        if (*i == element) {
            cout << "El elemento " << element << " se encuentra en la lista" << endl;
        } else {
            cout << "El elemento " << element << " no se encuentra en la lista" << endl;
        }
    }
}

void invertedList(list<int> &lista) {
    for (auto i = lista.rbegin(); i != lista.rend(); i++) {
        cout << *i << " ";
    }
}

void printList(list<int> &lista) {
    for (auto i = lista.begin(); i != lista.end(); i++) {
        cout << *i << " ";
    }
}

int main() {
    list<int> lista;
    do {
        cout << "1. Insertar elementos a la lista" << endl;
        cout << "2. Eliminar elementos de la lista" << endl;
        cout << "3. Eliminar lista" << endl;
        cout << "4. Eliminar numeros repetidos" << endl;
        cout << "5. Eliminar numeros pares" << endl;
        cout << "6. Calcular media" << endl;
        cout << "7. Calcular mayor" << endl;
        cout << "8. Calcular menor" << endl;
        cout << "9. Listar numeros primos" << endl;
        cout << "10. Ordenar elementos" << endl;
        cout << "11. Buscar elemento" << endl;
        cout << "12. Listar elementos en orden inverso" << endl;
        cout << "13. Listar elementos" << endl;
        cout << "14. Salir" << endl;
        cout << "Ingrese una opcion: ";
        int opcion;
        cin >> opcion;
        
        switch (opcion) {
        case 1: {
            insertElementsInList(lista);
            break;
        }
        case 2: {
            deleteElementOfList(lista);
            break;
        }
        case 3: {
            removeList(lista);
            break;
        }
        case 4: {
            removeRepeatedNumbers(lista);
            break;
        }
        case 5: {
            removeParNumbers(lista);
            break;
        }
        case 6: {
            calculateMedia(lista);
            break;
        }
        case 7: {
            calculateMayor(lista);
            break;
        }
        case 8: {
            calculateMinor(lista);
            break;
        }
        case 9: {
            listPrimes(lista);
            break;
        }
        case 10: {
            orderElements(lista);
            break;
        }
        case 11: {
            listElement(lista);
            break;
        }
        case 12: {
            invertedList(lista);
            break;
        }
        case 13: {
            printList(lista);
            break;
        }
        case 14: {
            return 0;
        }
        default:
            break;
        }
    } while (true);
}