#include <iostream>

using namespace std;

class Producto {
    private:
        string nombre;
        float precio;
        int cantidad;
        public:
        int getCantidad() {
            return cantidad;
        }
        float getPrecio() {
            return precio;
        }
};

class CarritoDeCompras {
    private:
        Producto producto[10];
        float total;
        int cantidad;
        float precio;
    public:
        float calcularTotal() {
            for(int i = 0; i < 10; i++) {
                cantidad = producto[i].getCantidad();
                precio = producto[i].getPrecio();
            }
            return total = cantidad * precio;
        }
};

int main() {
    CarritoDeCompras carrito;
    cout << "El total de la compra es: " << carrito.calcularTotal() << endl;
    return 0;
}