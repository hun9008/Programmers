#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <limits.h>
using namespace std;

int w, h;
int room[21][21];
int visited[21][21];
int trash[21][21];
int startTrash[21];
int dir[2][4] = {{1,-1,0,0},{0,0,1,-1}};
int startX, startY;


void printRoom(int n, int m)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cout << visited[i][j] << " ";
        }
        cout << endl;
    }
}

void bfs(int sx, int sy)
{
    queue<pair<int, int> > q;
    q.push(make_pair(sx, sy));
    fill(&visited[0][0], &visited[0][0] + 21 * 21, INT_MAX);
    visited[sx][sy] = 0;

    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        int cnt = visited[x][y] + 1;

        q.pop();


        for(int i = 0; i < 4; i++)
        {
            int nx = x + dir[0][i];
            int ny = y + dir[1][i];

            if (ny < 0 || nx < 0 || ny >= w || nx >= h || visited[nx][ny] <= cnt || room[nx][ny] == 2) {
				continue;
			}

            q.push(make_pair(nx, ny));
            visited[nx][ny] = cnt;

        }
    }

}

int main()
{
    cin >> w >> h;

    while(w != 0 || h != 0)
    {
        string s;
        vector<pair<int, int> > trashPos;
        for(int i = 0; i < 21; i++)
        {
            memset(room[i], 0, sizeof(int)*21);
            memset(trash[i], 0, sizeof(int)*21);
        }
        for(int i = 0; i < h; i++)
        {
            cin >> s;
            for(int j = 0; j < w; j++)
            {
                if(s[j] == 'o') startX = i, startY = j;
                if(s[j] == '*') {
                    room[i][j] = 1;
                    trashPos.push_back(make_pair(i, j));
                }
                if(s[j] == 'x') room[i][j] = 2;
            }
        }

        vector<int> order;
        bfs(startX, startY);
        int result = INT_MAX;
        for(int i = 0; i < trashPos.size(); i++)
        {
            startTrash[i] = visited[trashPos[i].first][trashPos[i].second];
        }
        for (int i = 0; i < trashPos.size(); i++) {
            bfs(trashPos[i].first, trashPos[i].second);

            for (int j = 0; j < trashPos.size(); j++) {
                if (i == j) {
                    continue;
                }
                trash[i][j] = visited[trashPos[j].first][trashPos[j].second];
		    }
		    order.push_back(i);
	    }

        do {
            int lengthSum = startTrash[order[0]];
            
            for (int i = 0; i < order.size()-1; i++) {
                if (trash[order[i]][order[i+1]] == INT_MAX) {
                    lengthSum = -1;
                    break;
                }
                lengthSum += trash[order[i]][order[i+1]];
            }
            if (lengthSum == -1) {
                continue;
            }
            result = min(result, lengthSum);

        } while (next_permutation(order.begin(), order.end()));

        if(result == INT_MAX){
            cout << -1 << endl;
        } else{
            cout << result << endl;
        }
        // printRoom(w,h);
        cin >> w >> h;
    }

    return 0;
}