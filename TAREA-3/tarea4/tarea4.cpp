#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Ficha {
    string nombreFich;
    unsigned long tamanyo;
};

vector<Ficha> fichas;
int opcion;

int main() {
    do {
        cout << "Escoja una opción:\n";
        cout << "1. Añadir datos de un nuevo fichero\n";
        cout << "2. Mostrar los nombres de todos los ficheros\n";
        cout << "3. Mostrar ficheros que sean de mas de un cierto tamaño\n";
        cout << "4. Ver datos de un fichero\n";
        cout << "5. Busqueda parcial con parte del nombre\n";
        cout << "6. Salir\n";
        
        string textoTemporal;
        unsigned long numeroTemporal;

        getline(cin, textoTemporal);
        opcion = stoi(textoTemporal);

        switch (opcion) {
            case 1:
                if (fichas.size() < 1000) {
                    Ficha nuevaFicha;
                    cout << "Introduce el nombre del fichero: ";
                    getline(cin, nuevaFicha.nombreFich);
                    cout << "Introduce el tamaño en KB: ";
                    getline(cin, textoTemporal);
                    nuevaFicha.tamanyo = stoul(textoTemporal);
                    if(nuevaFicha.nombreFich == "" && nuevaFicha.tamanyo < 0) {
                        cout << "No se puede añadir un fichero sin nombre y con tamaño negativo!\n";
                        break;
                    }
                    fichas.push_back(nuevaFicha);
                } else {
                    cout << "Máximo de fichas alcanzado (1000)!\n";
                }
                break;
            case 2:
                for (const auto& ficha : fichas) {
                    cout << "Nombre: " << ficha.nombreFich << "; Tamaño: " << ficha.tamanyo << " Kb\n";
                }
                break;
            case 3:
                cout << "¿A partir de que tamaño quieres que te muestre? ";
                getline(cin, textoTemporal);
                numeroTemporal = stoul(textoTemporal);
                for (const auto& ficha : fichas) {
                    if (ficha.tamanyo >= numeroTemporal) {
                        cout << "Nombre: " << ficha.nombreFich << "; Tamaño: " << ficha.tamanyo << " Kb\n";
                    }
                }
                break;
            case 4:
                cout << "¿De qué fichero quieres ver todos los datos? ";
                getline(cin, textoTemporal);
                for (const auto& ficha : fichas) {
                    if (ficha.nombreFich == textoTemporal) {
                        cout << "Nombre: " << ficha.nombreFich << "; Tamaño: " << ficha.tamanyo << " Kb\n";
                        break;
                    }
                }
                break;
            case 5:
                cout << "Ingrese parte de su nombre:\n";
                getline(cin, textoTemporal);
                for (const auto& ficha : fichas) {
                    if (ficha.nombreFich.find(textoTemporal) != string::npos) {
                        cout << "Nombre: " << ficha.nombreFich << "; Tamaño: " << ficha.tamanyo << " Kb\n";
                    }
                }
                break;
            case 6:
                cout << "Fin del programa\n";
                break;
            default:
                cout << "Opción desconocida!\n";
                break;
        }
    } while (opcion != 6);
    
    return 0;
}
