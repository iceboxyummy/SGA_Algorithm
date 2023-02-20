// __Tree_Main.cpp

#include"stdafx.h"

//===============
// [ Macro ]
//===============

#ifdef TREE_MAIN

//#define LSRC_TREE
//#define BINARY_TREE
#define HEAP_TREE

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