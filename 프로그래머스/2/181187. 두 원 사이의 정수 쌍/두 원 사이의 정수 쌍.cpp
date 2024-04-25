#define ll long long
#include <cmath>

using namespace std;

ll solution(int r1, int r2) {
    ll answer = 0;
    for (int i=1; i<=r2; i++) {
        answer += (i < r1) ? floor(sqrt((ll)r2*r2-(ll)i*i)) - ceil(sqrt((ll)r1*r1-(ll)i*i)) + 1 : floor(sqrt((ll)r2*r2-(ll)i*i)) + 1;
    }
    answer*=4;
    return answer;
}