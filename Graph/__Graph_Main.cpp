// __Graph_Main.cpp

#include"stdafx.h"

//===============
// [ Macro ]
//===============

#ifdef GRAPH_MAIN

//#define GRAPH_EX
#define BFS_GRAPH
//#define DFS_GRAPH

#endif 

//==================
// [ GRAPG EX ]
//==================

#ifdef GRAPH_EX

#include<iostream>
#include<Windows.h>

using namespace std;

int main()
{
    // 무방향 그래프의 인접 행렬 
    int m;
    cout << "정점의 개수 입력 :";
    cin >> m;

    int** graph = new int* [m];

    for (int i = 0; i < m; i++)
        graph[i] = new int[m];

    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
            graph[i][j] = 0;

    int u, v;
    for (int i = 0; i < m; i++)
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < m; j++)
                cout << graph[i][j] << "\t";
            cout << endl;
        }

        cout << "연결할 정점(u) : ";
        cin >> u;
        cout << "연결할 정점(v) : ";
        cin >> v;

        cout << endl;

        graph[u][v] = graph[v][u] = 1;

        Sleep(1000);
    }
    return 0;
}

#endif

//==================
// [ BFS GRAPH ]
//==================

#ifdef BFS_GRAPH

#include<iostream>
#include"01_BFS_Graph.h"

using namespace std;

int main()
{
   Graph graph(5);

   graph.Display();
   cout << endl;

   graph.MakeLink(0, 1);
   graph.MakeLink(0, 4);

   graph.MakeLink(1, 2);
   graph.MakeLink(1, 4);

   graph.MakeLink(2, 3);

   graph.Display();
   cout << endl;

   // 0을 시작점으로 탐색
   graph.BFS(0);

   return 0;
}

#endif

//==================
// [ DFS GRAPH ]
//==================

#ifdef DFS_GRAPH

#include<iostream>
#include"02_DFS_Graph.h"

using namespace std;

int main()
{
   Graph graph(5);

   graph.MakeLink(0, 1);
   graph.MakeLink(0, 2);

   graph.MakeLink(1, 3);

   graph.MakeLink(2, 3);

   graph.MakeLink(3, 4);

   graph.MakeLink(4, 0);

   graph.Display();
   cout << endl;

   graph.DFS1(0);
   cout << endl;

   graph.ClearVisitedInfo();
   graph.DFS2(0);
   cout << endl;
}

#endif