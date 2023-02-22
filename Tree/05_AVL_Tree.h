#pragma once

// 05_AVL_Tree.h

/*
    �� AVL Tree
        �� ���� ���� Ž�� Ʈ���߿� �ϳ��̴�.
        �� Adelson, Velsky, Landis ��� ������� ���� AVL�̴�.

    �� ���� ���� Ž�� Ʈ��
        �� �� ��忡�� ���� ����Ʈ���� ���̿� ������ ����Ʈ���� �������� 1������ ���� Ʈ���̴�.
        �� �ð� ���⵵�� O(log n)

    �� ���� ���� Ž�� Ʈ���� ����
        �� ���ο� ��带 ���� ��, �ұ��� ���·� ���� ���� ����� �������� ����Ʈ���鿡 ���Ͽ� �ٽ� ������ ��´�.

    �� ������ ��Ÿ���� ���
        �� ���� �μ� (Balance Factor)��� ���� �̿��Ѵ�.
        �� ���� �μ��� ���� �ڽ��� ���̿��� ������ �ڽ��� ���̸� �� ���̴�.
        �� ���� �μ��� 2 �̻��̰ų� -2 ������ �� ������ �����ٰ� �Ѵ�.

    �� ������ ������ ���� 4����
        - 1. LL ( Left   - Left   ) : ���ο� ��尡 �������� ���� ����Ʈ���� ���� ����Ʈ���� ���ԵǴ� ���
        - 2. RR ( Right   - Right   ) : ���ο� ��尡 �������� ������ ����Ʈ���� ������ ����Ʈ���� ���ԵǴ� ���
        - 3. RL ( Right   - Left   ) : ���ο� ��尡 �������� ������ ����Ʈ���� ���� ����Ʈ���� ���ԵǴ� ���
        - 4. LR ( Left   - Right   ) : ���ο� ��尡 �������� ����   ����Ʈ���� ������ ����Ʈ���� ���ԵǴ� ���

    �� ������ �̷�� ���� ��迭�� �ϴ� 4���� ���
        - 1. LL ȸ�� : ��������� ���ο� �������� ��λ��� ������ ���������� ȸ����Ų��.
            �� �����带 A, ���� ���� �ڽ��� B ��� ���� �� A�� Left�� B�� Right�� �����ϰ�, B�� Right�� A�� �����Ѵ�.

        - 2. RR ȸ�� : ��������� ���ο� �������� ��λ��� ������ �������� ȸ����Ų��.
            �� �����带 A, ���� ������ �ڽ��� B ��� ���� �� A�� Right�� B�� Left�� �����ϰ�, B�� Left�� A�� �����Ѵ�.

        - 3. RL ȸ�� : ��������� ���ο� ��尡���� ��λ��� ������ ������ ȸ���Ŀ� �������� ȸ����Ų��.
            �� A�� ������ �ڽĿ� = LL( B ), RR( A )

        - 4. LR ȸ�� : ��������� ���ο� ��尡���� ��λ��� ������ ���� ȸ���Ŀ� ���������� ȸ����Ų��.
            �� A�� ���� �ڽĿ� = RR( B ), LL( A )
*/

#include <algorithm>
#include <iostream>
#include <iomanip>
#include <queue>
using namespace std;

class AVL
{
public:
    struct Node
    {
        int data;

        Node* left = nullptr;
        Node* right = nullptr;
    };

    static Node* Create(int data)
    {
        Node* node = new Node();
        node->data = data;

        return node;
    }

    static void Destroy(Node** node)
    {
        delete(*node);
        *node = nullptr;
    }

public:
    Node* Insert(Node* root, int data)
    {
        if (root == nullptr)
            return Create(data);

        return root;
    }

    void InOrder(Node* node)
    {
        if (node == nullptr) return;
        InOrder(node->left);
        cout << node->data << " ";
        InOrder(node->right);
    }

    Node* Find(Node* root, int data)
    {}

    void Display(Node* root, int depth, int width)
    {
        if (root == nullptr) return;

        if (root->left != nullptr)
            Display(root->left, depth + 1, width / 2);

        for (int i = 0; i < depth; i++)
            cout << endl;

        for (int i = 0; i < depth + 1; i++)
            cout << setw(width);

        if (root != nullptr)
            cout << root->data;
        else
            cout << " ";

        if (root->right != nullptr)
            Display(root->right, depth + 1, width / 2);
    }

private:
    int Height(Node* node)
    {
        int h;

    }

    // node �������� �������̰� ���
    int Diff(Node* node)
    {}

    // �� ���̽� ó��
    Node* RR(Node* parent)
    {
        Node* temp;
        temp = parent->right;
        parent->right = temp->left;
        temp->left = parent;
        return temp;
    }

    Node* LL(Node* parent)
    {
        Node* temp;
        temp = parent->left;
    }

    Node* LR(Node* parent)
    {}

    Node* RL(Node* parent)
    {}

    // node �������� ���� �˻��� ������ �������� ��� 4���� ���̽��߿� �˸°� ��� ó��
    Node* Balance(Node* node)
    {}

};