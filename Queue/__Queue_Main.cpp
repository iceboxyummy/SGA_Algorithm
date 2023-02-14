#include"stdafx.h"

//===============
// [ Macro ]
//===============

#ifdef QUEUE_MAIN

//#define QUEUE_STL
#define MY_QUEUE_STL

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

//===============
// [ MY QUEUE_STL ]
//===============

#ifdef MY_QUEUE_STL

#include<iostream>
#include"01_Linear_Queue.h"

using namespace std;

int main()
{
    cout << "LinearQueue" << endl;
    LinearQueue lq(5);

    lq.Enqueue(10);
    lq.Enqueue(20);
    lq.Enqueue(30);
    lq.Enqueue(40);
    lq.Enqueue(50);
    lq.Enqueue(60); // ������!!!

    while (lq.IsEmpty() == false)
    {
        cout << lq.Front() << endl;
        cout << lq.Back() << endl << endl;
        lq.Dequeue();
    }

    return 0;
}
#endif