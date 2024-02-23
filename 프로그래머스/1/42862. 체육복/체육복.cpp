#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    int cl[31];
    for(int i = 1; i <= n; i++)
    {
        cl[i] = 1;
    }
    for(int i = 0; i < lost.size(); i++)
    {
        cl[lost[i]]--;
    }
    for(int i = 0; i < reserve.size(); i++)
    {
        cl[reserve[i]]++;
    }
    
    for(int i = 1; i <= n; i++)
    {
        if(cl[i] == 0){
            if(i == 1){
                if(cl[2] == 2){
                    cl[2]--;
                    cl[1]++;
                    continue;
                }
            }
            else if(i == n){
                if(cl[n - 1] == 2){
                    cl[n-1]--;
                    cl[n]++;
                    continue;
                }
            }
            else {
                if(cl[i - 1] == 2){
                    cl[i - 1]--;
                    cl[i]++;
                    continue;
                }
                if(cl[i+1] == 2){
                    cl[i+1]--;
                    cl[i]++;
                    continue;
                }
            }
        }
    }
    
    for(int i = 1; i <= n; i++)
    {
        if(cl[i] > 0){
            answer++;
        }
    }
    
    return answer;
}