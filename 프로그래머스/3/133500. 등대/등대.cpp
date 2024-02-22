#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> graph[100001];
bool visited[100001] = { 0, };
bool light[100001] = { 0, };
int answer = 0;

void init(int n)
{
    for(int i = 0; i <= n; i++)
    {
        visited[i] = 0;
        light[i] = 0;
    }
}

void dfs(int now, int parent)
{
    // cout << "dfs " << now << " " << parent << endl;
    for(int i = 0; i < graph[now].size();i++)
    {
        // cout << "next " << graph[now][i];
        if(graph[now][i] != parent){
            // cout << endl;
            dfs(graph[now][i], now);
            
            if(light[graph[now][i]] == 0 && light[now] == 0)
            {
                // cout << now << graph[now][i] << endl;
                light[now] = true;
                answer++;
            }
        } else{
            // cout << "out" << endl;
        }
    }
    
}

int solution(int n, vector<vector<int>> lighthouse) {
    
    for(int i = 0; i < lighthouse.size(); i++)
    {
        graph[lighthouse[i][0]].push_back(lighthouse[i][1]);
        graph[lighthouse[i][1]].push_back(lighthouse[i][0]);
    }

    dfs(1,1);


    return answer;
}