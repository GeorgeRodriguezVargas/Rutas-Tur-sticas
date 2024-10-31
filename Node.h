#pragma once
template <class  T>
class Node
{
private:
	T* data;
	Node<T>* next;
	Node<T>* prev;

public:
	Node(T* data) {
		this->data = data;
		next = nullptr;
		prev = nullptr;
	}

	T* getData() { return data; }

	void setNext(Node<T>* next) { this->next = next; }
	void setPrev(Node<T>* prev) { this->prev = prev; }

	Node<T>* getNext() { return next; }
	Node<T>* getPrev() { return prev; }
};

