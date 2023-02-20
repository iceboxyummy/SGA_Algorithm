#pragma once

//01_LCRS_Tree.h

/*
   ※ LCRS-Tree
      ㄴ Left-Child, Right-Sibling
      ㄴ 왼쪽은 자식을, 오른쪽은 형제를 가리키는 트리

   ※ 예시)

        A
       /
     B -> C -> D
    /        /
   E       F
*/

#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class LCRS_Tree
{
public:
    struct Node
    {
        char data;
        Node* left_child = nullptr;
        Node* right_sibling = nullptr;
    };

    static Node* Create(char data)
    {
        Node* node = new Node();
        node->data = data;
        return node;
    }

    static void Delete(Node** node)
    {
        delete(*node);
        *node = nullptr;
    }

public:
	void AddChild(Node* parent, Node* child)
	{
		if (parent->left_child == nullptr)
			parent->left_child = child;
		else
		{
			Node* node = parent->left_child;
			while (node->right_sibling != nullptr)
				node = node->right_sibling;
			node->right_sibling = child;
		}
	}

	// 전위 순회
    void PrintNode(Node* node, int level)
    {
        for (int i = 0; i < level; i++)
            cout << "-";

        cout << node->data << endl;

        if (node->left_child != nullptr)
            PrintNode(node->left_child, level + 1);

        if (node->right_sibling != nullptr)
            PrintNode(node->right_sibling, level);
    }

    // 재귀
    Node* GetNode(Node* root, char data) 
    {
        Node* node = nullptr;

        if (root->data == data)
            return root;

        else
        {
            if (root->left_child != nullptr)
                node = GetNode(root->left_child, data);

            if (node != nullptr)
                return node;

            if (root->right_sibling != nullptr)
                node = GetNode(root->right_sibling, data);
        }

        return node;
    }

    Node* GetNode2(Node* root, char data)
    {
        stack<Node*> stack;

        stack.push(root);

        while (stack.empty() != true)
        {
            Node* node = stack.top();
            stack.pop();

            if (node == nullptr) continue;

            if (node->data == data)
                return node;

            if (root->right_sibling != nullptr)
                stack.push(root->right_sibling);

            if (root->left_child != nullptr)
                stack.push(root->left_child);
        }
    }

    void GetNodes(Node* root, char data, vector<Node*>& vec)
    {
        if (root->data == data)
            vec.push_back(root);

        if (root->left_child != nullptr)
            GetNodes(root->left_child, data, vec);
     
        if (root->left_child != nullptr)
            GetNodes(root->left_child, data, vec);
    }
};