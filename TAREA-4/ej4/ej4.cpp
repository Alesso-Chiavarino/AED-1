#include <iostream>
#include <vector>

using namespace std;

class Círculo {
    int radio;
    int diametro;
    public: 
    Círculo(int radio, int diametro) {
        this->radio = radio;
        this->diametro = diametro;
    }
    int getRadio() {
        return radio;
    }
    int getDiametro() {
        return diametro;
    }
    int getArea() {
        return radio * diametro;
    }
    int getCircunferencia() {
        return 2 * (radio + diametro);
    }
};

int main() {
    vector<Círculo> círculos;
    círculos.push_back(Círculo(10, 20));
    círculos.push_back(Círculo(30, 40));
    for (int i = 0; i < círculos.size(); i++) {
        cout << "Círculo " << i + 1 << endl;
        cout << "Radio: " << círculos[i].getRadio() << endl;
        cout << "Diametro: " << círculos[i].getDiametro() << endl;
        cout << "Área: " << círculos[i].getArea() << endl;
        cout << "Circunferencia: " << círculos[i].getCircunferencia() << endl;
        cout << endl;
    }
}
