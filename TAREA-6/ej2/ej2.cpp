// Un programa que cree una lista de estudiantes y permita al usuario agregar, eliminar y buscar estudiantes por nombre, edad y carrera.

#include <iostream>
#include <list>
#include <string>

using namespace std;

#include <iostream>

class Estudiante {
    private:
        string nombre;
        int edad;
        string carrera;
    public: 
        Estudiante(string nombre, int edad, string carrera) {
            this->nombre = nombre;
            this->edad = edad;
            this->carrera = carrera;
        }
        string getNombre() {
            return this->nombre;
        }
        int getEdad() {
            return this->edad;
        }
        string getCarrera() {
            return this->carrera;
        }
        void setNombre(string nombre) {
            this->nombre = nombre;
        }
        void setEdad(int edad) {
            this->edad = edad;
        }
        void setCarrera(string carrera) {
            this->carrera = carrera;
        }
};

class Node
{
public:
    string name;
    int age;
    string career;
    Node *next;

    Node(string name, int age, string career)
    {
        this->name = name;
        this->age = age;
        this->career = career;
        this->next = nullptr;
    }
};

class LinkedList
{
public:
    Node *head;

    LinkedList()
    {
        this->head = nullptr;
    }


    void deleteNode(int position)
    {
        if (this->head == nullptr)
        {
            std::cout << "Error: list is empty" << std::endl;
        }
        else if (position == 0)
        {
            Node *temp = this->head;
            this->head = this->head->next;
            delete temp;
        }
        else
        {
            Node *current = this->head;
            int i = 0;

            while (current != nullptr && i < position - 1)
            {
                current = current->next;
                i++;
            }

            if (current == nullptr || current->next == nullptr)
            {
                std::cout << "Error: position out of range" << std::endl;
            }
            else
            {
                Node *temp = current->next;
                current->next = current->next->next;
                delete temp;
            }
        }

    }

    void addStudentNode() {
        string nombre;
        int edad;
        string carrera;
        cout << "Ingrese el nombre del estudiante: ";
        cin >> nombre;
        cout << "Ingrese la edad del estudiante: ";
        cin >> edad;
        cout << "Ingrese la carrera del estudiante: ";
        cin >> carrera;
        Estudiante estudiante(nombre, edad, carrera);
        Node *newNode = new Node(estudiante.getNombre(), estudiante.getEdad(), estudiante.getCarrera());   

    }

    void printList()
    {
        Node *current = this->head;
        while (current != nullptr)
        {
            cout << current->name << " ";
            cout << current->age << " ";
            cout << current->career << " ";

            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main()
{
    LinkedList *list = new LinkedList();
    list->addStudentNode();
    list->printList();
    
    
    return 0;
}
