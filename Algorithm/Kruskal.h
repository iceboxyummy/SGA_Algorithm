#pragma once

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
    DisjointSetTree(int node_count)
    {
        for (int i = 0; i < node_count; i++)
        {
            parent.push_back(i);
            height.push_back(1);
            group_size.push_back(1);
        }
    }

    int Find(int v)
    {
        // ��� ����(Path Compression)
        // -> Ž���� �� �ڽ��� �θ� ��� ��Ʈ�� �ٲ��־� Ž���ð��� ���δ�.
        if (parent[v] == v) return v;
        return parent[v] = Find(parent[v]);
    }

    // ��ũ ���� (rank Compression)
    // -> ���� ������ ū ���տ� �����ش�.
    void Union1(int v1, int v2) // Union by Rank
    {
        v1 = Find(v1);
        v2 = Find(v2);

        if (v1 == v2) return;

        // ����(����)�� ū ������ v1�� �����Ѵ�.
        if (height[v1] < height[v2])
            swap(v1, v2);

        // v2�� ������ v1�� �ٲپ� �ش�.
        // -> v2 ��ǥ ����(��Ʈ)�� v1�� ����(��Ʈ)�� �ڽ����� �����.
        parent[v2] = v1;

        // Ʈ���� ���̰� ���� ��� ���̰� �����ϰ� �ȴ�.
        if (height[v1] == height[v2])
            height[v1]++;
    }

    void Union2(int v1, int v2) // Union by Size
    {
        v1 = Find(v1);
        v2 = Find(v2);

        if (v1 == v2) return;

        // ũ�Ⱑ ū ������ v1�� �����Ѵ�.
        if (group_size[v1] < group_size[v2])
            swap(v1, v2);

        // v2�� ������ v1�� �ٲپ� �ش�.
        // -> v2 ��ǥ ����(��Ʈ)�� v1�� ����(��Ʈ)�� �ڽ����� �����.
        parent[v2] = v1;

        // ���� ũ�⸦ �����ش�.
        group_size[v1] += group_size[v2];
    }

private:
    vector<int> parent;   // �� ���Ұ� ����Ű�� �θ� 
    vector<int> height;   // �� ������ ����
    vector<int> group_size;   // �� ������ ũ��
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

    Kruskal(int nodeCount)
        :uf(nodeCount)
    {}

public:
    void AddEdge(Edge edge)
    {
        edges.push_back(edge);
    }

    int MakeMST(int node_count)
    {
        sort(edges.begin(), edges.end());
        
        int sum = 0;

        for (int i = 0; i < edges.size(); i++)
        {
            if ()
            {
                sum += edges[i].cost;
            }
        }
    }

private:
    vector<Edge> edges;
    DisjointSetTree uf;
};