#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> sticker)
{
    int answer = 0;

    int dp[100001];
    int dp2[100001];

    for(int i = 0; i < 100001; i++)
    {
        dp[i] = 0;
        dp2[i] = 0;
    }

    dp[0] = sticker[0];
    dp[1] = dp[0];
    for(int i = 2; i < sticker.size() - 1; i++)
    {
        dp[i] = max(dp[i-2] + sticker[i], dp[i-1]);
    }
    dp[sticker.size() - 1] = dp[sticker.size() - 2];

    dp2[0] = 0;
    dp2[1] = sticker[1];
    // dp2[2] = dp2[1];
    for(int i = 1; i < sticker.size(); i++)
    {
        dp2[i] = max(dp2[i-2] + sticker[i], dp2[i-1]);
    }

    answer = max(dp[sticker.size()-1], dp2[sticker.size()-1]);
    if(sticker.size() == 1) {
        return sticker[0];
    }
    return answer;
}