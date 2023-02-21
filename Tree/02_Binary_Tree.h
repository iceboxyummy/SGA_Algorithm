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
    static void InsertNode(Node** root, int key) 
	{
		Node* parent = nullptr;
		Node* current = nullptr;
		Node* new_node = CreateNode(key);

		current = *root;

		while (current != nullptr)
		{
			parent = current;
			if (key < parent->data)
				current = parent->left;
			else
				current = parent->right;
		}

        if (parent != nullptr)
        {
            if (key < parent->data)
                parent->left = new_node;
            else
                parent->right = new_node;
        }
        else
            *root = new_node;
	}

    static void PreOrder(Node* node) 
    {
        if (node == nullptr) return;

        cout << " " << node->data;
        PreOrder(node->left);
        PreOrder(node->right);
    }

    static void InOrder(Node* node) 
    {
        if (node == nullptr) return;

        InOrder(node->left);
        cout << " " << node->data;
        InOrder(node->right);
    }

    static void PostOrder(Node* node) 
    {
        if (node == nullptr) return;

        PostOrder(node->left);
        PostOrder(node->right);
        cout << " " << node->data;
    }
};