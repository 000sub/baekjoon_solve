#include <string>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

int N;
vector<int> Times;

ll check(ll time) {
    ll res = 0;
    for (int t : Times) {
        res += time / t;
    }
    return res;
}

ll bisearch() {
    ll low = 1, high = 1e18;
    
    while (low<=high) {
        ll mid = (low + high) / 2;
                
        if (check(mid) >= N) {
            if (check(mid-1) >= N) {
                high = mid - 1;
            } else {
                return mid;
            }
        } else {
            low = mid+1;
        }
    }
}

long long solution(int n, vector<int> times) {    
    N = n;
    Times = times;
    return bisearch();
}