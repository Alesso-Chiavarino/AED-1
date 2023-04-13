#include <iostream>
#include <list>
#include <string>

using namespace std;

struct Producto {
    string nombre;
    float precio;
};

void imprimir_producto(Producto p) {
    cout << "Nombre: " << p.nombre << endl;
    cout << "Precio: " << p.precio << endl;
}

int main() {
   
    list<Producto> productos;

   
    int opcion = 0;
    while (opcion != 4) {
        cout << "1. Agregar producto" << endl;
        cout << "2. Eliminar producto" << endl;
        cout << "3. Buscar producto por nombre o precio" << endl;
        cout << "4. Salir" << endl;
        cout << "Elija una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
               
                Producto p;
                cout << "Introduzca el nombre del producto: ";
                cin >> p.nombre;
                cout << "Introduzca el precio del producto: ";
                cin >> p.precio;

               
                productos.push_back(p);
                cout << "Producto añadido correctamente." << endl;
                break;
            }
            case 2: {
                
                string nombre;
                cout << "Introduzca el nombre del producto a eliminar: ";
                cin >> nombre;

                
                for (auto it = productos.begin(); it != productos.end(); ++it) {
                    if (it->nombre == nombre) {
                        productos.erase(it);
                        cout << "Producto eliminado correctamente." << endl;
                        break;
                    }
                }
                break;
            }
            case 3: {
              
                string clave;
                cout << "Introduzca el nombre o precio del producto a buscar: ";
                cin >> clave;

    
                bool encontrado = false;
                for (auto p : productos) {
                    if (p.nombre == clave || p.precio == stof(clave)) {
                        imprimir_producto(p);
                        encontrado = true;
                    }
                }
                if (!encontrado) {
                    cout << "No se encontraron productos que coincidan con la búsqueda." << endl;
                }
                break;
            }
            case 4: {
                cout << "¡Hasta pronto!" << endl;
                break;
            }
            default: {
                cout << "Opción no válida. Por favor, seleccione una opción del menú." << endl;
                break;
            }
        }
    }

    return 0;
}
