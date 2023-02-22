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
		while (node != nullptr)
		{
			if (key == node->key)
				return node;
			else if (key < node->key)
				node = node->left;
			else
				node = node->right;
		}
		return nullptr;
	}

	// ��� �Լ��� ���� Ž��
	Node* SearchRecurrsive(Node* node, int key)
	{
		if (node == nullptr) return nullptr;

		if (key == node->key)
			return node;
		else if (key > node->key)
			SearchRecurrsive(node->right, key);
		else
			SearchRecurrsive(node->left, key);
	}

	// ��� �߰�
	void InsertNode(Node** root, int key)
	{
		Node* parent = nullptr;
		Node* current = nullptr;
		Node* new_node = Create(key);

		current = *root;

		while (current != nullptr)
		{
			if (key == current->key)
			{
				Delete(&new_node);
				return;
			}

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
		Node* parent = nullptr;
		Node* current = nullptr;
		Node* child = nullptr;
		Node* prev = nullptr;
		Node* next = nullptr;

		// root���� ������ key���� ������ ��� Ž��
		current = *root;

		while (current != nullptr && current->key != key)
		{
			parent = current;
			current = (key < parent->key) ? parent->left : parent->right;
		}

		if (current == nullptr)return;

		if (current->left == nullptr && current->right == nullptr) // 1. �ڽ��� ������
		{
			if (parent != nullptr)
			{
				if (parent->left == current)
					parent->left = nullptr;
				else
					parent->right = nullptr;
			}
			else
				*root = nullptr;
		}

		else if (current->left == nullptr || current->right == nullptr) // 2. �ڽ��� �ϳ��� ������
		{
			child = current->left != nullptr ? current->left : current->right;

			if (parent != nullptr)
			{
				if (parent->left == current)
					parent->left = child;
				else
					parent->right = child;
			}
			else
				*root = child;
		}

		else // 3. ���ʿ� �ڽ��� ������
		{
			prev = current;
			next = current->right;
			while (next->left != nullptr)
			{
				prev = next;
				next = next->left;
			}

			if (prev == current)
				prev->right = next->right;
			else
				prev->left = next->right;

			next->left = current->left;
			next->right = current->right;

			if (parent == nullptr)*root = next;
		}
		Delete(&current);

		/*
		   ������ ��带 ã�Ҵٸ� 3���� ����ó��

		   1. �ڽ��� ������
			  - ������ ����� �θ𿡼� ������ ����� ��ġ�� nullptr�� ����
			  - ��� ����

		   2. �ڽ��� �ϳ��� ������
			  - ������ ����� ��ġ�� �ڽ��� �÷��ش�.
			  - ��� ����

		   3. ���ʿ� �ڽ��� ������
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
	{
		int count = 0;
		if (node != nullptr)
			count = 1 + GetNodeCount(node->left) + GetNodeCount(node->right);
		return count;
	}

	int GetHeight(Node* node)
	{
		int height = -1;
		if (node != nullptr)
		{
			height = 1 + max(GetHeight(node->left), GetHeight(node->right));
		}
		return height;
	}

	void InOrder(Node* node, int depth)
	{
		if (node == nullptr) return;

		InOrder(node->left, depth + 1);

		for (int i = 0; i < depth; i++)
			cout << "-";
		cout << node->key << endl;

		InOrder(node->right, depth + 1);
	}
};