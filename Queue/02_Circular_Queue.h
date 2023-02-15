#pragma once

// 02_Circular_Queue.h

/*
   �� ȯ�� ť
      �� ó���� ���� �������� �̾��� �ִ� ����
      �� �ڵ� �����δ� 1���� �迭������ �����·� �����
      �� ����� ��ȭ ���¸� ���ϱ����� �ϳ��� ������ �׻� ����־� �Ѵ�.
         - ���� ���� : rear == front
         - ��ȭ ���� : (rear + 1) % size == front
*/

#include<iostream>

using namespace std;

template<typename T>
class CircularQueue
{
public:
    CircularQueue(int size)
        :size(size)
    {
        datas = new T[size];
    }

    ~CircularQueue()
    {
        delete[] datas;
    }

    bool IsFull() { return (rear + 1) % size == front; }
    bool Empty() { return rear == front; }

	void Enqueue(T data)
	{
		if (IsFull == false)
		{
            // ȯ�� ���·� �ٷ�� ���� %size�Ͽ� �ε��� ���� ��ȯ�ϵ��� �Ѵ�.
			rear = (rear + 1) % size;
			datas[rear] = data;
		}
		else
			cout << "Is Full" << endl;
	}

    void Dequeue() 
    {
        if (Empty == false)
            front = (front + 1) % size;
        else
            cout << "Is Empty" << endl; 
    }

    T& Front() { return datas[(front + 1) % size]; }

    void ViewIndex()
    {
        cout << "Current Front Index : " << front << endl;
        cout << "Current Rear Index : " << rear << endl;
        cout << endl;
    }

private:
    T* datas = nullptr;
    int front = 0; // ù�� ° ������ �� �ε����� ����Ų��.
    int rear = 0; // ������ ������ �ε����� ����Ų��.
    int size = 0;
};