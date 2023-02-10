#pragma once

 // 01_Array_Stack 

/*
   �� �迭�� ������ ����
      �� ���� �� �������� �ε����� top�̶�� ������ �ξ� �����Ѵ�.
      �� ó�� top�� ��ġ�� �ƹ� �����͵� ������ -1���� �����Ѵ�.
*/

#include<iostream>
#include<assert.h>

template<typename T>
class ArrayStack
{
public:
    ArrayStack(int size)
        :size(size)
    {
        datas = new T[size];
    }

    ~ArrayStack()
    {
        delete[] datas;
    }

    bool Push(T data)
    {
        if (top < size - 1)
        {
            datas[++top] = data;
            return true;
        }
        else
            return false;
    }

    T& Top()
    {
        assert(top != -1);
        return datas[top];
    }

    void Pop()
    {
        assert(top != -1);
        --top;
    }

	bool IsEmpty() { return top == -1; }

private:
    T* datas = nullptr;   // ������
    int top = -1;      // �ֻ��� �������� ��ġ
    int size = 0;      // �ִ� ������
};