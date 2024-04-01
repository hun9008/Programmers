#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    string str;

    cin >> n >> str;

    long long lonely = 0;

    for(int i = 0; i < n; i++)
    {
        long long lCnt = 0;
        long long rCnt = 0;
        for(int k = i - 1; k >= 0 && str[k] != str[i]; k--)
        {
            lCnt++;
        }
        for(int k = i + 1; k < n && str[k] != str[i]; k++)
        {
            rCnt++;
        }
        lonely += lCnt * rCnt;
        long long zero = 0;
        lonely += max(zero, lCnt - 1);
        lonely += max(zero, rCnt - 1);
    }

    cout << lonely << endl;
    return 0;
}