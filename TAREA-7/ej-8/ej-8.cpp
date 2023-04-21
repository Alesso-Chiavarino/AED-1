#include <iostream>
#include <random>
using namespace std;
class node {
public:
	int num;
	node* next;
	node(int num) {
		this->num = num;
		this->next = nullptr;
	}
};
class Linkedlist {
public:
	node* cabeza;
	Linkedlist() {
		this->cabeza = nullptr;
	}
	void agregar(int num) {
		node* nuevonode = new node(num);
		if (this->cabeza == nullptr) {
			this->cabeza = nuevonode;
		}
		else {
			node* current = this->cabeza;
			while (current->next != nullptr) {
				current = current->next;
			}
			current->next = nuevonode;
		}
	}
	void mostrar() {
		node* current = this->cabeza;
		while (current != nullptr) {
			cout << "Elemento:" << current->num << " " << endl;
			cout << endl;
			current = current->next;
		}
	}
	void insertar(int num) {
		node* nuevonode = new node(num);
		if (this->cabeza == nullptr) {
			this->cabeza = nuevonode;
		}
		else {
			node* current = this->cabeza;
			while (current->next != nullptr) {
				current = current->next;
			}
			current->next = nuevonode;
		}
	}
	void unirlistas(Linkedlist LF) {
		node* current = this->cabeza;
		while (current->next != nullptr) {
			current = current->next;
		}
		current->next = LF.cabeza;
}

	void restar() {
		node* current = this->cabeza;
		node* current2 = this->cabeza;
		while (current != nullptr) {
			while (current2 != nullptr) {
				if (current->num == current2->num) {
					current->num = 0;
				}
				current2 = current2->next;
			}
			current = current->next;
		}
		current = this->cabeza;
		while (current != nullptr) {
			if (current->num == 0) {
				if (current == this->cabeza) {
					this->cabeza = current->next;
					delete current;
					current = this->cabeza;
				}
				else {
					node* temp = this->cabeza;
					while (temp->next != current) {
						temp = temp->next;
					}
					temp->next = current->next;
					delete current;
					current = temp->next;
				}
			}
			else {
				current = current->next;
			}
		}
}


};
int main() {
	int op;
	
	Linkedlist l1;
	Linkedlist l2;
	l1.agregar(2);
	l1.agregar(3);
	l2.agregar(7);
	l2.agregar(2);
	do {
		system("cls");
		cout << "Elija la opcion que desea ingresar" << endl;
		cout << "0-SALIR" << endl;
		cout << "1-Mostrar las 2 listas" << endl;
		cout << "2-Mostrar lista final" << endl;
		cout << "3-Mostrar la resta de ambas listas" << endl;
		cout << "Ingrese su opcion";
		cin >> op;
		switch (op)
		{
		case 1:
			cout << "Lista 1:" << endl;
			l1.mostrar();
			cout << "Lista 2:" << endl;
			l2.mostrar();
			cout << endl;
            system("pause");
			break;
		case 2:
			cout << "La lista final:" << endl;
			l2.unirlistas(l1);
			l2.mostrar();
			system("pause");
			break;
		case 3: 
			cout << "La resta:" << endl;
			l2.unirlistas(l1);
			l2.restar();
			system("pause");
			break;
		default:
			break;
		}
	} while (op != 0);
}