#include <iostream>
#include <stack>
#include <string>

using namespace std;

void pushStack(stack<string>& stack) {
    string dato;
    cout << "Ingrese un dato: ";
    cin >> dato;
    stack.push(dato);
}

void showStack(stack<string>& stack) {
    cout << "Elementos de la pila: ";
    while (!stack.empty()) {
        cout << stack.top() << " ";
        stack.pop();
    }
    cout << endl;
}

void joinStack(stack<string>& stack1, stack<string>& stack2) {
    stack<string> tempStack;
    while (!stack1.empty()) {
        tempStack.push(stack1.top());
        stack1.pop();
    }
    while (!tempStack.empty()) {
        stack2.push(tempStack.top());
        tempStack.pop();
    }
    cout << "Pilas unidas exitosamente." << endl;
}

void multiplyStacks(stack<string>& stack1, stack<string>& stack2) {
    stack<string> resultStack;
    while (!stack1.empty() && !stack2.empty()) {
        int num1 = stoi(stack1.top());
        int num2 = stoi(stack2.top());
        int result = num1 * num2;
        resultStack.push(to_string(result));
        stack1.pop();
        stack2.pop();
    }
    while (!stack1.empty()) {
        resultStack.push(stack1.top());
        stack1.pop();
    }
    while (!stack2.empty()) {
        resultStack.push(stack2.top());
        stack2.pop();
    }
    cout << "Pilas multiplicadas: ";
    showStack(resultStack);
}

int main() {
    stack<string> stack1;
    stack<string> stack2;
    
    do {
        cout << "1. Apilar" << endl;
        cout << "2. Ver" << endl;
        cout << "3. Unir pilas" << endl;
        cout << "4. Multiplicar pilas" << endl;
        cout << "5. Salir" << endl;
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
                multiplyStacks(stack1, stack2);
                break;
            }
            case 5: {
                return 0;
            }
            default: {
                cout << "Ingrese una opcion correcta" << endl;
                break;
            }
        }


    } while(true);
}