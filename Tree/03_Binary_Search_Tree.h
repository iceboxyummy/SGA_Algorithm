#pragma once

// 03_Binary_Search_Tree.h

/*
   ※ 이진 탐색 트리(Binary Search Tree)
	  ㄴ 조건1 : 모든 키값은 유일해야함(중복x)
	  ㄴ 조건2 : 왼쪽 서브트리의 모든 키값들은 root의 키값보다 작다
	  ㄴ 조건3 : 오른쪽 서브트리의 모든 키값들은 root의 키값보다 크다
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

	// 반복문을 통한 탐색
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

	// 재귀 함수를 통한 탐색
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

	// 노드 추가
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

		// root에서 삭제할 key값을 가지는 노드 탐색
		current = *root;

		while (current != nullptr && current->key != key)
		{
			parent = current;
			current = (key < parent->key) ? parent->left : parent->right;
		}

		if (current == nullptr)return;

		if (current->left == nullptr && current->right == nullptr) // 1. 자식이 없을때
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

		else if (current->left == nullptr || current->right == nullptr) // 2. 자식이 하나만 있을때
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

		else // 3. 양쪽에 자식이 있을때
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
		   삭제할 노드를 찾았다면 3가지 예외처리

		   1. 자식이 없을때
			  - 삭제될 노드의 부모에서 삭제될 노드의 위치를 nullptr로 변경
			  - 노드 삭제

		   2. 자식이 하나만 있을때
			  - 삭제할 노드의 위치에 자식을 올려준다.
			  - 노드 삭제

		   3. 양쪽에 자식이 있을때
			  - 삭제될 노드의 오른쪽 자식중 제일 왼쪽 자식(왼쪽 자식이 없는) 노드(후임)를 찾는다

			  - 후임 노드가 삭제될 노드의 위치를 대신하기전에 후임 노드의 오른쪽자식을
			  후임 노드의 부모에 연결시켜준다. (2가지 경우)
				 1. 삭제될 노드의 오른쪽 자식이 후임이 된 경우
					- 후임 노드의 오른쪽 자식을 부모의 오른쪽에 연결

				 2. 삭제될 노드의 오른쪽 자식이 후임이 아닌경우
					- 후임 노드의 오른쪽 자식을 부모의 왼쪽에 연결

			  - 후임 노드가 삭제될 노드의 왼쪽, 오른쪽 자식을 이어 받는다.

			  - 노드 삭제
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