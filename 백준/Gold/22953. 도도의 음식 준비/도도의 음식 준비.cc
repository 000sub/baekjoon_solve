#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <cstring>
#include <cmath>
#include <map>
typedef long long ll;
using namespace std;

int arr[10];
int n,k,c;
ll ans = 1e12;

ll getFoodCnt(ll time) {
	ll cnt = 0;
	for (int i=0; i<n; i++) {
		cnt += time / arr[i];
	}
	
	return cnt;
}

void binSearch(){
	ll low = 0;
	ll high = 1e12;
	ll minT = 1e12;
	
	while (low<=high) {
		ll mid = (low+high) / 2;
		ll foodCnt = getFoodCnt(mid);
		if (foodCnt < k) {
			low = mid + 1;
		}
		else {
			minT = mid;
			high = mid - 1;
		}
	}
	
	ans = min(ans, minT);
}

void BT(int idx) {
	
	binSearch();
	
	if (idx == c) {
		
		return;
	}
	
	for (int i=0; i<n; i++) {
		if (arr[i] == 1) continue;
		arr[i]--;
		BT(idx+1);
		arr[i]++;	
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>n>>k>>c;
	for (int i=0; i<n; i++) cin>>arr[i];
	
	BT(0);
	
	cout<<ans;
	
	return 0;
}
