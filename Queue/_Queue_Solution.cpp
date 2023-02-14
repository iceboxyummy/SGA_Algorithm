// _Queue_Solution.cpp

#include"stdafx.h"

//==================
// [ Macro ]
//==================
#ifdef QUEUE_SOLUTION

#define 요세푸스순열 // Link: https://www.acmicpc.net/problem/1158

#endif

//==================
// [ 요세푸스 순열 ]
//==================

#ifdef 요세푸스순열

#include<iostream>
#include<queue>

using namespace std;

int main() {

	int N, K;
	cin >> N >> K;
	
	queue<int>queue;

	for (int i = 1; i <= N; i++)
	{
		queue.push(i);
	}

	cout << "<";

	while (queue.size() >1) 
	{
		for (int j = 1; j < K; j++)
		{
			int temp = queue.front();
			queue.pop();
			queue.push(temp);
		}
		cout << queue.front() << ", ";
		queue.pop();
	}
	cout << queue.front() << ">";
}
#endif