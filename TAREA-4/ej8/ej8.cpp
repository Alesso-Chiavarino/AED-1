//sistema de gestión de citas médicas

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Paciente {
    string nombre;
    string apellido;
    string indentificacion;
    string telefono;
    public: 
    Paciente(string nombre, string apellido, string cedula, string telefono, string direccion, string email) {
        this->nombre = nombre;
        this->apellido = apellido;
        this->telefono = telefono;
    }
    string getNombre() {
        return nombre;
    }
    string getApellido() {
        return apellido;
    }
    string getTelefono() {
        return telefono;
    }
};

class Medico {
    string nombre;
    string apellido;
    string indentificacion;
    string telefono;
    public: 
    Medico(string nombre, string apellido, string cedula, string telefono, string direccion, string email) {
        this->nombre = nombre;
        this->apellido = apellido;
        this->telefono = telefono;
    }
    string getNombre() {
        return nombre;
    }
    string getApellido() {
        return apellido;
    }
    string getTelefono() {
        return telefono;
    }
};

class Cita {
    string fecha;
    string hora;
    string motivo;
    bool estado;
    public:
    Cita(string fecha, string hora, string motivo, bool estado) {
        this->fecha = fecha;
        this->hora = hora;
        this->motivo = motivo;
        this->estado = estado;
    }
    string getFecha() {
        return fecha;
    }
    string getHora() {
        return hora;
    }
    string getMotivo() {
        return motivo;
    }
    bool getEstado() {
        return estado;
    }
};

int main() {
    vector<Paciente> pacientes;
    vector<Medico> medicos;
    vector<Cita> citas;
    int opcion = 0;
    while (opcion != 5) {
        cout << "1. Agregar paciente" << endl;
        cout << "2. Agregar medico" << endl;
        cout << "3. Agregar cita" << endl;
        cout << "4. Ver citas" << endl;
        cout << "5. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        if (opcion == 1) {
            string nombre, apellido, cedula, telefono, direccion, email;
            cout << "Ingrese el nombre: ";
            cin >> nombre;
            cout << "Ingrese el apellido: ";
            cin >> apellido;
            cout << "Ingrese la cedula: ";
            cin >> cedula;
            cout << "Ingrese el telefono: ";
            cin >> telefono;
            cout << "Ingrese la direccion: ";
            cin >> direccion;
            cout << "Ingrese el email: ";
            cin >> email;
            Paciente paciente(nombre, apellido, cedula, telefono, direccion, email);
            pacientes.push_back(paciente);
        } else if (opcion == 2) {
            string nombre, apellido, cedula, telefono, direccion, email;
            cout << "Ingrese el nombre: ";
            cin >> nombre;
            cout << "Ingrese el apellido: ";
            cin >> apellido;
            cout << "Ingrese la cedula: ";
            cin >> cedula;
            cout << "Ingrese el telefono: ";
            cin >> telefono;
            cout << "Ingrese la direccion: ";
            cin >> direccion;
            cout << "Ingrese el email: ";
            cin >> email;
            Medico medico(nombre, apellido, cedula, telefono, direccion, email);
            medicos.push_back(medico);
        } else if (opcion == 3) {
            string fecha, hora, motivo;
            bool estado;
            cout << "Ingrese la fecha: ";
            cin >> fecha;
            cout << "Ingrese la hora: ";
            cin >> hora;
            cout << "Ingrese el motivo: ";
            cin >> motivo;
            cout << "Ingrese el estado: ";
            cin >> estado;
            Cita cita(fecha, hora, motivo, estado);
            citas.push_back(cita);
        } else if (opcion == 4)
        {
            for (int i = 0; i < citas.size(); i++) {
                cout << "Fecha: " << citas[i].getFecha() << endl;
                cout << "Hora: " << citas[i].getHora() << endl;
                cout << "Motivo: " << citas[i].getMotivo() << endl;
                cout << "Estado: " << citas[i].getEstado() << endl;
            }
        }
}
    return 0;
}