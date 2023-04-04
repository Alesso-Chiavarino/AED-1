#include <iostream>

using namespace std;

class CuentaBancaria {
    private:
        float saldo;
        int numeroCuenta;
        public:
            float getSaldo() {
                return saldo;
         }
};

class CuentaCorriente : public CuentaBancaria {
    private:
        float comision;
        float interes;
    public:
        float cobrarComisiones() {
            return comision = getSaldo() * 0.2;
        }
        float calcularIntereses() {
            return interes = getSaldo() * 1.05;
        }
};

class cuentaAhorro : public CuentaBancaria {
    private:
        float interes;
        float comision;
    public:
        float calcularComisiones() {
            return comision = getSaldo() * 0.2;
        }
        float calcularIntereses() {
            return interes = getSaldo() * 1.05;
        }
};

int main() {
    CuentaCorriente cuentaCorriente;
    cuentaAhorro cuentaAhorro;
    cuentaCorriente.getSaldo();
    cuentaAhorro.getSaldo();
    cout << "Cuenta corriente: " << cuentaCorriente.cobrarComisiones() << endl;
    cout << "Cuenta de ahorro: " << cuentaAhorro.calcularComisiones() << endl;
    return 0;
}