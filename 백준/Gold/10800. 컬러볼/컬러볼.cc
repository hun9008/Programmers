#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <map>
using namespace std;

typedef struct info {
    int idx;
    int color;
    int size;
} info;

vector<info> input;
vector<long long> ans(200001,0);
int n;

bool comp(info a, info b)
{
    if(a.size == b.size) return a.color < b.color;
    return a.size < b.size;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int color;
        int size;
        cin >> color >> size;
        info inf;
        inf.idx = i;
        inf.color = color;
        inf.size = size;
        input.push_back(inf);
        // box[color - 1].push_back(size);
    }

    sort(input.begin(), input.end(), comp);

    long long sum = 0;
    long long sum_color[200001];
    long long sum_size[200001];
    memset(sum_color, 0, 200001);
    memset(sum_size, 0, 200001);
    for(int i = 0; i < n; i++)
    {
        int index = input[i].idx;
        int color = input[i].color;
        int size = input[i].size;
        sum += size;
        sum_color[color] += size;
        sum_size[size] += size;

        if(i > 0 && size == input[i-1].size && color == input[i-1].color){
            ans[index] = ans[input[i-1].idx];
        } else{
            ans[index] = sum - sum_color[color] - sum_size[size] + size;
        }
    }

    for(int i = 0; i < n; i++)
    {
        cout << ans[i] << "\n";
    }

    return 0;
}