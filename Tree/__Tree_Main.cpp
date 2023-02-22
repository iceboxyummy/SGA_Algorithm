// __Tree_Main.cpp

#include"stdafx.h"

//===============
// [ Macro ]
//===============

#ifdef TREE_MAIN

//#define LSRC_TREE
//#define BINARY_TREE
//#define BINARY_SEARCH_TREE
//#define HEAP_TREE
#define AVL_TREE

#endif 

//==================
// [ LCRS TREE ]
//==================

#ifdef LCRS_TREE

#include<iostream>
#include"01_LCRS_Tree.h"

using namespace std;

int main()
{
    LCRS_Tree::Node* Root = LCRS_Tree::Create('R');
    LCRS_Tree::Node* A = LCRS_Tree::Create('A');
    LCRS_Tree::Node* B = LCRS_Tree::Create('B');
    LCRS_Tree::Node* C = LCRS_Tree::Create('C');
    LCRS_Tree::Node* D = LCRS_Tree::Create('D');
    LCRS_Tree::Node* E = LCRS_Tree::Create('E');
    LCRS_Tree::Node* F = LCRS_Tree::Create('F');
    LCRS_Tree::Node* G = LCRS_Tree::Create('G');

    LCRS_Tree tree;
    tree.AddChild(Root, A);
    tree.AddChild(Root, B);

    tree.AddChild(A, C);
    tree.AddChild(A, D);

    tree.AddChild(C, E);
    tree.AddChild(C, F);

    tree.AddChild(B, G);

    tree.PrintNode(Root, 0);

    LCRS_Tree::Node* temp = tree.GetNode(Root, 'G');

    vector<LCRS_Tree::Node*> vec;

    tree.GetNodes(Root, 'G', vec);

    for (auto& iter : vec)
    {
        cout << iter->data << endl;
        cout << iter << endl;
    }
    return 0;
}
#endif

//==================
// [ BINARY TREE ]
//==================

#ifdef BINARY_TREE

#include<iostream>
#include"02_Binary_Tree.h"

using namespace std;

int main()
{
    BinaryTree::Node* root = nullptr;

    BinaryTree::InsertNode(&root, 150);
    BinaryTree::InsertNode(&root, 200);
    BinaryTree::InsertNode(&root, 325);
    BinaryTree::InsertNode(&root, 175);
    BinaryTree::InsertNode(&root, 60);
    BinaryTree::InsertNode(&root, 90);
    BinaryTree::InsertNode(&root, 80);

    cout << "PreOrder : ";
    BinaryTree::PreOrder(root);
    cout << endl;

    cout << "InOrder : ";
    BinaryTree::InOrder(root);
    cout << endl;

    cout << "PostOrder : ";
    BinaryTree::PostOrder(root);
    cout << endl;

    return 0;
}
#endif

//==================
// [ BINARY TREE ]
//==================

#ifdef BINARY_SEARCH_TREE

#include<iostream>
#include"03_Binary_Search_Tree.h"

using namespace std;

int main()
{
    BST Tree;
    BST::Node* Root = BST::Create(100);

    Tree.InsertNode(&Root, 50);
    Tree.InsertNode(&Root, 75);
    Tree.InsertNode(&Root, 30);
    Tree.InsertNode(&Root, 150);
    Tree.InsertNode(&Root, 175);
    Tree.InsertNode(&Root, 125);
    Tree.InsertNode(&Root, 110);
    Tree.InsertNode(&Root, 100);

    cout << Tree.SearchIteration(Root, 125)->key << endl;
    cout << Tree.SearchRecurrsive(Root, 125)->key << endl;

    // 이진 탐색 트리에서 중위 순회를 할 경우 오름차순으로 값이 출력된다.
    cout << endl;
    Tree.InOrder(Root, 0);

    Tree.DeleteNode(&Root, 125);

    cout << endl;
    Tree.InOrder(Root, 0);

    cout << "Height : " << Tree.GetHeight(Root) << endl;
    cout << "Node Count : " << Tree.GetNodeCount(Root) << endl;

    return 0;
}
#endif

//==================
// [ HEAP TREE ]
//==================

#ifdef HEAP_TREE

#include<iostream>
#include"04_Heap_Tree.h"

using namespace std;

int main()
{
    MaxHeap mh;
    for (int i = 0; i < 255; i++)
        mh.Push(rand() % 10);

    for (int i = 0; i < 255; i++)
        cout << mh.Pop() << endl;

    return 0;
}
#endif 

//==================
// [ AVL TREE ]
//==================

#ifdef AVL_TREE

#include "05_AVL_Tree.h"
#include<iomanip>

int main()
{
   AVL avl;
   AVL::Node* root = nullptr;
   root = avl.Insert(root, 5);
   root = avl.Insert(root, 15);
   root = avl.Insert(root, 25);
   root = avl.Insert(root, 18);
   root = avl.Insert(root, 37);
   root = avl.Insert(root, 1);
   root = avl.Insert(root, 3);
   root = avl.Insert(root, 9);
   root = avl.Insert(root, 12);
   root = avl.Insert(root, 14);
   root = avl.Insert(root, 20);
   root = avl.Insert(root, 80);
   root = avl.Insert(root, 7);

   //avl.Display(root);

   return 0;
}

#endif 