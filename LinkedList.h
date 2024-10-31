#pragma once
#include "Node.h"
#include <iostream>
using namespace std;

template <class T>
class LinkedList
{
private:
	Node<T>* head;
	Node<T>* tail;

public:
	LinkedList() {
		head = nullptr;
		tail = nullptr;
	}

	void addToEnd(T* data) {
		Node<T>* newNode = new Node<T>(data);
		if (!head) {
			head = newNode;
			tail = newNode;
		}
		else {
			tail->setNext(newNode);
			newNode->setPrev(tail);
			tail = newNode;
		}
	}

    void deleteNode(string name) {
        if (!head) {
            cout << "La lista esta vacia\n";
            return; 
        }

        Node<T>* current = head;

        while (current != nullptr && current->getData()->getName() != name) {
            current = current->getNext();
        }

        if (current == head) {  // El nodo a eliminar es la cabeza
            head = head->getNext();
            if (head != nullptr) {
                head->setPrev(nullptr);
            }
        }
       
        else if (current == tail) {  // El nodo a eliminar es la cola
            tail = tail->getPrev();
            if (tail != nullptr) {
                tail->setNext(nullptr);
            }
        }

        else { // El nodo a eliminar está en el medio
            current->getPrev()->setNext(current->getNext());
            current->getNext()->setPrev(current->getPrev());
        }

        delete current;
        cout << "Nodo con nombre: " << name << " eliminado\n";
    }

    void DisplayInfo() {

        cout << "Rutas:\n";
        Node<T>* temp = head;

        while (temp != nullptr) {
            cout << temp->getData()->getName() << endl;
            temp = temp->getNext();
        }
    }
};

