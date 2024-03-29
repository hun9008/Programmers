#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define INF 987654321987654321

vector< vector<pair<int, int> > > load;
long long costs[10001][21];
int n, m, k;

void dijkstra(){

    for(int i = 0; i < 10001; i++)
    {
        for(int j = 0; j < 21; j++)
        {
            costs[i][j] = INF;
        }
    }

    priority_queue<pair<long long, pair<int, int> > > pq;
    pq.push(make_pair(0,make_pair(1,0)));
    costs[1][0] = 0;

    while(!pq.empty())
    {
        int Pos = pq.top().second.first;
        int cnt = pq.top().second.second;
        long long cost = -1 * pq.top().first;
        pq.pop();

        if(costs[Pos][cnt] < cost){
            continue;
        }

        for(int i = 0; i < load[Pos].size(); i++)
        {
            int nPos = load[Pos][i].first;
            long long nCost = cost + load[Pos][i].second;

            if(costs[nPos][cnt] > nCost){
                costs[nPos][cnt] = nCost;
                pq.push(make_pair(-1 * nCost, make_pair(nPos, cnt)));
            }

            if(costs[nPos][cnt + 1] > cost && cnt + 1 <= k){
                costs[nPos][cnt + 1] = cost;
                pq.push(make_pair(-1 * cost, make_pair(nPos, cnt + 1)));
            }
        }
    }

}


int main(){

    cin >> n >> m >> k;

    load.resize(n+1);

    for(int i = 0; i < m; i++)
    {
        int s, e, cost;
        cin >> s >> e >> cost;
        load[s].push_back(make_pair(e, cost));
        load[e].push_back(make_pair(s, cost));
    }

    long long minCost = INF;

    dijkstra();

    for(int i = 0; i <= k; i++)
    {
        minCost = min(minCost, costs[n][i]);
    }

    cout << minCost << endl;

    return 0;
}