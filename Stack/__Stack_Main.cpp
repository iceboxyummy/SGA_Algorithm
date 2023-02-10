 //__Stack_Main.cpp

#include"stdafx.h"

//==================
// [ Macro ]
//==================
#ifdef STACK_MAIN

//#define STACK_STL

#define STACK_CALCULATOR

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

//=============================
// [STACK_CALCULATOR]
//=============================
#ifdef STACK_CALCULATOR
#include<iostream>
#include"03_Stack_Calculator.h"
using namespace std;

int main()
{
	//isdigit('c') : 10������ ������ �� �ִ� ���ڰ� �ƴϸ� 0 ��ȯ ������ ���̸� 0�̿��� ���� ��ȯ

	//const char* c = "1 10.5+ 2 * +5 +";

	// c ���� �������κ��� ���ڱ����� ���ڸ� �о� double���� ��ȯ�Ͽ� ����
	//atof(&c[2]);

	//1 10 2 * +5 +
	{
		char post[256];
		const char* mid = "1+10*2+5";

		Stack_Calculator::MakePostfix(&post[0], mid);

		cout << post << endl;
		cout << Stack_Calculator::CalcPostfix(post) << endl << endl;
	}

	//1 10 +2 *5 +
	{
		char post[256];
		const char* mid = "(1+10)*2+5";

		Stack_Calculator::MakePostfix(&post[0], mid);

		cout << post << endl;
		cout << Stack_Calculator::CalcPostfix(post) << endl << endl;
	}

	// 1.5 1 +
	{
		char post[256];
		const char* mid = "1.5+1";

		Stack_Calculator::MakePostfix(&post[0], mid);

		cout << post << endl;
		cout << Stack_Calculator::CalcPostfix(post) << endl << endl;
	}
	return 0;
}

#endif 