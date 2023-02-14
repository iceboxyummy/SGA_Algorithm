#pragma once

// 01_Linear_Queue.h

/*
   �� ���� ť
	  �� �����Ͱ� �Ϸķ� �Ǿ��ִ� ����
	  �� �����͸� �� �� ������ �����͸� ������ �о������ -> ����� ���̵�
*/

#include<iostream>
#include<assert.h>

using namespace std;

class LinearQueue
{
public:
	// ó���� ũ�⸦ �޾� ����
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

	// �����͸� �����Ѵ�.
	void Enqueue(int data)
	{
		if (IsFull == false)
			datas[++rear] = data;
		else
			cout << "Is Full" << endl;
	}

	// �����͸� �����Ѵ�.
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
	//�ε����� ���� ��Ű�� �ִ´�.

	int* datas = nullptr;
	int size = 0;
	int front = 0; // �� ���� ������ �ε����� ����Ų��.
	int rear = -1; // ������ �ε����� ����Ų��. �ʱ⿣ �����Ͱ� �����Ƿ� -1
};