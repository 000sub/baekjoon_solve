#include <iostream>
#include <queue>

#define PII pair<int,int>

using namespace std;

int solution(int n)
{    
    int ans = 0;
    while (n > 0) {
        if (n%2==0) n/=2;
        else {
            ans++;
            n = (n-1)/2;
        }
    }
    return ans;
}