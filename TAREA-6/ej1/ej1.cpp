// Un programa que permita al usuario ingresar una lista de números enteros y, a continuación, elimine de la lista todos los números pares.

#include <iostream>
#include <list>

using namespace std;

#include <iostream>

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
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

    void addNode(int data)
    {
        Node *newNode = new Node(data);

        if (this->head == nullptr)
        {
            this->head = newNode;
        }
        else
        {
            Node *current = this->head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void insertNode(int data, int position)
    {
        Node *newNode = new Node(data);

        if (position == 0)
        {
            newNode->next = this->head;
            this->head = newNode;
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

            if (current == nullptr)
            {
                std::cout << "Error: position out of range" << std::endl;
            }
            else
            {
                newNode->next = current->next;
                current->next = newNode;
            }
        }
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

    int deleteNumberParOfAllList() {
        int count = 1;
        Node *current = this->head;
        while (current != nullptr)
        {
            if (current->data % 2 == 0) {
                deleteNode(count);
                count++;
            }
            current = current->next;
        }
        return count;
    }

    void printList()
    {
        Node *current = this->head;
        while (current != nullptr)
        {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main()
{
    LinkedList list;
    list.addNode(1);
    list.addNode(2);
    list.addNode(4);
    list.addNode(5);
    list.addNode(6);
    list.addNode(7);
    list.insertNode(3, 2);
    list.printList();
    list.deleteNumberParOfAllList();
    list.printList();
    return 0;
}
