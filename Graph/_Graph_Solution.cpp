// _Graph_Solution.cpp

#include"stdafx.h"

//==================
// [ Macro ]
//==================
#ifdef GRAPH_SOLUTION

#define 미로탐색 // Link: https://www.acmicpc.net/problem/2178
// #define 단지번호붙이기 // Link: https://www.acmicpc.net/problem/2667

#endif

//====================
// [ 미로 탐색 ]
//====================

#ifdef 미로탐색

#include"stdafx.h"
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int DFS(vector<vector<bool>>& map, vector<vector<bool>>& visited, int row, int col)
{
	if (row < 0 || row >= map.size()) return;
}

int main()
{
	int N, M;
	cin >> N, M;

	vector<vector<bool>> map(N);
	vector<vector<bool>> visited(N);

	for (auto& vec : map)
		vec.resize(M, false);

	for(auto& vec:visited)
		vec.resize(M, false);

	for (int row = 0; row < map.size(); row++)
	{
		string str("");
		getline(cin, str);
		cin.ignore();

		for (int col = 0; col < map[0].size(); col++)
			if (str[col] == '0')
				map[row][col] = false;
			else
				map[row][col] = true;
	}
	return 0;
}

#endif

//====================
// [ 단지번호 붙이기 ]
//====================

#ifdef 단지번호붙이기

#endif