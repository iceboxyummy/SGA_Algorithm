#pragma once

// 04_Heap_Tree.h

/*
   �ؿ켱����ť
      �� ������, �ùķ��̼� �ý���, ��Ʈ��ũ Ʈ���� ����, �ü���� �۾� �����층�� ���
      �� �켱���� ť�� �迭, ���Ḯ��Ʈ, ������ ��������
      �� ��Ʈ���� �켱����ť�� ���� �������

   �� �� Ʈ��(Heap Tree)
      �� ���� ����Ʈ���� ����, ª�� ���̶�� �θ���.
      �� �켱���� ť�� ���Ͽ� ������� �ڷᱸ��
      �� �������� ���� �߿��� �ִ밪�̰ų� �ּҰ��� ������ ã�Ƴ����� ������� �ڷᱸ��.
      �� �θ����� Ű���� �ڽĳ�庸�� �׻�ũ��(�۴�) -> �������� ���������� ����.
      �� ū ���� ���� ������ �ְ�, ���� ���� ���� ������ �ִ�.
      �� �ߺ�Ű���� �����

   �� ���� ����

   1. �ִ���(max heap)
      �� �θ� ����� Ű���� �ڽ� ����� Ű�� ���� ũ�ų� ���� ���� ����Ʈ��

   2. �ּ���(min heap)
      �� �θ� ����� Ű���� �ڽ� ����� Ű�� ���� �۰ų� ���� ���� ����Ʈ��


   �� �������� �θ� ���� �ڽ� ����� ����
      �� ������ϰ� �ϱ����ؼ� �ε����� 1������ ������. 0���� �ϴ� ��쵵 ����
      �� ���� ����� �ε����� current��� ������
         - �θ� ����� �ε��� : current / 2
         - �ڽ� Left�� �ε��� : current * 2
         - �ڽ� Right�� �ε��� : current * 2 + 1

   �� ���� ���� ����
      �� ���� ����
         - ���� ���ο� ��Ұ� ������ ���ο� ��带 ���� ������ ��ġ�� �����Ѵ�.
         - ���ο� ��带 �θ� ����� ��ȯ�ذ��鼭 ���� ���� ������Ų��.

      �� ���� ����
         - ��Ʈ�� ���� ��ȯ�� �ϰ�, ��Ʈ�� ��������带 �����Ѵ�.
         - �ٽ� ���� ���� ���鼭 ������ �Ѵ�.
*/

void Swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

#include<Windows.h>
#define MAX_ARRAY_SIZE 256

class MaxHeap
{
public:
    MaxHeap()
    {
        ZeroMemory(values, sizeof(int) * MAX_ARRAY_SIZE);
    }

    void Push(int data) 
    {
        values[++heap_count] = data;

        int current = heap_count;
        int parent = current / 2;

        while (current > 1 && values[current] > values[parent])
        {
            Swap(&values[parent], &values[current]);

            current = parent;
            parent = current / 2;
        }
    }

    int Pop() 
    {
        int result = values[1];

        Swap(&values[1], &values[heap_count--]);
        
        int current = 1;
        int child = current * 2;

        if (child + 1 <= heap_count)
        {
            child = values[child] > values[child + 1] ? child : child + 1;
        }

        while (child <= heap_count && values[current] < values[child])
        {
            Swap(&values[current], &values[child]);

            current = child;
            child = current * 2;

            if (child + 1 <= heap_count)
            {
                child = values[child] > values[child + 1] ? child : child + 1;
            }
        }
        return result;
    }

private:
    int values[MAX_ARRAY_SIZE];
    int heap_count = 0;
};

class MinHeap
{
public:
    MinHeap()
    {
        ZeroMemory(values, sizeof(int) * MAX_ARRAY_SIZE);
    }

    void Push(int data)
    {}

    int Pop()
    {}

private:
    int values[MAX_ARRAY_SIZE];
    int heap_count = 0;
};