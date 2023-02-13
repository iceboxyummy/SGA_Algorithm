#include"stdafx.h"

//===============
// [ Macro ]
//===============

#ifdef QUEUE_MAIN

#define QURUR_STL

#endif 

//===============
// [ QUEUE_STL ]
//===============

#ifdef QUEUE_STL

#include<iostream>
#include<queue>

using namespace std;

int main()
{
    //Enqueue : Push
    //Dequeue : Pop
    //Empty

    // ť�� �ݺ��� ���� x, �������پȵ� -> �ʿ��ϸ� ť�� ���� �ȵȴ�.
    cout << "queue" << endl;
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    while (q.empty() == false)
    {
        cout << q.front() << endl;
        cout << q.back() << endl << endl;

        q.pop();
    }
    cout << endl;

    return 0;
}
#endif