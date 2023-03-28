#include <iostream>
#include <vector>

using namespace std;

class cuentaBancaria {
    int numeroCuenta;
    double saldo;
    public: 
    cuentaBancaria(int numeroCuenta, double saldo) {
        this->numeroCuenta = numeroCuenta;
        this->saldo = saldo;
    }
    int getSaldo() {
        return saldo;
    }
    int depositar(int cantidad) {
        return saldo + cantidad;
    }
    int retirar(int cantidad) {
        return saldo - cantidad;
    }
};

int main() {
    vector<cuentaBancaria> cuentas;
    cuentas.push_back(cuentaBancaria(10, 20));
    cuentas.push_back(cuentaBancaria(30, 40));
    for (int i = 0; i < cuentas.size(); i++) {
        cout << "Cuenta " << i + 1 << endl;
        cout << "Saldo: " << cuentas[i].getSaldo() << endl;
        cout << "Depositar: " << cuentas[i].depositar(50) << endl;
        cout << "Retirar: " << cuentas[i].retirar(20) << endl;
        cout << endl;
    }
}
