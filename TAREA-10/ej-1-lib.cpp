// Unir pilas C++: A través de la programación en C++, desarrollaremos un programa haciendo uso de Pilas, donde nos permita apilar y unir pilas. El programa consistirá en crear un menú con 4 opciones que incluya las ya mencionadas (apilar, ver, unir pilas y salir).

#include <iostream>
#include <stack>
#include <string>

using namespace std;

void pushStack(stack<string> stack1) {
    string dato;
    cout << "Ingrese un dato: ";
    cin >> dato;
    stack1.push(dato);
}

void showStack(stack<string> stack) {
    cout << stack.size();
    for(int i = 0; i < stack.size(); i++) {
        cout << "hola";
    }
}

void joinStack(stack<string> stack1, stack<string> stack2) {
    for(auto i = 0; i < stack1.size(); i++) {
        stack2.push(stack1.top());
        stack1.pop();
    }
    showStack(stack2);
}

int main() {
    do {
        stack<string> stack1;
        stack<string> stack2;
        cout << "1. Apilar" << endl;
        cout << "2. Ver" << endl;
        cout << "3. Unir pilas" << endl;
        cout << "4. Salir" << endl;
        cout << "Ingrese una opción: ";
        int op;
        cin >> op;

        switch(op) {
            case 1: {
                pushStack(stack1);
                break;
            }
            case 2: {
                cout << "Ingrese pila a visualizar: " << endl;
                int numStack;
                cin >> numStack;
                switch(numStack) {
                    case 1: {
                        showStack(stack1);
                        break;
                    }
                    case 2: {
                        showStack(stack2);
                        break;
                    }
                    default: {
                        cout << "Numero de pila no definido" << endl;
                        break;
                    }
                }
                
                break;
            }
            case 3: {
                joinStack(stack1, stack2);
                break;
            }
            case 4: {
                return 0;
            }
            default: {
                cout << "Ingrese una opcion correcta" << endl;
                break;
            }
        }


    } while(true);
}