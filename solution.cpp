﻿#include <iostream>
#include <string>
#include <vector>
using namespace std;
//реализация односвязного списка
template<typename T>
class List
{
public:
	List();
	~List();
	void pop_front();
	void push_back(T data);
	void clear();
	int GetSize() { return Size; }
	T& operator [] (const int index);
	void push_front(T data);
	void insert(T data, int index);
private:
	template<typename T>
	class Node
	{
	public:
		Node* pNext;
		T data;
		Node(T data = T(), Node* pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};
	int Size;
	Node <T> *head;
};

template<typename T>
List<T>::List()
{
	Size = 0;
	head = nullptr;
}

template<typename T>
List<T>::~List()
{
	clear();
}

template<typename T>
void List<T>::pop_front()
{
	Node<T>* temp = head;
	head = head->pNext;
	delete temp;
	Size--;
}

template<typename T>
void List<T>::push_back(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T>* current = this->head;

		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);
	}
	Size++;
}

template<typename T>
void List<T>::clear()
{
	while (Size)
	{
		pop_front();
	}
}

template<typename T>
T& List<T>::operator[](const int index)
{
	int counter = 0;
	Node<T>* current = this->head;
	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
}

template<typename T>
void List<T>::push_front(T data)
{
	head = new Node<T>(data, head);
	Size++;
}

template<typename T>
void List<T>::insert(T data, int index)
{
	if (index == 0)
	{
		push_front(data);
	}
	else
	{
		Node<T>* previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}
		Node<T>* newNode = new Node <T>(data, previous->pNext);
		previous->pNext = newNode;
		Size++;
	}

}

int main()
{
	setlocale(LC_ALL, "Russian");
	List <int> lst;

	lst.push_front(3);
	lst.push_front(9);
	lst.push_front(5);

	for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << lst[i] << endl;
	}
	cout << "----------------------------------------" << endl;
	lst.insert(12, 1);

	for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << lst[i] << endl;
	}

	return 0;
}