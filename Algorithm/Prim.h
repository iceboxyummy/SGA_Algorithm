#pragma once

// Prim.h

/*
   �� Prim's Algoritm
      �� ����ġ�� �ִ� ���� �׷������� �ּҺ�� ����Ʈ���� ã�� �˰���.
      �� �׷������� ������ ��带 �����Ͽ� ������ Ʈ���� ����� Ʈ���� ���� ���� ������� ����
      ��尣�� ���� �� ���� ����ġ�� ���� ������ ã�� Ʈ���� �߰��Ѵ�.
      �� �ּ� ���� ����Ͽ� ������ �����ϴ�.
      �� ũ�罺Į �˰���� ���� �뵵���� ��Ȳ�� ���� �� �˰����� ȿ���� �޶��� �� �ִ�.
      �� ������ ������ ���� ��쿡�� ũ�罺Į, ������ ������ ���� ��� ������ ȿ�����̴�.


   �� �������
      1. ������ ������ �����Ͽ� ����ִ� T�� ���Խ�Ų��.(T�� ��尡 �Ѱ��� Ʈ��)
      2. T�� �ִ� ���� T�� ���� ���� ������ ���� �� ����ġ�� �ּ��� ������ ã�´�.
      3. ã�� ������ �����ϴ� �� ��� ��, T�� ���� ��带 T�� ���Խ�Ų��.
      4. 2�� 3���� ��� ��尡 T�� ���� �� �� ���� �ݺ��Ѵ�.
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

    // ����ġ �ִ� ���� �׷����� ����
    void AddEdge(int v1, int v2, int weight)
    {
        edges[v1].push_back(make_pair(weight, v2));
        edges[v2].push_back(make_pair(weight, v1));
    }

    // �ּ� ��� ����Ʈ���� ����ġ �� ��ȯ
	int MakeMST()
	{
		int min_weight = 0;

		// greater : �ش� �ڷ����� ������������ ����
		// pair�� ��� ó�� first������ ������ �õ� ���࿡ ���� ���ٸ� second�� �����Ѵ�.
		priority_queue<PII, vector<PII>, greater<PII>> queue;

		// ���� 0���������� �����Ѵ�.
		// Ʈ���� �����̹Ƿ� ����ġ(first)���� 0���� �ش�.
		queue.push(make_pair(0, 0));

		while (queue.empty() != true)
		{
			// �켱���� ť���� ������(���� ����ġ�� ����)�� ������
			auto cur_data = queue.top();
			queue.pop();

			// Ʈ���� �ִ� �����̶�� �ѱ��.
			if (visited[cur_data.second] == true) continue;
			// ������ Ʈ���� �����ϰ� �������� �����ش�.
			visited[cur_data.second] = true;
			min_weight += cur_data.first;

			// �̹��� Ʈ���� ������ ������ ����� �����߿� Ʈ���� ���ԵǾ� ����
			// �ʴٸ� �ش� �������� ������ �켱���� ť�� �����Ѵ�.
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
    // -> ���� v1�� v2�� �մ� ���� e�� ����ġ weight
    vector<vector<PII>> edges;
    // �ش� ��尡 Ʈ���� ���ԵǾ��°�?
    vector<bool> visited;
};