#pragma once

// 02_Double_Linked_List.h

#include<iostream>
using namespace std;

template<typename T>
class DoubleLinkedList
{
public:
	struct Node
	{
		Node* prev = nullptr;
		Node* next = nullptr;
		T data;
	};

	static Node* Create(T data)
	{
		Node* node = new Node();
		node->data = data;
		return node;
	}

	static void Destroy(Node** node)
	{
		delete* node;
		*node = nullptr;
	}

public:

	~DoubleLinkedList()
	{
		Clear();
	}

	void PushBack(T data)
	{
		Node* node = Create(data);

		if (head == nullptr)
		{
			head = node;
			tail = node;
		}

		else
		{
			tail->next = node;
			node->prev = tail;
			tail = node;
		}
		size++;
	}

	void PushFront(T data)
	{
		Node* node = Create(data);

		if (head == nullptr)
		{
			head = node;
			tail = node;
		}

		else
		{
			head->prev = node;
			node->next = head;
			head = node;
		}
		size++;
	}

	void PopBack()
	{
		if (size <= 0) return;

		if (size == 1)
		{
			Destroy(&head);
			tail = nullptr;
		}

		else
		{
			Node* temp = tail->prev;
			Destroy(&tail);
			tail = temp;
			tail->next = nullptr;
		}
		size--;
	}

	void PopFront()
	{
		if (size <= 0) return;

		if (size == 1)
		{
			Destroy(&head);
			tail = nullptr;
		}

		else
		{
			Node* temp = head->next;
			Destroy(&head);
			head = temp;
			head->prev = nullptr;
		}
		size--;
	}

	void Insert(Node* target, T data)
	{
		Node* temp = head;

		while (temp != nullptr)
		{
			if (temp == target)break;
			temp = temp->next;
		}
		if (temp == nullptr)return;

		if (target = head)
			PushFront(data);

		else
		{
			Node* new_node = Create(data);

			new_node->next = target;
			new_node->prev = target->prev;

			new_node->prev->next = new_node;
			new_node->next->prev = new_node;

			size++;
		}
	}

	Node* operator[](int index)
	{
		if (index >= size)
		{
			cout << "index error" << endl;
			return nullptr;
		}

		Node* node = head;

		while (node != nullptr && index-- > 0)
			node = node->next;

		return node;
	}

	int Size() { return size; }

	void Clear()
	{
		for (int i = size; i > 0; i--)
			PopBack();
	}

	void PrintList()
	{
		for (int i = 0; i < size; i++)
			cout << operator[](i)->data << " ";

		cout << endl;
	}

protected:
	Node* head = nullptr;
	Node* tail = nullptr;

	int size = 0;
};