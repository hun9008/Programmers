#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#include <functional>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    sort(people.begin(), people.end());
    
    int idx = 0;
    while(idx < people.size())
    {
        int back = people.back();
        people.pop_back();
        if(people[idx] + back <= limit){
            idx++;
            answer++;
        } else{
            answer++;
        }
    }
    
    return answer;
}