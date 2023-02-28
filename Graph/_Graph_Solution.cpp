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
#include<queue>

using namespace std;

struct pos
{
    pos(int row, int col)
        : row(row), col(col)
    {}

    int row;
    int col;
};

pos dir[] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

int BFS(vector<vector<bool>>& map, vector<vector<bool>>& visited)
{
    int dest_row = map.size() - 1;
    int dest_col = map[0].size() - 1;
    if (0 == dest_row && dest_col == 0) return 1;

    queue<pair<pos, int>> queue;
    queue.push(make_pair<pos, int>(pos(0, 0), 1));
    visited[0][0] = true;

    while (queue.empty() != true)
    {
        pair<pos, int> data = queue.front();
        queue.pop();

        auto data_pos = data.first;

        for (auto& cur_dir : dir)
        {
            int cur_row = data_pos.row + cur_dir.row;
            int cur_col = data_pos.col + cur_dir.col;

            if (cur_row < 0 || cur_row > dest_row) continue;
            if (cur_col < 0 || cur_col > dest_col) continue;
            if (map[cur_row][cur_col] == false) continue;
            if (visited[cur_row][cur_col] == true) continue;

            if (cur_row == dest_row && cur_col == dest_col) return data.second + 1;

            visited[cur_row][cur_col] = true;
            queue.push(make_pair(pos(cur_row, cur_col), data.second + 1));
        }
    }
}

int main()
{
    int N, M;
    cin >> N >> M;

    vector<vector<bool>> map(N);
    vector<vector<bool>> visited(N);

    for (auto& vec : map)
        vec.resize(M, false);

    for (auto& vec : visited)
        vec.resize(M, false);

    for (int row = 0; row < map.size(); row++)
    {
        string str("");
        cin >> str;
        cin.ignore();

        for (int col = 0; col < map[0].size(); col++)
            if (str[col] == '0')
                map[row][col] = false;
            else
                map[row][col] = true;
    }
    cout << BFS(map, visited);

    return 0;
}
#endif

//====================
// [ 단지번호 붙이기 ]
//====================

#ifdef 단지번호붙이기

#include"stdafx.h"
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>

using namespace std;

int DFS(vector<vector<bool>>& map, vector<vector<bool>>& visited, int row, int col)
{
    if (row < 0 || row >= map.size()) return 0;
    if (col < 0 || col >= map[0].size()) return 0;
    if (map[row][col] == false) return 0;
    if (visited[row][col] == true) return 0;

    visited[row][col] = true;
    int result = 1;

    result += DFS(map, visited, row + 1, col);
    result += DFS(map, visited, row - 1, col);
    result += DFS(map, visited, row, col + 1);
    result += DFS(map, visited, row, col - 1);

    return result;
}

int main()
{
    int N;
    int result = 0;
    cin >> N;

    vector<vector<bool>> map(N);
    vector<vector<bool>> visited(N);
    vector<int> result_2;

    for (auto& vec : map)
        vec.resize(N, false);

    for (auto& vec : visited)
        vec.resize(N, false);

    for (int row = 0; row < map.size(); row++)
    {
        string str("");
        cin >> str;
        cin.ignore();

        for (int col = 0; col < map[0].size(); col++)
            if (str[col] == '0')
                map[row][col] = false;
            else
                map[row][col] = true;
    }

    for (int row = 0; row < map.size(); row++)
        for (int col = 0; col < map[0].size(); col++)
        {
            if (map[row][col] == true && visited[row][col] == false)
            {
                result_2.push_back(DFS(map, visited, row, col));
                result++;
            }
        }

    cout << result << endl;
    sort(result_2.begin(), result_2.end());

    for (auto ele : result_2)
        cout << ele << endl;

    return 0;
}
#endif