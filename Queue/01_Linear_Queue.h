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

    // 데이터를 삽입한다.
    void Enqueue(int data)
    {
        if (rear < size - 1)
            datas[++rear] = data;
        else
            cout << "error" << endl;
    }

    // 데이터를 삭제한다.
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
    //인덱스를 증가 시키고 넣는다.

    int* datas = nullptr;
    int size = 0;
    int front = 0; // 맨 앞의 원소의 인덱스를 가리킨다.
    int rear = -1; // 마지막 인덱스를 가리킨다. 초기엔 데이터가 없으므로 -1
};