#include <iostream>

using namespace std;

class FiguraGeometrica {
    private: 
        int area;
        int perimetro;
};

class Triangulo : public FiguraGeometrica {
    private:
        int base;
        int altura;
    public:
        int calcularArea() {
            return (base * altura) / 2;
        }
        int calcularPerimetro() {
            return base * 3;
        }
};

class Cuadrado : public FiguraGeometrica {
    private:
        int lado;
    public:
        int calcularArea() {
            return lado * lado;
        }
        int calcularPerimetro() {
            return lado * 4;
        }
};

int main() {
    Triangulo triangulo;
    Cuadrado cuadrado;

    triangulo.calcularArea();
    triangulo.calcularPerimetro();

    cuadrado.calcularArea();
    cuadrado.calcularPerimetro();

    return 0;
}

