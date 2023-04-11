// Un programa que cree una lista de tareas y permita al usuario agregar nuevas tareas, eliminar tareas completadas y mostrar todas las tareas pendientes.

#include <iostream>
#include <list>

using namespace std;

void showList(list<string> lista) {
    list<string>::iterator it;
    for (it = lista.begin(); it != lista.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

void addTaskToList(list<string> &lista) {
    string task;
    cout << "Ingrese una tarea: ";
    cin.ignore();
    getline(cin, task);
    lista.push_back(task);
}

void deleteTaskFromList(list<string> &lista) {
    string task;
    cout << "Ingrese la tarea a eliminar: ";
    cin.ignore();
    getline(cin, task);
    list<string>::iterator it = lista.begin();
    while (it != lista.end()) {
        if (*it == task) {
            it = lista.erase(it);
        } else {
            it++;
        }
    }
}

int main() {
    list<string> lista;
    int opcion;
    do {
        cout << "1. Agregar tarea" << endl;
        cout << "2. Mostrar lista" << endl;
        cout << "3. Eliminar tarea completada" << endl;
        cout << "4. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        switch (opcion) {
            case 1:
                addTaskToList(lista);
                break;
            case 2:
                showList(lista);
                break;
            case 3:
                deleteTaskFromList(lista);
                break;
            case 4:
                cout << "Adios" << endl;
                break;
            default:
                cout << "Opcion invalida" << endl;
                break;
        }
    } while (opcion != 4);
    return 0;
}