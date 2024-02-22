#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> cores) {
    int answer = 0;
    if(n <= cores.size())
    {
        return n;
    }
    
    int minValue = 1999999999;
    for(int i = 0; i < cores.size(); i++)
    {
        if(minValue > cores[i])
        {
            minValue = cores[i];
        }
    }
    
    int start = n / cores.size() * minValue;
    int end = n * minValue;
    
    while(start <= end)
    {
        int mid = (start + end) / 2;
        int cnt = cores.size();
        int current_cnt = 0;
        
        for(int i = 0; i < cores.size(); i++)
        {
            cnt += mid / cores[i];
            if(mid % cores[i] == 0)
            {
                cnt--;
                current_cnt++;
            }
        }
        if(cnt >= n)
        {
            end = mid - 1;
        } else if((cnt + current_cnt) < n)
        {
            start = mid + 1;
        } else{
            for(int i = 0; i < cores.size(); i++)
            {
                if(mid % cores[i] == 0)
                {
                    cnt++;
                }
                if(cnt == n){
                    return i + 1;
                }
            }
        }
    }
    
    
    
    
    return answer;
}