#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> tops) {
    int answer = 0;

    int aS, S, paS, pS;
    paS = 0;
    pS = 1;
    for(int i = 0; i < tops.size(); i++)
    {
        aS = paS + pS;
        if(tops[i] == 1)
        {
            S = pS * 3 + paS * 2;
        } else{
            S = 2* pS + paS;
        }
        paS = aS;
        pS = S;
        paS %= 10007;
        pS %= 10007;
    }

    return (S+aS) % 10007;
}