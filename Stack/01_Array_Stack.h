#pragma once

 // 01_Array_Stack 

/*
   ※ 배열로 구현한 스택
      ㄴ 가장 윗 데이터의 인덱스를 top이라는 변수를 두어 관리한다.
      ㄴ 처음 top의 위치는 아무 데이터도 없으니 -1에서 시작한다.
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
    T* datas = nullptr;   // 데이터
    int top = -1;      // 최상위 데이터의 위치
    int size = 0;      // 최대 사이즈
};