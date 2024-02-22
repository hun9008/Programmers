#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
int dp[101][201];

int INF = 987654321;
void init()
{
    for(int i = 0; i < 101; i++)
    {
        for(int j = 0; j < 201; j++)
        {
            dp[i][j] = INF;
        }
    }
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, int m, vector<vector<int>> edge_list, int k, vector<int> gps_log) {
    int answer = 0;
    
    vector<int> adj[201];
    for(int i = 0; i < edge_list.size(); i++)
    {
        adj[edge_list[i][0]].push_back(edge_list[i][1]);
        adj[edge_list[i][1]].push_back(edge_list[i][0]);
    }
    init();
    dp[1][gps_log[0]] = 0;
    for(int t = 2; t <= k; ++t)
    {
        for(int pos = 1; pos <= n; ++pos)
        {
            int minError = dp[t-1][pos];
            for(int i = 0; i < adj[pos].size(); ++i)
            {
                minError = min(dp[t-1][adj[pos][i]], minError);
            }
            if(gps_log[t-1] != pos)
            {
                minError++;
            }
            dp[t][pos] = minError;
        }
    }
    
    answer = dp[k][gps_log[k-1]];
    if(answer >= INF) answer = -1;
    
    return answer;
}