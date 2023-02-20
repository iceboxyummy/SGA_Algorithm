// __Link_List_Main.cpp

#include"stdafx.h"

//===============
// [ Macro ]
//===============

#ifdef LINKED_LIST_MAIN

//#define LINKED_LIST
#define DOUBLE_LINKED_LIST

#endif 

//==================
// [ LINKED_LIST ]
//==================

#ifdef LINKED_LIST

#include<iostream>
#include<list>

using namespace std;

int main()
{
	list<int> l;

	l.push_back(10);
	l.push_back(20);
	l.push_front(0);
	l.push_front(-10);
	//l[1]; //error : ���� ���� �Ұ���

	//=========================================================================
	// [ �ε����� �̿��� ������ �ȵǹǷ� iterator�� ����Ͽ� ���������� �����Ѵ�. ]
	//=========================================================================
	{
		//for (int i = 0; i < l.size(); i++)
		//   l[i]; // error

		list<int>::iterator iter = l.begin();
		for (iter; iter != l.end(); ++iter)
			cout << *iter << " ";
		cout << endl;
	}

	//============================================================
	// [ Insert(iter, data) : �ش� iter ��ġ�� ���Ҹ� �߰��Ѵ�. ]
	//============================================================
	{
		list<int>::iterator iter = l.begin();
		iter = l.begin();
		iter++;
		iter++;
		iter++;
		// -10 0 10 20
		l.insert(iter, 100); // insert(��� �������ΰ�?, ������)
		for (iter = l.begin(); iter != l.end(); ++iter)
			cout << *iter << " ";
		cout << endl;
	}

	//==========================================================
	// [ erase(iter) : �ش� iter�� ����Ű�� ���Ҹ� �����Ѵ�. ]
	//==========================================================
	{
		list<int>::iterator iter = l.begin();

		iter = l.end();
		iter--; 
		iter--;
		l.erase(iter);

		for (iter = l.begin(); iter != l.end(); ++iter)
			cout << *iter << " ";
		cout << endl;
	}

	//===========================================================
	// [remove(data) : �ش� data�� ������ ��� ���Ҹ� �����Ѵ�.
	//===========================================================
	{
		list<int>::iterator iter = l.begin();

		l.remove(0);
		for (iter = l.begin(); iter != l.end(); ++iter)
			cout << *iter << " ";
		cout << endl;
	}

	l.clear();

	return 0;
}
#endif

//=========================
// [ DOUBLE LINKED_LIST ]
//=========================

#ifdef DOUBLE_LINKED_LIST

#include"02_Double_Linked_List.h"
#include<iostream>

using namespace std;

int main()
{
	DoubleLinkedList<int> d1;
	d1.PushBack(10);
	d1.PushBack(20);
	d1.PushBack(30);
	d1.PushBack(40);
	d1.PushFront(0);
	d1.PushFront(-10);
	d1.PrintList();

	d1.PopBack();
	d1.PopFront();
	d1.PrintList();

	d1.Insert(d1[3], 100);
	d1.Insert(d1[3], 200);
	d1.PrintList();

	return 0;
}
#endif