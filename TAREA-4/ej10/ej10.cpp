#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Estudiante{
    private:
        string nombre;
        string apellido;
        int edad;
        string carrera;
        int semestre;
        string codigo;
    public:
        Estudiante(string nombre, string apellido, int edad, string carrera, int semestre, string codigo){
            this->nombre = nombre;
            this->apellido = apellido;
            this->edad = edad;
            this->carrera = carrera;
            this->semestre = semestre;
            this->codigo = codigo;
        }
        string getNombre(){
            return nombre;
        }
        string getApellido(){
            return apellido;
        }
        int getEdad(){
            return edad;
        }
        string getCarrera(){
            return carrera;
        }
        int getSemestre(){
            return semestre;
        }
        string getCodigo(){
            return codigo;
        }
};

class Curso{
    private:
        string nombre;
        string codigo;
        int creditos;
        int horas;
        string profesor;
    public:
        Curso(string nombre, string codigo, int creditos, int horas, string profesor){
            this->nombre = nombre;
            this->codigo = codigo;
            this->creditos = creditos;
            this->horas = horas;
            this->profesor = profesor;
        }
        string getNombre(){
            return nombre;
        }
        string getCodigo(){
            return codigo;
        }
        int getCreditos(){
            return creditos;
        }
        int getHoras(){
            return horas;
        }
        string getProfesor(){
            return profesor;
        }
};

class Nota{
    private:
        string codigo;
        string nombre;
        int nota;
    public:
        Nota(string codigo, string nombre, int nota){
            this->codigo = codigo;
            this->nombre = nombre;
            this->nota = nota;
        }
        string getCodigo(){
            return codigo;
        }
        string getNombre(){
            return nombre;
        }
        int getNota(){
            return nota;
        }
};

class Promedio{
    private:
        string codigo;
        string nombre;
        int promedio;
    public:
        Promedio(string codigo, string nombre, int promedio){
            this->codigo = codigo;
            this->nombre = nombre;
            this->promedio = promedio;
        }
        string getCodigo(){
            return codigo;
        }
        string getNombre(){
            return nombre;
        }
        int getPromedio(){
            return promedio;
        }
};

int main(){
    vector<Estudiante> estudiantes;
    vector<Curso> cursos;
    vector<Nota> notas;
    vector<Promedio> promedios;
    int opcion = 0;
    while(opcion != 5){
        cout << "1. Registrar estudiante" << endl;
        cout << "2. Registrar curso" << endl;
        cout << "3. Registrar nota" << endl;
        cout << "4. Calcular promedio" << endl;
        cout << "5. Salir" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        switch(opcion){
            case 1:{
                string nombre, apellido, carrera, codigo;
                int edad, semestre;
                cout << "Ingrese el nombre del estudiante: ";
                cin >> nombre;
                cout << "Ingrese el apellido del estudiante: ";
                cin >> apellido;
                cout << "Ingrese la edad del estudiante: ";
                cin >> edad;
                cout << "Ingrese la carrera del estudiante: ";
                cin >> carrera;
                cout << "Ingrese el semestre del estudiante: ";
                cin >> semestre;
                cout << "Ingrese el codigo del estudiante: ";
                cin >> codigo;
                Estudiante estudiante(nombre, apellido, edad, carrera, semestre, codigo);
                estudiantes.push_back(estudiante);
                break;
            }
            case 2:{
                string nombre, codigo, profesor;
                int creditos, horas;
                cout << "Ingrese el nombre del curso: ";
                cin >> nombre;
                cout << "Ingrese el codigo del curso: ";
                cin >> codigo;
                cout << "Ingrese los creditos del curso: ";
                cin >> creditos;
                cout << "Ingrese las horas del curso: ";
                cin >> horas;
                cout << "Ingrese el nombre del profesor: ";
                cin >> profesor;
                Curso curso(nombre, codigo, creditos, horas, profesor);
                cursos.push_back(curso);
                break;
            }
            case 3:{
                string codigo, nombre;
                int nota;
                cout << "Ingrese el codigo del estudiante: ";
                cin >> codigo;
                cout << "Ingrese el nombre del curso: ";
                cin >> nombre;
                cout << "Ingrese la nota del estudiante: ";
                cin >> nota;
                Nota nota1(codigo, nombre, nota);
                notas.push_back(nota1);
                break;
            }
            case 4:{
                string codigo, nombre;
                int nota = 0, promedio = 0;
                cout << "Ingrese el codigo del estudiante: ";
                cin >> codigo;
                cout << "Ingrese el nombre del curso: ";
                cin >> nombre;
                for(int i = 0; i < notas.size(); i++){
                    if(notas[i].getCodigo() == codigo && notas[i].getNombre() == nombre){
                        nota += notas[i].getNota();
                    }
                }
                promedio = nota / notas.size();
                Promedio promedio1(codigo, nombre, promedio);
                promedios.push_back(promedio1);
                cout << "El promedio del estudiante es: " << promedio << endl;
                break;
            }
            case 5:{
                break;
            }
            default:{
                cout << "Opcion invalida" << endl;
                break;
            }
        }
    }
    return 0;
}
                