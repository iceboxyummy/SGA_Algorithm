#pragma once

// 02_DFS_Graph.h

/*
   �� DFS(depth - first search)
      �� ��Ʈ���(Ȥ�� ������ �ٸ� ���)���� �����ؼ� ���� �б�� �Ѿ�� ���� �ش� �б⸦ �Ϻ��ϰ� Ž���ϴ� ���.
      �� �̷θ� Ž�� �Ҷ� �� �������� ���� �� �� ���� ������ ��� ���ٰ� ���̻� �� �� ���� �Ǹ� �ٽ� ���� ����� �������
      ���ƿͼ� �̰����κ��� �ٸ� �������� �ٽ� Ž���� �����ϴ� ���.
      �� �ʺ� �켱 Ž���� ���� ������ ���� �����ϴ�.
      �� �ܼ� �˻��ӵ��� BFS�� ���� ������.

   �� Ư¡
      �� �ڱ� �ڽ��� ȣ���ϴ� ��ȯ �˰������� ���¸� �ڴ�.
      �� ���� ��ȸ�� ������ �ٸ� ������ Ʈ�� ��ȸ�� ��� DFS�� �� ������.

   �� ����
      �� ���� �� ��λ��� ���鸸 ����ϸ� �Ǳ� ������ ��������� ���䰡 ���� ����.
      �� ��ǥ ��尡 ���� �ܰ迡 ������� ���� �ظ� ���Ҽ� �ִ�.

   �� ����
      �� �ذ� ���� ��ο� ���� ���� ���ɼ��� �����Ѵ�. ���� �����δ�
      �̸� ������ ������ ���̱����� Ž���ϰ�, ��ǥ��带 �߰����� ���ϸ�
      ���� ��θ� ���� Ž���ϴ� ����� ����Ѵ�.

      �� ����� �ذ� �ִ� ��ΰ� �ȴٴ� ������ ����.
      �̴� ��ǥ�� �̸��� ��ΰ� �ټ��� ������ ���� ���� �켱Ž����
      ��ǥ�� �ٴٸ��� Ž���� ���������� ������, �̶� ����� �ش� ������ �ƴҼ��� �ִ�.
*/

#include<Windows.h>
#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>

using namespace std;

// ���� �׷���
class Graph
{
public:
    Graph(int nodeCount)
        :nodeCount(nodeCount)
    {
        // assign(����, ��) : ���� ��ŭ�� ���Ҹ� �ش� ������ �ʱ�ȭ�Ѵ�.
        graph.assign(nodeCount, vector<int>());
        visited.assign(nodeCount, false);
    }

    void MakeLink(int node, int next)
    {
        graph[node][next] = 1;
    }

    void Display()
    {}

    // ����Լ��� Ȱ���� DFS
    void DFS1(int start)
    {
        visited[start] == true;


    }

    // ������ Ȱ���� DFS
    void DFS2(int start)
    {
        stack<int>s;
        s.push(start);

        while (s.empty() != true)
        {
            int temp = s.top();
            s.pop();

            if(visited[temp])
            visited[temp] = true;

            cout << temp << " ";

            for (int i = 0; i < nodeCount; i++)
            {
                if (graph[temp][i] == 1 && visited[i] == false)
                    s.push(i);
            }
        }
    }

    // 
    void DFS3()
    {
        // �׷����� �и��Ǿ� �ִ� ���  �� �κ� �׷����� ������Ʈ Ȥ�� ��Ҷ�� �θ���.
        // dfs�� bfs�� ����Ͽ� �׷����� ��� ������Ʈ�� �����Ǿ����� Ȯ�ΰ����ϴ�.
        ClearVisitedInfo();

        int count = 0;
        for (int i = 0; i < nodeCount; i++)
            if (visited[i] == false)
            {
                count++;
                DFS1(i);
            }
    }

    // visited �迭 false�� ����
    void ClearVisitedInfo()
    {
        fill(visited.begin(), visited.end(), 0);
    }

private:
    vector<vector<int>> graph;
    vector<bool> visited;
    int nodeCount;
};