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
        if (top + 1 == size)
            std::cout << "Is Full" << endl;
        else
            datas[++top] = data;
    }

    T& Top()
    {
        return T[top];
    }

    void Pop()
    {
        if (top == -1)
            std::cout << "Is Empty" << std::endl;
        else
            datas[top--];
    }

    bool IsEmpty()
    {
        if (top == -1)  return true;
        else return false;
    }

private:
    T* datas = nullptr;   // ������
    int top = -1;      // �ֻ��� �������� ��ġ
    int size = 0;      // �ִ� ������
};