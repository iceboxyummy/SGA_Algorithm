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

    bool IsFull()
    {
        if (rear < size - 1)
            return false;
        else true;
    }

    bool IsEmpty()
    {
        if (rear == -1)
            return true;
        else false;
    }

    // �����͸� �����Ѵ�.
    void Enqueue(int data)
    {
        if (rear < size - 1)
            datas[++rear] = data;
        else
            cout << "error" << endl;
    }

    // �����͸� �����Ѵ�.
    void Dequeue()
    {
        for (int i = 1; i < size; i++)
        {
            datas[front + i] = datas[front + i + 1];
        }
        rear--;
    }

    int& Front()
    {
        return datas[front];
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