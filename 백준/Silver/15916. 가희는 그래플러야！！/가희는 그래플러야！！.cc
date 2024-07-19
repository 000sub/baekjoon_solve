#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

typedef long long ll;
using namespace std;

ll n, k;
ll arr[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>n;
	for (int i=1;i<=n;i++) cin>>arr[i];
	cin>>k;
	
	
	if (arr[1]==k) {
		cout<<'T';
		return 0;
	}
	
	bool isAbove = arr[1] > k;
	
	for (int i=2; i<=n; i++) {
		if ( (isAbove ^ (arr[i] > i*k)) || (arr[i] == i*k) ) {
			cout<<'T';
			return 0;
		}
	}
	
	cout<<'F';
	return 0;
}