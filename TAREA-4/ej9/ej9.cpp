//simular un juego de cartas

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Carta{
    string palo;
    string numero;
    public:
    Carta(string palo, string numero){
        this->palo = palo;
        this->numero = numero;
    }
    string getPalo(){
        return palo;
    }
    string getNumero(){
        return numero;
    }
};

class Juego {
    Jugador jugador1;
    Jugador jugador2;
    Baraja baraja;
    public:
    Juego(Jugador jugador1, Jugador jugador2){
        this->jugador1 = jugador1;
        this->jugador2 = jugador2;
    }
    void repartirCartas(){
        for(int i = 0; i < 10; i++){
            jugador1.agregarCarta(baraja[i]);
            jugador2.agregarCarta(baraja[i+10]);
        }
    }
    void mostrarCartas(){
        jugador1.mostrarCartas();
        jugador2.mostrarCartas();
    }
};

class Jugador {
    string nombre;
    vector<Carta> cartas;
    public:
    Jugador() = default;
    Jugador(string nombre){
        this->nombre = nombre;
    }
    void agregarCarta(Carta carta){
        cartas.push_back(carta);
    }
    void mostrarCartas(){
        cout << nombre << endl;
        for(int i = 0; i < cartas.size(); i++){
            cout << cartas[i].getNumero() << " de " << cartas[i].getPalo() << endl;
        }
    }
};

class Baraja {
    vector<Carta> cartas;
    public:
    Baraja(){
        string palos[] = {"Oros", "Copas", "Espadas", "Bastos"};
        string numeros[] = {"As", "Dos", "Tres", "Cuatro", "Cinco", "Seis", "Siete", "Sota", "Caballo", "Rey"};
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 10; j++){
                Carta carta(palos[i], numeros[j]);
                cartas.push_back(carta);
            }
        }
    }
    Carta operator[](int i){
        return cartas[i];
    }
};



int main(){
    Jugador jugador1("Jugador 1");
    Jugador jugador2("Jugador 2");
    Juego juego(jugador1, jugador2);
    juego.repartirCartas();
    juego.mostrarCartas();
    return 0;
}
