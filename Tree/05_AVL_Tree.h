#pragma once

// 05_AVL_Tree.h

/*
   ※ AVL Tree
      ㄴ 균형 이진 탐색 트리중에 하나이다.
      ㄴ Adelson, Velsky, Landis 라는 사람들이 만들어서 AVL이다.

   ※ 균형 이진 탐색 트리
      ㄴ 각 노드에서 왼쪽 서브트리의 높이와 오른쪽 서브트리의 높이차가 1이하인 이진 트리이다.
      ㄴ 시간 복잡도는 O(log n)

   ※ 균형 이진 탐색 트리의 삽입
      ㄴ 새로운 노드를 삽입 후, 불균형 상태로 변한 가장 가까운 조상노드의 서브트리들에 대하여 다시 균형을 잡는다.

   ※ 균형을 나타내는 방법
      ㄴ 균형 인수 (Balance Factor)라는 것을 이용한다.
      ㄴ 균형 인수는 왼쪽 자식의 높이에서 오른쪽 자식의 높이를 뺀 것이다.
      ㄴ 균형 인수가 2 이상이거나 -2 이하일 때 균형이 깨졌다고 한다.

   ※ 균형이 깨지는 조건 4가지
      - 1. LL ( Left   - Left   ) : 새로운 노드가 조상노드의 읜쪽 서브트리의 왼쪽 서브트리에 삽입되는 경우
      - 2. RR ( Right   - Right   ) : 새로운 노드가 조상노드의 오른쪽 서브트리의 오른쪽 서브트리에 삽입되는 경우
      - 3. RL ( Right   - Left   ) : 새로운 노드가 조상노드의 오른쪽 서브트리의 왼쪽 서브트리에 삽입되는 경우
      - 4. LR ( Left   - Right   ) : 새로운 노드가 조상노드의 읜쪽   서브트리의 오른쪽 서브트리에 삽입되는 경우

   ※ 균형을 이루기 위해 재배열을 하는 4가지 방법
      - 1. LL 회전 : 조상노드부터 새로운 노드까지의 경로상의 노드들을 오른쪽으로 회전시킨다.
         ㄴ 조상노드를 A, 조상 왼쪽 자식을 B 라고 했을 때 A의 Left에 B의 Right를 연결하고, B의 Right에 A를 연결한다.

      - 2. RR 회전 : 조상노드부터 새로운 노드까지의 경로상의 노드들을 왼쪽으로 회전시킨다.
         ㄴ 조상노드를 A, 조상 오른쪽 자식을 B 라고 했을 때 A의 Right에 B의 Left를 연결하고, B의 Left에 A를 연결한다.

      - 3. RL 회전 : 조상노드부터 새로운 노드가지의 경로상의 노드들을 오른쪽 회전후에 왼쪽으로 회전시킨다.
         ㄴ A의 오른쪽 자식에 = LL( B ), RR( A )

      - 4. LR 회전 : 조상노드부터 새로운 노드가지의 경로상의 노드들을 왼쪽 회전후에 오른쪽으로 회전시킨다.
         ㄴ A의 왼쪽 자식에 = RR( B ), LL( A )
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

        else if (data < root->data)
        {
            root->left = Insert(root->left, data);
            root = Balance(root);
        }

        else if (data >= root->data)
        {
            root->right = Insert(root->right, data);
            root = Balance(root);
        }
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
    {
        Node* node = root;

        while (node != nullptr)
        {
            if (data == node->data)
                return node;
            else if (data < node->data)
                node = node->left;
            else
                node = node->right;
        }
        return nullptr;
    }

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
        int height = 0;

        if (node != nullptr)
        {
            int left = Height(node->left);
            int right = Height(node->right);
            int maxHeight = max(left, right);

            height = 1 + maxHeight;
        }
        return height;
    }

    // node 기준으로 균형차이값 계산
    int Diff(Node* node)
    {
        int left = Height(node->left);
        int right = Height(node->right);
        int factor = left - right;

        return factor;
    }

    // 각 케이스 처리
    Node* RR(Node* parent)
    {
        Node* temp = parent->right;
        parent->right = temp->left;
        temp->left = parent;

        return temp;
    }

    Node* LL(Node* parent)
    {
        Node* temp = parent->left;
        parent->left = temp->right;
        temp->right = parent;

        return temp;
    }

    Node* LR(Node* parent)
    {
        Node* temp = parent->left;
        parent->left = RR(temp);

        return LL(parent);
    }

    Node* RL(Node* parent)
    {
        Node* temp = parent->right;
        parent->right = LL(temp);

        return RR(parent);
    }

    // node 기준으로 균형 검사후 균형이 맞지않을 경우 4가지 케이스중에 알맞게 골라서 처리
    Node* Balance(Node* node)
    {
        Node* temp = node;

        int factor = Diff(node);

        if (factor > 1)
        {
            if (Diff(temp->left) > 0)
                temp = LL(temp);
            else
                temp = LR(temp);
        }

        else if (factor < -1)
        {
            if (Diff(temp->right) > 0)
                temp = RL(temp);
            else
                temp = RR(temp);
        }
        return temp;
    }
};