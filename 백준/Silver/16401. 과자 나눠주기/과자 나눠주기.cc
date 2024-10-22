#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <set>
#include <string>
#include <map>

#define PII pair<int,int>
using namespace std;
typedef long long ll;

int arr[1000001];
int N, M;

ll check(ll k) {
	ll cnt = 0;
	for (int i=0; i<N; i++) cnt += (ll)arr[i] / k;
	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>M>>N;
	for (int i=0; i<N; i++) cin>>arr[i];

	ll lo = 1, hi = 1e9;
	while (lo <= hi) {
		ll mid = (lo+hi)/2;
		if (check(mid) >= M) {
			lo = mid + 1;
		}
		else hi = mid - 1;
	}

	cout << hi;
    
    return 0;
}