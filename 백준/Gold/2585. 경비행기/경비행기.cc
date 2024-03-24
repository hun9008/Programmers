#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string.h>
using namespace std;

int n, k;
vector<pair<int, int> > points;

int dist(int x1, int y1, int x2, int y2)
{
	double x = x1 - x2; 
	double y = y1 - y2;
	double dist;

	dist = pow(x, 2) + pow(y, 2);       
	dist = sqrt(dist);    
    // cout << dist << endl;              

	return ceil(dist/10);
}

bool bfs(int mid)
{
    queue<pair<pair<int, int>, int> > q;
    bool visited[1001];
    q.push(make_pair(make_pair(0,0),0));
    memset(visited, 0, sizeof(visited));
    visited[0] = 1;
    
    while(!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int kth = q.front().second;
        q.pop();

        if(mid >= dist(x, y, 10000, 10000)){
            return true;
        } 
        if(kth == k + 1){
            continue; //pop만
        }
        for(int i = 1; i < points.size(); i++)
        {
            int nx = points[i].first;
            int ny = points[i].second;
            if(mid >= dist(x, y, nx, ny) && !visited[i])
            {
                visited[i] = 1;
                q.push(make_pair(make_pair(nx, ny),kth + 1));
            }
        }
    }
    return false;
}

int main()
{
    cin >> n >> k;
    points.push_back(make_pair(0,0));
    for(int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        points.push_back(make_pair(x, y));
    }

    int start = 0;
    int end = 987654321;
    int ans = 987654321;

    while(start <= end)
    {
        int mid = (end + start) / 2;

        if(bfs(mid)){
            end = mid - 1;
            ans = min(ans, mid);
            // cout << ans << endl;
        } else{
            start = mid + 1;
        }
    }

    cout << ans << endl;

    return 0;
}