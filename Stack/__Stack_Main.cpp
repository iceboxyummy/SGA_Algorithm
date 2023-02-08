 //__Stack_Main.cpp

#include"stdafx.h"

//==================
// [ Macro ]
//==================
#ifdef STACK_MAIN

#endif

//==================
// [ STACK_STL ]
//==================

#ifdef STACK_STL

#include<iostream>
#include<stack>
#include<vector>
#include<list>
using namespace std;

int main()
{
    stack<int> s;            // �⺻������ deque �����̳ʸ� ���
    stack<int, vector<int>> sv; // deque ��ſ� vector�����̳� ���
    stack<int, list<int>> sl;   // deque ��ſ� list�����̳� ���

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    while (s.empty() != true)
    {
        cout << s.top() << endl;
        s.pop();
    }

#endif