#include <iostream>
#include <string>
#include <vector>

// Desarrollar un programa que pida datos de 8 personas: nombre, día de nacimiento, mes de nacimiento, y año de nacimiento (que se deben almacenar en una tabla de structs). Después deberá repetir lo siguiente: preguntar un número de mes y mostrar en pantalla los datos de las personas que cumplan los años durante ese mes. Terminará de repetirse cuando se teclee 0 como número de mes.

using namespace std;

struct Persona {
    string nombre;
    int dia_nacimiento;
    int mes_nacimiento;
    int anio_nacimiento;
};

void pedirDatos() {
    int personas = 0;
    int mes = 10000;

    Persona persona[2];

    //pedir datos de las personas
    for (int i = 0; i < 2; i++) {
        cout << "Introduce el nombre: ";
        cin >> persona[i].nombre;
        cout << "Introduce el dia de nacimiento: ";
        cin >> persona[i].dia_nacimiento;
        cout << "Introduce el mes de nacimiento: ";
        cin >> persona[i].mes_nacimiento;
        cout << "Introduce el anio de nacimiento: ";
        cin >> persona[i].anio_nacimiento;
        personas++;
    }

    while(mes != 0) {
        cout << "Introduce el mes: ";
        cin >> mes;

        for (int i = 0; i < personas; i++) {
            if (persona[i].mes_nacimiento == mes) {
                cout << "Nombre: " << persona[i].nombre << "; Dia: " << persona[i].dia_nacimiento << "; Mes: " << persona[i].mes_nacimiento << "; Anio: " << persona[i].anio_nacimiento << endl;
            }
        }
    }
}

int main() {
    pedirDatos();
    return 0;
}

