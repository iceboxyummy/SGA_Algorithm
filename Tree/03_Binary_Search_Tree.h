#pragma once

// 03_Binary_Search_Tree.h

/*
   �� ���� Ž�� Ʈ��(Binary Search Tree)
      �� ����1 : ��� Ű���� �����ؾ���(�ߺ�x)
      �� ����2 : ���� ����Ʈ���� ��� Ű������ root�� Ű������ �۴�
      �� ����3 : ������ ����Ʈ���� ��� Ű������ root�� Ű������ ũ��
*/

#include <iostream>
#include <algorithm>

using namespace std;

class BST
{
public:
    struct Node
    {
        int key = 0;
        Node* left = nullptr;
        Node* right = nullptr;
    };

    static Node* Create(int key)
    {
        Node* node = new Node();
        node->key = key;
        return node;
    }

    static void Delete(Node** node)
    {
        delete(*node);
        *node = nullptr;
    }

    // �ݺ����� ���� Ž��
    Node* SearchIteration(Node* node, int key)
    {
        if (node == nullptr) return;       
    }

    // ��� �Լ��� ���� Ž��
    Node* SearchRecurrsive(Node* node, int key)
    {
        if (node == nullptr) return;

        if (node->key == key)
            return node;

        if (node->key > key)
            SearchRecurrsive(node->left, key);

        if (node->key < key)
            SearchRecurrsive(node->right, key);
    }

    // ��� �߰�
    void InsertNode(Node** root, int key)
    {
        Node* parent = nullptr;
        Node* current = nullptr;
        Node* new_node = Create(key);

        current = *root;

        if (key == current->key) return;

        while (current != nullptr)
        {
            parent = current;
            if (key < parent->key)
                current = parent->left;
            else
                current = parent->right;
        }

        if (parent != nullptr)
        {
            if (key < parent->key)
                parent->left = new_node;
            else
                parent->right = new_node;
        }
        else
            *root = new_node;
    }

    void DeleteNode(Node** root, int key)
    {

        // root���� ������ key���� ������ ��� Ž��
        Node* target = SearchRecurrsive(*root, key);

        if(target->left==nullptr&&target->right==nullptr)

        /*
           ������ ��带 ã�Ҵٸ� 3���� ����ó��

           1. �ڽ��� ���°�
              - ������ ����� �θ𿡼� ������ ����� ��ġ�� nullptr�� ����
              - ��� ����

           2. �ڽ��� �ϳ��� �ִ°�
              - ������ ����� ��ġ�� �ڽ��� �÷��ش�.
              - ��� ����

           3. ���ʿ� �ڽ��� �ִ°�
              - ������ ����� ������ �ڽ��� ���� ���� �ڽ�(���� �ڽ��� ����) ���(����)�� ã�´�

              - ���� ��尡 ������ ����� ��ġ�� ����ϱ����� ���� ����� �������ڽ���
              ���� ����� �θ� ��������ش�. (2���� ���)
                 1. ������ ����� ������ �ڽ��� ������ �� ���
                    - ���� ����� ������ �ڽ��� �θ��� �����ʿ� ����

                 2. ������ ����� ������ �ڽ��� ������ �ƴѰ��
                    - ���� ����� ������ �ڽ��� �θ��� ���ʿ� ����

              - ���� ��尡 ������ ����� ����, ������ �ڽ��� �̾� �޴´�.

              - ��� ����
        */


    }

    int GetNodeCount(Node* node)
    {}

    int GetHeight(Node* node)
    {}

    void InOrder(Node* node, int depth)
    {}
};