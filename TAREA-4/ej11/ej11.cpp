// 11. Crea un programa en C++ que use clases y objetos para implementar un sistema de gestión de inventarios para una tienda en línea, con una clase productos utilizando punteros, y clases para categorías, pedidos y carritos de compras.

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Producto {
    private:
        string nombre;
        string descripcion;
        string categoria;
        float precio;
        int cantidad;
    public:
        Producto(string nombre, string descripcion, float precio, int cantidad) {
            this->nombre = nombre;
            this->descripcion = descripcion;
            this->precio = precio;
            this->cantidad = cantidad;
        }
        string getNombre() {
            return nombre;
        }
        string getDescripcion() {
            return descripcion;
        }
        float getPrecio() {
            return precio;
        }
        int getCantidad() {
            return cantidad;
        }
        void setNombre(string nombre) {
            this->nombre = nombre;
        }
        void setDescripcion(string descripcion) {
            this->descripcion = descripcion;
        }
        void setPrecio(float precio) {
            this->precio = precio;
        }
        void setCantidad(int cantidad) {
            this->cantidad = cantidad;
        }
};

class Categoria {
    private:
        string nombre;
        vector<Producto*> productos;
    public:
        Categoria(string nombre) {
            this->nombre = nombre;
        }
        string getNombre() {
            return nombre;
        }
        void setNombre(string nombre) {
            this->nombre = nombre;
        }
        void agregarProducto(Producto* producto) {
            productos.push_back(producto);
        }
        void mostrarProductos() {
            for (int i = 0; i < productos.size(); i++) {
                cout << "Nombre: " << productos[i]->getNombre() << endl;
                cout << "Descripcion: " << productos[i]->getDescripcion() << endl;
                cout << "Precio: " << productos[i]->getPrecio() << endl;
                cout << "Cantidad: " << productos[i]->getCantidad() << endl;
                cout << endl;
            }
        }
};

class Pedido {
    private:
        vector<Producto*> productos;
    public:
        void agregarProducto(Producto* producto) {
            productos.push_back(producto);
        }
        void mostrarProductos() {
            for (int i = 0; i < productos.size(); i++) {
                cout << "Nombre: " << productos[i]->getNombre() << endl;
                cout << "Descripcion: " << productos[i]->getDescripcion() << endl;
                cout << "Precio: " << productos[i]->getPrecio() << endl;
                cout << "Cantidad: " << productos[i]->getCantidad() << endl;
                cout << endl;
            }
        }
};

class Carrito {
    private:
        vector<Producto*> productos;
    public:
        void agregarProducto(Producto* producto) {
            productos.push_back(producto);
        }
        void mostrarProductos() {
            for (int i = 0; i < productos.size(); i++) {
                cout << "Nombre: " << productos[i]->getNombre() << endl;
                cout << "Descripcion: " << productos[i]->getDescripcion() << endl;
                cout << "Precio: " << productos[i]->getPrecio() << endl;
                cout << "Cantidad: " << productos[i]->getCantidad() << endl;
                cout << endl;
            }
        }
};

int main() {
    Categoria* categoria1 = new Categoria("Categoria 1");
    Categoria* categoria2 = new Categoria("Categoria 2");
    Categoria* categoria3 = new Categoria("Categoria 3");
    //fin de categorias
    Producto* producto1 = new Producto("Producto 1", "Descripcion 1", 1.0, 1);
    Producto* producto2 = new Producto("Producto 2", "Descripcion 2", 2.0, 2);
    Producto* producto3 = new Producto("Producto 3", "Descripcion 3", 3.0, 3);
    // fin de productos
    categoria1->agregarProducto(producto1);
    categoria1->agregarProducto(producto2);
    categoria1->agregarProducto(producto3);
    // fin de agregar productos a categorias
    categoria1->mostrarProductos(); 
    return 0;
}
