#pragma once

// 03_Ranking_List.h

/*
   �� ��ŷǥ ����� ����

   [menu]
   1. �������Է�
   2. ��ŷǥ Ȯ��
   3. ����
   ����(1-3);
   (����ó��)

   1�� ���ý�
   �Ʒ��� ���� �Է¹���
   x��° ĳ���� �̸� :
   x��° ĳ���� ���� :
   x��°ĳ���� elo : -> ��ŷ�� ��� ����
   �����͸� �Է� �� ������ �ٽ� ���θ޴���

   1�� ���ý�
   �Ʒ��� ���� �Է¹���
   x��° ĳ���� �̸� :
   x��° ĳ���� ���� :
   x��°ĳ���� elo : ->��ŷ�� ��� ����
   �����͸� �Է� �� ������ �ٽ� ���θ޴���

   2�� ���ý�
   ��ŷǥ ���
   -----------------
   ĳ���͸� ��ŷ ���� elo
*/

#include<iostream>

using namespace std;

struct Character
{
    string name;
    int level;
    int elo;
};

class RankingList
{
public:
    struct Node
    {
        Node* prev = nullptr;
        Node* next = nullptr;
        Character* data;
    };

    static Node* Create(Character* data)
    {
        Node* node = new Node();
        node->data = data;
        return node;
    }

    static void Destroy(Node** node)
    {
        delete* node;
        *node = nullptr;
    }

    static Character* CreateCharacter(int index)
    {
        Character* character = new Character();
        cout << index + 1 << "��° ĳ���� �̸� : ";
        cin >> character->name;

        cout << index + 1 << "��° ĳ���� ���� : ";
        cin >> character->level;

        cout << index + 1 << "��° ĳ���� elo : ";
        cin >> character->elo;
        cout << endl;

        return character;
    }

public:

    ~RankingList()
    {
        Clear();
    }

    void PushBack(Character* data)
    {
        Node* node = Create(data);
        if (head == nullptr)
        {
            head = node;
            tail = node;
        }
        else
        {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
        size++;
    }


    void PushFront(Character* data)
    {
        Node* node = Create(data);
        if (head == nullptr)
        {
            head = node;
            tail = node;
        }
        else
        {
            head->prev = node;
            node->next = head;
            head = node;
        }
        size++;
    }

    void PopBack()
    {
        if (size <= 0) return;

        if (size == 1)
        {
            Destroy(&head);
            tail = nullptr;
        }
        else
        {
            Node* temp = tail->prev;
            Destroy(&tail);
            tail = temp;
            tail->next = nullptr;
        }
        size--;
    }

    void PopFront()
    {
        if (size <= 0) return;

        if (size == 1)
        {
            Destroy(&head);
            tail = nullptr;
        }
        else
        {
            Node* temp = head->next;
            Destroy(&head);
            head = temp;
            head->prev = nullptr;
        }
        size--;
    }

    void Insert(Node* target, Character* data)
    {
        Node* temp = head;

        while (temp != nullptr)
        {
            if (temp == target) break;
            temp = temp->next;
        }
        if (temp == nullptr) return;

        if (target == head)
            PushFront(data);
        else
        {
            //  P D T 
            Node* new_node = Create(data);

            new_node->next = target;
            new_node->prev = target->prev;

            new_node->prev->next = new_node;
            new_node->next->prev = new_node;

            size++;
        }
    }

    Node* operator[](int index)
    {
        if (index >= size)
        {
            cout << "�ε��� ����" << endl;
            return nullptr;
        }

        Node* node = head;
        while (node != nullptr && index-- > 0)
            node = node->next;
        return node;
    }

    int Size() { return size; }

    void Clear()
    {
        for (int i = size; i > 0; i--)
            PopBack();
    }

    void PrintList()
    {
        //operator[](0) == (*this)[0]

        for (int i = 0; i < size; i++)
            cout << operator[](i)->data << " ";

        cout << endl;
    }

    void PushCharacter(Character* data)
    {
        if (head == nullptr)
        {
            Node* node = Create(data);
            head = node;
            tail = node;
            size++;
        }
        else
        {
            // 
            //  ?? ?? ?? a
            if (data->elo > head->data->elo)
            {
                PushFront(data);
                return;
            }
            else if (data->elo < tail->data->elo)
            {
                PushBack(data);
                return;
            }

            Node* temp = head->next;
            while (temp != nullptr)
            {
                if (data->elo > temp->data->elo)
                {
                    Insert(temp, data);
                    return;
                }
                temp = temp->next;
            }
        }
    }

    void PrintRank()
    {
        cout << "�̸�\t��ũ\t����\telo" << endl;
        for (int i = 0; i < size; i++)
        {
            cout << operator[](i)->data->name
                << "\t" << i + 1
                << "\t" << operator[](i)->data->level
                << "\t" << operator[](i)->data->elo
                << endl;
        }
    }

protected:
    Node* head = nullptr;
    Node* tail = nullptr;

    int size = 0;
};