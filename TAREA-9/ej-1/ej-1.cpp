#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Desarrolla en C++ dentro VS2022 los siguientes ejercicios (usando clases en modo manual): 
// Confeccionar una clase que administre una lista tipo pila (se debe poder insertar, extraer e imprimir los datos de la pila)
// Agregar a la clase Pila un método que retorne la cantidad de nodos y otro que indique si esta vacía.
// Agregar un método a la clase Pila que retorne la información del primer nodo de la Pila sin borrarlo.
// Se debe desarrollar una clase que tenga las siguientes responsabilidades (clase Formula):
// Ingresar una fórmula que contenga paréntesis, corchetes y llaves.
// Validar que los ( ) [] y {} estén correctamente balanceados.

class Pila {
    private:
        struct Nodo {
            string dato;
            Nodo *siguiente;
        };
        Nodo *cima;
        int cantidad;
    public:
        Pila();
        ~Pila();
        void push(string dato);
        string pop();
        string top();
        int size();
        bool empty();
        void print();
};

Pila::Pila() {
    cima = NULL;
    cantidad = 0;
}

Pila::~Pila() {
    while (cima != NULL) {
        Nodo *aux = cima;
        cima = cima->siguiente;
        delete aux;
    }
}

void Pila::push(string dato) {
    Nodo *nuevo = new Nodo();
    nuevo->dato = dato;
    nuevo->siguiente = cima;
    cima = nuevo;
    cantidad++;
}

string Pila::pop() {
    if (cima == NULL) {
        return "";
    }
    Nodo *aux = cima;
    string dato = aux->dato;
    cima = cima->siguiente;
    delete aux;
    cantidad--;
    return dato;
}

string Pila::top() {
    if (cima == NULL) {
        return "";
    }
    return cima->dato;
}

int Pila::size() {
    return cantidad;
}

bool Pila::empty() {
    return cima == NULL;
}

void Pila::print() {
    Nodo *aux = cima;
    while (aux != NULL) {
        cout << aux->dato << endl;
        aux = aux->siguiente;
    }
}

class Formula {
    private:
        string formula;
    public:
        Formula(string formula);
        bool validar();
};

Formula::Formula(string formula) {
    this->formula = formula;
}

bool Formula::validar() {
    Pila pila;
    for (int i = 0; i < formula.length(); i++) {
        string caracter = formula.substr(i, 1);
        if (caracter == "(" || caracter == "[" || caracter == "{") {
            pila.push(caracter);
        } else if (caracter == ")" || caracter == "]" || caracter == "}") {
            if (pila.empty()) {
                return false;
            }
            string ultimo = pila.pop();
            if (caracter == ")" && ultimo != "(") {
                return false;
            } else if (caracter == "]" && ultimo != "[") {
                return false;
            } else if (caracter == "}" && ultimo != "{") {
                return false;
            }
        }
    }
    return pila.empty();
}

int main() {
    Pila pila;
    pila.push("1");
    pila.push("2");
    pila.push("3");
    pila.push("4");
    pila.push("5");
    pila.print();
    cout << "Cantidad: " << pila.size() << endl;
    cout << "Top: " << pila.top() << endl;
    cout << "Pop: " << pila.pop() << endl;
}