#include <iostream>
#include <string>

using namespace std;

class Pila {
    private:
        string* datos;
        int max_size;
        int tope;
    public:
        Pila(int size) {
            max_size = size;
            tope = -1;
            datos = new string[max_size];
        }
        ~Pila() {
            delete[] datos;
        }
        void insert(string dato) {
            if (tope == max_size-1) {
                cout << "La pila esta llena" << endl;
            } else {
                tope++;
                datos[tope] = dato;
            }
        }
        void extract() {
            if (tope == -1) {
                cout << "La pila esta vacia" << endl;
            } else {
                cout << "El dato extraido es: " << datos[tope] << endl;
                tope--;
            }
        }
        void print() {
            if (tope == -1) {
                cout << "La pila esta vacia" << endl;
            } else {
                cout << "Los datos de la pila son: " << endl;
                for (int i = tope; i >= 0; i--) {
                    cout << datos[i] << endl;
                }
            }
        }
        int quantity() {
            if(tope == -1) {
                cout << "La pila esta vacia" << endl;
                return 0;
            } else {
                cout << "La cantidad de nodos es: " << tope+1 << endl;
                return tope+1;
            }
        }
        string showFirst() {
            if(tope == -1) {
                cout << "La pila esta vacia" << endl;
                return "";
            } else {
                cout << "El primer nodo es: " << datos[tope] << endl;
                return datos[tope];
            }
        }
        bool isEmpty() {
            return tope == -1;
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
            Pila pila(formula.length());
            for (int i = 0; i < formula.length(); i++) {
                if (formula[i] == '(' || formula[i] == '[' || formula[i] == '{') {
                    string aux = "";
                    aux += formula[i];
                    pila.insert(aux);
                } else if (formula[i] == ')' || formula[i] == ']' || formula[i] == '}') {
                    if (pila.isEmpty()) {
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
            if (pila.isEmpty()) {
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
                cout << formula.validate();
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
