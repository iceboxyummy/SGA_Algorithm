#pragma once

// Kruskal.h
#pragma once

/*
   ※ 크루스칼(Kruskal's) 알고리즘
      ㄴ 무향 연결 그래프가 주어질 때, "최소 신장 트리"라고
      불리는 서브 그래프를 찾는 알고리즘
      ㄴ 크루스칼 알고리즘은 Union_Find 자료구조를 사용한다.

   ※ 신장트리
      ㄴ 해당 그래프의 모든 정점을 포함하는 트리 형태의 서브 그래프
      ㄴ 그래프에서 신장트리는 여러개가 존재할 수 있다.
      ㄴ 그런 신장트리들 중에서 간선의 가중치의 합이 가장 작은 신장트리를
      최소 신장 트리라고 한다.

   ※ 구현 방법
      - 1. 모든 간선을 끊어 놓는다.
      - 2. 가중치 순으로(오름차순) 간선들을 정렬한다.
      - 3. 정렬된 간선을 순서대로 선택한다.
      - 4. 선택한 간선의 두 정점이 연결되어 있지 않으면
      해당 간선을 최소 신장 트리에 포함시키고 두 정점을 연결한다.
      (사이클이 있으면 안됨)
      (간접적으로 연결이 되어 있어도 연결이 되어있다고 친다.)
      (최소 신장 트리의 총 간선의 수 : 총 노드의 개수 - 1)
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
        // 경로 압축(Path Compression)
        // -> 탐색할 때 자식의 부모를 모두 루트로 바꿔주어 탐색시간을 줄인다.
        if (parent[v] == v) return v;
        return parent[v] = Find(parent[v]);
    }

    // 랭크 압축 (rank Compression)
    // -> 작은 집합을 큰 집합에 합쳐준다.
    void Union1(int v1, int v2) // Union by Rank
    {
        v1 = Find(v1);
        v2 = Find(v2);

        if (v1 == v2) return;

        // 높이(깊이)가 큰 집합이 v1로 오게한다.
        if (height[v1] < height[v2])
            swap(v1, v2);

        // v2의 집합을 v1로 바꾸어 준다.
        // -> v2 대표 원소(루트)를 v1의 집합(루트)의 자식으로 만든다.
        parent[v2] = v1;

        // 트리의 높이가 같을 경우 높이가 증가하게 된다.
        if (height[v1] == height[v2])
            height[v1]++;
    }

    void Union2(int v1, int v2) // Union by Size
    {
        v1 = Find(v1);
        v2 = Find(v2);

        if (v1 == v2) return;

        // 크기가 큰 집합이 v1로 오게한다.
        if (group_size[v1] < group_size[v2])
            swap(v1, v2);

        // v2의 집합을 v1로 바꾸어 준다.
        // -> v2 대표 원소(루트)를 v1의 집합(루트)의 자식으로 만든다.
        parent[v2] = v1;

        // 집합 크기를 더해준다.
        group_size[v1] += group_size[v2];
    }

private:
    vector<int> parent;   // 각 원소가 가리키는 부모 
    vector<int> height;   // 각 집합의 높이
    vector<int> group_size;   // 각 집합의 크기
};

class Kruskal
{
public:
    struct Edge
    {
        Edge() = default;
        Edge(int v1, int v2, int cost) : v1(v1), v2(v2), cost(cost) {}

        int v1, v2; // 연결할 두 정점
        int cost; // 간선의 가중치

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