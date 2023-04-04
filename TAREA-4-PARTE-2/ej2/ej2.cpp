#include <iostream>

using namespace std;

class Vehiculo {
    private: 
        string marca;
        string modelo;
        int anio;
        string color;
        string placa;
};

class Coche : public Vehiculo {
    private:
        int numPuertas;
        string tipo;
};

class Moto : public Vehiculo {
    private:
        int cilindrada;
        string tipo;
};

int main() {
    return 0;
}