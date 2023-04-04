#include <iostream>

using namespace std;

class Animal {
    public:
        void comer() {
            cout << "El animal está comiendo" << endl;
        }
        void dormir() {
            cout << "El animal está durmiendo" << endl;
        }
};

class Perro : public Animal {
    public:
        void ladrar() {
            cout << "El perro está ladrando" << endl;
        }
};

class Gato : public Animal {
    public:
        void maullar() {
            cout << "El gato está maullando" << endl;
        }
};

int main() {
    Perro perro;
    Gato gato;

    perro.comer();
    perro.dormir();
    perro.ladrar();

    gato.comer();
    gato.dormir();
    gato.maullar();

    return 0;
}