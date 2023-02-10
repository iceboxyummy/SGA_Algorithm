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
    stack<int> s;            // 기본값으로 deque 컨테이너를 사용
    stack<int, vector<int>> sv; // deque 대신에 vector컨테이너 사용
    stack<int, list<int>> sl;   // deque 대신에 list컨테이너 사용

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
	//isdigit('c') : 10진수로 변경할 수 있는 문자가 아니면 0 변환 가능한 값이면 0이외의 값을 반환

	//const char* c = "1 10.5+ 2 * +5 +";

	// c 시작 지점으로부터 숫자까지의 문자를 읽어 double으로 변환하여 리턴
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