#pragma once

// 02_Binary_Tree.h

/*
   ※ 이진 트리(Binary Tree)
      ㄴ 트리의 차수가 2이하인 트리
      ㄴ 노드가 정렬되어 있을 경우 탐색에 유리함
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
    // 해당 key값을 가지는 노드 생성후 트리에 추가하기
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