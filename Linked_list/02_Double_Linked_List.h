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

    }

    void PushFront(T data)
    {

    }

    void PopBack()
    {

    }

    void PopFront()
    {

    }

    void Insert(Node* target, T data)
    {

    }


    Node* operator[](int index)
    {

    }

    int Size() { return size; }

    void Clear()
    {

    }

    void PrintList()
    {

    }

protected:
    Node* head = nullptr;
    Node* tail = nullptr;

    int size = 0;
};