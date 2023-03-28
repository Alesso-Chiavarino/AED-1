#include <iostream>
#include <vector>

using namespace std;

class CuentaBancaria {
    int numeroCuenta;
    double saldo;
    public: 
    CuentaBancaria(int numeroCuenta, double saldo) {
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
    int getNumeroCuenta() {
        return numeroCuenta;
    }
};

class Transaccion {
    int numeroCuenta;
    string fecha;
    double monto;
    string tipo;
    public: 
    Transaccion(int numeroCuenta, string fecha, double monto, string tipo) {
        this->numeroCuenta = numeroCuenta;
        this->fecha = fecha;
        this->monto = monto;
        this->tipo = tipo;
    }
    int getNumeroCuenta() {
        return numeroCuenta;
    }
    string getFecha() {
        return fecha;
    }
    double getMonto() {
        return monto;
    }
    string getTipo() {
        return tipo;
    }
};

class TarjetaCredito {
    int numeroTarjeta;
    string fechaVencimiento;
    double limiteCredito;
    double saldo;
    public: 
    TarjetaCredito(int numeroTarjeta, string fechaVencimiento, double limiteCredito, double saldo) {
        this->numeroTarjeta = numeroTarjeta;
        this->fechaVencimiento = fechaVencimiento;
        this->limiteCredito = limiteCredito;
        this->saldo = saldo;
    }
    int getNumeroTarjeta() {
        return numeroTarjeta;
    }
    string getFechaVencimiento() {
        return fechaVencimiento;
    }
    double getLimiteCredito() {
        return limiteCredito;
    }
    double getSaldo() {
        return saldo;
    }
    double getSaldoDisponible() {
        return limiteCredito - saldo;
    }
};

void registrarCuentaBancaria(vector<CuentaBancaria> cuentas) {
    int numeroCuenta;
    double saldo;
    cout << "Ingrese el número de cuenta: ";
    cin >> numeroCuenta;
    cout << "Ingrese el saldo: ";
    cin >> saldo;
    cuentas.push_back(CuentaBancaria(numeroCuenta, saldo));
}

void registrarTarjetaCredito(vector<TarjetaCredito> tarjetas) {
    int numeroTarjeta;
    string fechaVencimiento;
    double limiteCredito;
    double saldo;
    cout << "Ingrese el número de tarjeta: ";
    cin >> numeroTarjeta;
    cout << "Ingrese la fecha de vencimiento: ";
    cin >> fechaVencimiento;
    cout << "Ingrese el límite de crédito: ";
    cin >> limiteCredito;
    cout << "Ingrese el saldo: ";
    cin >> saldo;
    tarjetas.push_back(TarjetaCredito(numeroTarjeta, fechaVencimiento, limiteCredito, saldo));
}

void regitrarTransaccion() {
    int numeroCuenta;
    string fecha;
    double monto;
    string tipo;
    cout << "Ingrese el número de cuenta: ";
    cin >> numeroCuenta;
    cout << "Ingrese la fecha: ";
    cin >> fecha;
    cout << "Ingrese el monto: ";
    cin >> monto;
    cout << "Ingrese el tipo: ";
    cin >> tipo;
}

void consultarSaldoCuentaBancaria(vector<CuentaBancaria> cuentas) {
    int numeroCuenta;
    cout << "Ingrese el número de cuenta: ";
    cin >> numeroCuenta;
    for (int i = 0; i < cuentas.size(); i++) {
        if (cuentas[i].getNumeroCuenta() == numeroCuenta) {
            cout << "Saldo: " << cuentas[i].getSaldo() << endl;
        }
    }
}

void consultarSaldoTarjetaCredito(vector<TarjetaCredito> tarjetas) {
    int numeroTarjeta;
    cout << "Ingrese el número de tarjeta: ";
    cin >> numeroTarjeta;
    for (int i = 0; i < tarjetas.size(); i++) {
        if (tarjetas[i].getNumeroTarjeta() == numeroTarjeta) {
            cout << "Saldo: " << tarjetas[i].getSaldo() << endl;
            cout << "Saldo disponible: " << tarjetas[i].getSaldoDisponible() << endl;
        }
    }
}

int menu() {
    int opcion;
    
    do {
        cout << "1. Registrar cuenta bancaria" << endl;
        cout << "2. Registrar tarjeta de crédito" << endl;
        cout << "3. Registrar transacción" << endl;
        cout << "4. Consultar saldo de cuenta bancaria" << endl;
        cout << "5. Consultar saldo de tarjeta de crédito" << endl;
        cout << "6. Salir" << endl;
        cout << "Ingrese una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                registrarCuentaBancaria();
                break;
            case 2:
                registrarTarjetaCredito();
                break;
            case 3:
                regitrarTransaccion();
                break;
            case 4:
                consultarSaldoCuentaBancaria();
                break;
            case 5:
                consultarSaldoTarjetaCredito();
                break;
            case 6:
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opción inválida" << endl;
                break;
        }
    } while (opcion != 6);

}

int main(){
    vector<CuentaBancaria> cuentas;
    vector<TarjetaCredito> tarjetas;
    vector<Transaccion> transacciones;
    menu();
    return 0;
}