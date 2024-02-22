#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

vector<int> graph[201];
bool visited[201];

void init()
{
    for(int i = 0; i < 201; i++)
    {
        visited[i] = false;
    }
}

void bfs(int start)
{
    queue<int> q;
    q.push(start);

    while(!q.empty())
    {
        int now = q.front();
        visited[now] = true;
        q.pop();

        for(int i = 0; i < graph[now].size(); i++)
        {
            int next = graph[now][i];
            if(visited[next] == false)
            {
                q.push(next);
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    init();
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i != j)
            {
                if(computers[i][j] == 1)
                {
                    graph[i+1].push_back(j+1);
                }
            }
        }
    }

    // for(int i = 1; i <= n; i++)
    // {
    //     for(int j = 0; j < graph[i].size(); j++)
    //     {
    //         cout << graph[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    for(int i = 1; i <= n; i++)
    {
        if(visited[i] == false)
        {
            bfs(i);
            answer++;
        }
    }

    return answer;
}