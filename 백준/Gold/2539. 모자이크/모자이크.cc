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

int N, M, K, L;
vector<int> v;
int minH = 0;

int check(int k) {
	int cnt = 0;
	int prev = -1;

	for (int pos : v) {
		if (prev == -1) {
			prev = pos;
			cnt++;
		}
		else if (prev + k <= pos) {
			prev = pos;
			cnt++;
		}
	}

	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>N>>M>>K>>L;

	for (int i=0,a,b; i<L; i++) {
		cin>>a>>b;
		minH = max(minH, a);
		v.push_back(b);
	}

	sort(v.begin(), v.end());

	int lo = minH, hi = 1000000;
	while (lo<=hi) {
		int mid = (lo+hi) / 2;

		if (check(mid) <= K) hi = mid - 1;
		else lo = mid + 1;
	}

	cout<<lo;
    return 0;
}