#include <iostream>
#include <vector>

using namespace std;

class Coche {
    string marca, modelo;
    int año;
public:
    Coche(string marca, string modelo, int año) {
        this->marca = marca;
        this->modelo = modelo;
        this->año = año;
    }
    string getMarca() {
        return marca;
    }
    string getModelo() {
        return modelo;
    }
    int getAño() {
        return año;
    }
};

int main() {
    vector<Coche> coches;
    coches.push_back(Coche("Ford", "Focus", 2010));
    coches.push_back(Coche("Ford", "Fiesta", 2011));
}