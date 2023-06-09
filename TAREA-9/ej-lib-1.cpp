#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Pila {
    private:
        stack<string> pila;
    public:
        void insert(string dato) {
            pila.push(dato);
        }
        void extract() {
            if (pila.empty()) {
                cout << "La pila está vacía" << endl;
            } else {
                cout << "El dato extraído es: " << pila.top() << endl;
                pila.pop();
            }
        }
        void print() {
            if (pila.empty()) {
                cout << "La pila está vacía" << endl;
            } else {
                cout << "Los datos de la pila son: " << endl;
                while (!pila.empty()) {
                    cout << pila.top() << endl;
                    pila.pop();
                }
            }
        }

        int quantity() {
            if(pila.empty()) {
                cout << "La pila está vacía" << endl;
                return 0;
            } else {
                cout << "La cantidad de nodos es: " << pila.size() << endl;
                return pila.size();
            }
        }
        string showFirst() {
            if(pila.empty()) {
                cout << "La pila está vacía" << endl;
                return "";
            } else {
                cout << "El primer nodo es: " << pila.top() << endl;
                return pila.top();
            }
        }
};

class Formula {
    private:
        string formula;
    public:
        void setFormula(string formula) {
            this->formula = formula;
        }
        bool validate() {
            Pila pila;
            for (int i = 0; i < formula.length(); i++) {
                if (formula[i] == '(' || formula[i] == '[' || formula[i] == '{') {
                    string aux = "";
                    aux += formula[i];
                    pila.insert(aux);
                } else if (formula[i] == ')' || formula[i] == ']' || formula[i] == '}') {
                    if (pila.quantity() == 0) {
                        return false;
                    }
                    string aux = "";
                    aux += formula[i];
                    string aux2 = pila.showFirst();
                    if (aux2 == "(" && aux == ")") {
                        pila.extract();
                    } else if (aux2 == "[" && aux == "]") {
                        pila.extract();
                    } else if (aux2 == "{" && aux == "}") {
                        pila.extract();
                    } else {
                        return false;
                    }
                }
            }
            if (pila.quantity() == 0) {
                return true;
            } else {
                return false;
            }
        }
};

int main() {
    do {
        cout << "1. Ingresar una formula" << endl;
        cout << "2. Validar formula" << endl;
        cout << "3. Salir" << endl;
        cout << "Ingrese una opcion: ";
        int opcion;
        cin >> opcion;
        switch (opcion) {
            case 1: {
                Formula formula;
                string formulaIngresada;
                cout << "Ingrese una formula: ";
                cin >> formulaIngresada;
                formula.setFormula(formulaIngresada);
                break;
            }
            case 2: {
                Formula formula;
                if (formula.validate()) {
                    cout << "La formula esta balanceada" << endl;
                } else {
                    cout << "La formula no esta balanceada" << endl;
                }
                break;
            }
            case 3: {
                return 0;
            }
            default: {
                cout << "Opcion incorrecta" << endl;
                break;
            }
        }


    } while(true);
}