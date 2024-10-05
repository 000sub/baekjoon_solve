#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <string>
#include <set>
#include <algorithm>

#define PII pair<int,int>
using namespace std;
typedef long long ll;

int N;
int A[4001], B[4001], C[4001], D[4001];
vector<ll> v1;
int main() {
    ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>N;
	for (int i=0; i<N; i++) {
		cin>>A[i]>>B[i]>>C[i]>>D[i];
	}

	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			v1.push_back(A[i] + B[j]);
		}
	}
	sort(v1.begin(), v1.end());
	ll ans = 0;
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) {
			ll sum = -(C[i] + D[j]);
			int hi = upper_bound(v1.begin(), v1.end(), sum) - v1.begin();
			int lo = lower_bound(v1.begin(), v1.end(), sum) - v1.begin();

			if (sum == v1[lo]) ans += (hi - lo);
		}
	}

	cout<<ans;

    return 0;
}