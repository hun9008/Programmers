#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int a, b;

long long bfs()
{
    queue <pair<long long, long long> > q;
    q.push(make_pair(a,0));

    while(!q.empty())
    {
        long long num = q.front().first;
        long long cnt = q.front().second;
        q.pop();

        if(num == b)
        {
            return cnt;
        } else if(num > b)
        {
            continue;
        } else {
            q.push(make_pair(num*2, cnt+1));
            q.push(make_pair(num*10 + 1, cnt + 1));
        }
    }
    return -1;
}

int main()
{
    cin >> a >> b;

    long long answer = bfs();

    if(answer > 0)
    {
        cout << answer + 1 << endl;
    } else{
        cout << -1 << endl;
    }

    return 0;
}