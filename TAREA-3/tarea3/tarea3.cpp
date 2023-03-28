#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Persona
{
    string nombre;
    string direccion;
    string telefono;
    int edad;
};

void pedirDatos()
{
    int personas = 0;
    int opcion = 10000;
    char inicial = 'a';

    Persona persona[50];

    // pedir datos de las personas
    for (int i = 0; i < 50; i++)
    {
        cout << "Introduce el nombre: ";
        // getline acepta vacio
        cin.ignore();
        getline(cin, persona[i].nombre);
        if (persona[i].nombre == "")
        {
            break;
        }
        cout << "Introduce la direccion: ";
        cin >> persona[i].direccion;
        cout << "Introduce el telefono: ";
        cin >> persona[i].telefono;
        cout << "Introduce la edad: ";
        cin >> persona[i].edad;
    }

    while (opcion != 4)
    {
        cout << "Escoja una opcion: " << endl;
        cout << "1.- Mostrar la lista de todos los nombres." << endl;
        cout << "2.- Mostrar las personas de una cierta edad." << endl;
        cout << "3.- Mostrar las personas cuya inicial sea la que el usuario indique." << endl;
        cout << "4.- Salir del programa." << endl;
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            for (int i = 0; i < personas; i++)
            {
                cout << "Nombre: " << persona[i].nombre << endl;
            }
            break;
        case 2:
            cout << "Introduce la edad: ";
            cin >> opcion;
            for (int i = 0; i < personas; i++)
            {
                if (persona[i].edad == opcion)
                {
                    cout << "Nombre: " << persona[i].nombre << "; Direccion: " << persona[i].direccion << "; Telefono: " << persona[i].telefono << "; Edad: " << persona[i].edad << endl;
                }
            }
            break;
        case 3:
            cout << "Introduce la inicial: ";
            cin >> inicial;
            for (int i = 0; i < personas; i++)
            {
                if (persona[i].nombre[0] == inicial)
                {
                    cout << "Nombre: " << persona[i].nombre << "; Direccion: " << persona[i].direccion << "; Telefono: " << persona[i].telefono << "; Edad: " << persona[i].edad
                         << endl;
                }
            }
            break;
        case 4:
            break;
        default:
            cout << "Opcion incorrecta" << endl;
            break;
        }
    }
}

int main()
{
    pedirDatos();
    return 0;
}