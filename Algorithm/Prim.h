#pragma once

// Prim.h

/*
   ※ Prim's Algoritm
      ㄴ 가중치가 있는 무향 그래프에서 최소비용 신장트리를 찾는 알고리즘.
      ㄴ 그래프에서 임의의 노드를 선택하여 최초의 트리를 만들고 트리의 노드와 아직 연결되지 않은
      노드간의 간선 중 가장 가중치가 적은 간선을 찾아 트리에 추가한다.
      ㄴ 최소 힙을 사용하여 구현이 가능하다.
      ㄴ 크루스칼 알고리즘과 같은 용도지만 상황에 따라 두 알고리즘의 효율이 달라질 수 있다.
      ㄴ 간선의 개수가 작은 경우에는 크루스칼, 간선의 개수가 많은 경우 프림이 효율적이다.


   ※ 구현방법
      1. 임의의 정점을 선택하여 비어있는 T에 포함시킨다.(T는 노드가 한개인 트리)
      2. T에 있는 노드와 T에 없는 노드들 사이의 간선 중 가중치가 최소인 간선을 찾는다.
      3. 찾은 간선이 연결하는 두 노드 중, T에 없던 노드를 T에 포함시킨다.
      4. 2번 3번을 모든 노드가 T에 포함 될 때 까지 반복한다.
*/

#include<vector>
#include<queue>

using namespace std;

using PII = pair<int, int>;

class Prim
{
public:
    Prim(int node_count)
        : edges(node_count)
        , visited(node_count, false)
    {
    }

    // 가중치 있는 무향 그래프의 연결
    void AddEdge(int v1, int v2, int weight)
    {
        edges[v1].push_back(make_pair(weight, v2));
        edges[v2].push_back(make_pair(weight, v1));
    }

    // 최소 비용 신장트리의 가중치 값 반환
	int MakeMST()
	{
		int min_weight = 0;

		// greater : 해당 자료형을 오름차순으로 정렬
		// pair의 경우 처음 first값으로 정렬을 시도 만약에 값이 같다면 second로 정렬한다.
		priority_queue<PII, vector<PII>, greater<PII>> queue;

		// 정점 0번에서부터 시작한다.
		// 트리의 시작이므로 가중치(first)값을 0으로 준다.
		queue.push(make_pair(0, 0));

		while (queue.empty() != true)
		{
			// 우선순위 큐에서 데이터(가장 가중치가 작은)를 꺼낸다
			auto cur_data = queue.top();
			queue.pop();

			// 트리에 있는 정점이라면 넘긴다.
			if (visited[cur_data.second] == true) continue;
			// 정점을 트리에 연결하고 연결비용을 합해준다.
			visited[cur_data.second] = true;
			min_weight += cur_data.first;

			// 이번에 트리에 연결한 정점과 연결된 정점중에 트리에 포함되어 있지
			// 않다면 해당 정점간의 간선을 우선순위 큐에 삽입한다.
			for (const auto& edge : edges[cur_data.second])
			{
				if (visited[edge.second] == true) continue;
				queue.push(edge);
			}
		}
		return min_weight;
	}

public:
    // edges[v1][e].first  = weight;
    // edges[v1][e].second = v2;
    // -> 정점 v1와 v2를 잇는 간선 e의 가중치 weight
    vector<vector<PII>> edges;
    // 해당 노드가 트리에 포함되었는가?
    vector<bool> visited;
};