#pragma once

// 01_Linear_Queue.h

/*
   ※ 선형 큐
	  ㄴ 데이터가 일렬로 되어있는 형태
	  ㄴ 데이터를 뺄 떄 나머지 데이터를 앞으로 밀어줘야함 -> 비용이 많이듬
*/

#include<iostream>
#include<assert.h>

using namespace std;

class LinearQueue
{
public:
	// 처음에 크기를 받아 생성
	LinearQueue(int size)
		:size(size)
	{
		datas = new int[size];
	}

	~LinearQueue()
	{
		delete[] datas;
		datas = nullptr;
	}

	bool IsFull() { return  rear == (size - 1); }
	bool IsEmpty() { return rear < 0; }

	// 데이터를 삽입한다.
	void Enqueue(int data)
	{
		if (IsFull == false)
			datas[++rear] = data;
		else
			cout << "Is Full" << endl;
	}

	// 데이터를 삭제한다.
	void Dequeue()
	{
		if (IsEmpty() == false)
		{
			for (int i = 1; i < -rear; i++)
				datas[i - 1] = datas[i];
			rear--;
		}
		else
			cout << "Is Empty" << endl;
	}

	int& Front()
	{
		return datas[0];
	}

	int& Back()
	{
		return datas[rear];
	}

private:
	//인덱스를 증가 시키고 넣는다.

	int* datas = nullptr;
	int size = 0;
	int front = 0; // 맨 앞의 원소의 인덱스를 가리킨다.
	int rear = -1; // 마지막 인덱스를 가리킨다. 초기엔 데이터가 없으므로 -1
};