#pragma once

// 02_Binary_Tree.h

/*
   �� ���� Ʈ��(Binary Tree)
      �� Ʈ���� ������ 2������ Ʈ��
      �� ��尡 ���ĵǾ� ���� ��� Ž���� ������
*/

#include<iostream>
using namespace std;

class BinaryTree
{
public:
    struct Node
    {
        int data;
        Node* left = nullptr;
        Node* right = nullptr;
    };

    static Node* CreateNode(int data)
    {
        Node* node = new Node();
        node->data = data;
        return node;
    }

    static void DeleteNode(Node** node)
    {
        delete(*node);
        *node = nullptr;
    }

public:
    // �ش� key���� ������ ��� ������ Ʈ���� �߰��ϱ�
    static void InsertNode(Node** root, int key) {}

    static void PreOrder(Node* node) 
    {
        if (node == nullptr)
            return;

        else

    }

    static void InOrder(Node* node) {}

    static void PostOrder(Node* node) {}
};