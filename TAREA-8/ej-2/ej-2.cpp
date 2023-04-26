#include <iostream>
#include <stack>

using namespace std;

// Escribir un programa en C++ que simule el funcionamiento de una calculadora básica utilizando una pila para almacenar los valores y operaciones. El programa debe permitir al usuario ingresar los valores y operaciones y mostrar el resultado final.

int calculate(stack<int> expr, stack<char> op) {
    switch(op.top()) {
        case '+':
            int a = expr.top();
            expr.pop();
            int b = expr.top();
            expr.pop();
            return a + b;
            break;
        case '-':
            break;
        case '*':
            expr.push(expr.top() * expr.top());
            break;
        case '/':
            expr.push(expr.top() / expr.top());
            break;
    }
}

int main() {
    stack<int> expr;
    stack<char> op;
    char operation[100];
    
    do {
        cout << "Ingrese la operacion:" << endl;
        cin >> operation;

        int length = strlen(operation);

        for(int i = 0; i < length; i++) {

            if(operation[i] == '=') {
                cout << expr.top() << endl;
                break;
            }

            if(operation[i] == '+' || operation[i] == '-' || operation[i] == '*' || operation[i] == '/') {
                op.push(operation[i]);
            } else {
                break;
            }

            expr.push(operation[i] - '0');



            // char c = operation[i] - '0';

            // // if(operation[i] == '=') {
            // //     break;
            // // }

            // int result = 0;
            
            // result = c + operation[i] - '0';

            // cout << result << endl;

            // actualOperation[i] = pila.top();
            
        }

        for(int i = 0; i < expr.size(); i++) {
            
        }




        return 0;


    } while(true);
}