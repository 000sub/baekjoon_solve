#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <cstring>
#include <cmath>
typedef long long ll;
using namespace std;


ll arr[100001];
int N;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>N;
	
	for (int i=0; i<N; i++) cin>>arr[i];
	
	sort(arr, arr+N);
		
	int s = 0, e = N - 1;
	int minS = s, minE = e;
	ll ans = arr[s] + arr[e];
	while (s<e) {
		ll sum = arr[s] + arr[e];
		if (abs(ans)>abs(sum)) {
			ans = sum;
			minS = s;
			minE = e;
		}
		if (ans == 0) break;
		else if (sum > 0) e--;
		else s++;

	}	
	
	cout<<arr[minS]<<' '<<arr[minE];
}