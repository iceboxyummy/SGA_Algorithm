// Kruskal.h
#pragma once

/*
   �� ũ�罺Į(Kruskal's) �˰���
      �� ���� ���� �׷����� �־��� ��, "�ּ� ���� Ʈ��"���
      �Ҹ��� ���� �׷����� ã�� �˰���
      �� ũ�罺Į �˰����� Union_Find �ڷᱸ���� ����Ѵ�.

   �� ����Ʈ��
      �� �ش� �׷����� ��� ������ �����ϴ� Ʈ�� ������ ���� �׷���
      �� �׷������� ����Ʈ���� �������� ������ �� �ִ�.
      �� �׷� ����Ʈ���� �߿��� ������ ����ġ�� ���� ���� ���� ����Ʈ����
      �ּ� ���� Ʈ����� �Ѵ�.

   �� ���� ���
      - 1. ��� ������ ���� ���´�.
      - 2. ����ġ ������(��������) �������� �����Ѵ�.
      - 3. ���ĵ� ������ ������� �����Ѵ�.
      - 4. ������ ������ �� ������ ����Ǿ� ���� ������
      �ش� ������ �ּ� ���� Ʈ���� ���Խ�Ű�� �� ������ �����Ѵ�.
      (����Ŭ�� ������ �ȵ�)
      (���������� ������ �Ǿ� �־ ������ �Ǿ��ִٰ� ģ��.)
      (�ּ� ���� Ʈ���� �� ������ �� : �� ����� ���� - 1)
*/

#include<vector>
#include<algorithm>
using namespace std;

class DisjointSetTree
{
public:
    void Init(int node_count)
    {
        parent.clear();
        height.clear();

        parent.shrink_to_fit();
        height.shrink_to_fit();

        for (int i = 0; i < node_count; i++)
        {
            parent.push_back(i);
            height.push_back(1);
        }
    }

    int Find(int v)
    {
        if (parent[v] == v) return v;
        return parent[v] = Find(parent[v]);
    }

    void Union(int v1, int v2)
    {
        v1 = Find(v1);
        v2 = Find(v2);

        if (v1 == v2) return;

        if (height[v1] < height[v2])
            swap(v1, v2);

        parent[v2] = v1;

        if (height[v1] == height[v2])
            height[v1]++;
    }

    bool IsSameSet(int v1, int v2) { return Find(v1) == Find(v2); }

private:
    vector<int> parent;
    vector<int> height;
};

class Kruskal
{
public:
    struct Edge
    {
        Edge() = default;
        Edge(int v1, int v2, int cost) : v1(v1), v2(v2), cost(cost) {}

        int v1, v2; // ������ �� ����
        int cost; // ������ ����ġ

        bool operator <(const Edge& e1) const
        {
            return cost < e1.cost;
        }
    };

public:
    void AddEdge(Edge edge)
    {
        edges.push_back(edge);
    }

    int MakeMST(int node_count)
    {
        uf.Init(node_count);

        sort(edges.begin(), edges.end());
        
        int result = 0;

        for (const Edge& e : edges)
        {
            if (uf.IsSameSet(e.v1, e.v2) == false)
            {
                uf.Union(e.v1, e.v2);
                result += e.cost;
            }
        }
        return result;
    }

private:
    vector<Edge> edges;
    DisjointSetTree uf;
};