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

int arr[8];
int n;

int calc() {
	int sum = 0;
	for (int i=0; i<n-1; i++) {
		sum += abs(arr[i] - arr[i+1]);
	}
	
	return sum;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin>>n;
	for (int i=0; i<n; i++) cin>>arr[i];
	
	sort(arr, arr+n);
	int ans = 0;
	do {
		ans = max(ans, calc());
	} while (next_permutation(arr, arr+n));
	
	
	cout<<ans;
	return 0;
}
