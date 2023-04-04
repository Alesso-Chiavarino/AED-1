#include <iostream>

using namespace std;

class Animal {
    private:
        bool come;
        bool duerme;
    public:
        bool Comer() {
            return come = true;
        }
        bool Dormir() {
            return duerme = true;
        }

};

class Veterinario {
    private:
        Animal animal;
    public:
        void analizar(){
            if(animal.Comer() && animal.Dormir()){
                cout << "El animal esta bien" << endl;
            } else {
                cout << "El animal esta mal" << endl;
            }
        }
};

int main() {
    Veterinario veterinario;
    veterinario.analizar();
    return 0;
}