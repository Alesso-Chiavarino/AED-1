#include <iostream>
#include <vector>

using namespace std;

class Rectángulo {
    int base, altura;
public:
    Rectángulo(int base, int altura) {
        this->base = base;
        this->altura = altura;
    }
    int getBase() {
        return base;
    }
    int getAltura() {
        return altura;
    }
    int getArea() {
        return base * altura;
    }
    int getPerímetro() {
        return 2 * (base + altura);
    }
};

int main() {
    vector<Rectángulo> rectángulos;
    rectángulos.push_back(Rectángulo(10, 20));
    rectángulos.push_back(Rectángulo(30, 40));
    for (int i = 0; i < rectángulos.size(); i++) {
        cout << "Rectángulo " << i + 1 << endl;
        cout << "Base: " << rectángulos[i].getBase() << endl;
        cout << "Altura: " << rectángulos[i].getAltura() << endl;
        cout << "Área: " << rectángulos[i].getArea() << endl;
        cout << "Perímetro: " << rectángulos[i].getPerímetro() << endl;
        cout << endl;
    }
}