#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;

    int timeSize = times.size();

    sort(times.begin(), times.end());
    long long maxTime = times.back();

    long long left = 1;
    long long right = maxTime * n;

    while(left <= right)
    {
        long long mid = (left + right) / 2;
        // cout << mid << endl;
        long long person = 0;
        for(int i = 0; i < timeSize; i++)
        {
            person += (mid / (long long)times[i]);
            if(person >= n) {
                break;
            }
        }

        if(person >= n)
        {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }

    }



    return answer;
}