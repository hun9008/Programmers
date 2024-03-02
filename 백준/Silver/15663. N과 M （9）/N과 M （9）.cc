#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int answer[9];
vector <int> ins;
int n, m;
bool visited[9] = { 0, };

void init()
{
    for(int i = 0; i < 8; i++)
    {
        visited[i] = 0;
    }
}

void promising(int size)
{
    if(size == m){
        for(int i = 0; i < m; i++)
        {
            cout << answer[i] << " ";
        }
        cout << "\n";
        return;
    }

    int prev_element = 0;

    for(int i = 0; i < n; i++)
    {
            if(prev_element != ins[i] && visited[i] == 0){
                answer[size] = ins[i];
                prev_element = ins[i];
                visited[i] = 1;
                promising(size+1);
                visited[i] = 0;
            }
    }
}

int main(){
    cin >> n >> m;

    for(int i = 1; i <= n; i++)
    {
        int in;
        cin >> in;
        ins.push_back(in);
    }
    sort(ins.begin(), ins.end());
    init();
    promising(0);
    
    return 0;
}