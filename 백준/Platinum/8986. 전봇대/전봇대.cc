#include <iostream>
#include <algorithm>
#include <cmath>


typedef long long ll;
using namespace std;

int n, x[100000];

ll f(int dist){
	
	ll rst = 0;
	
	for (ll i=1; i<n; i++){
		rst += abs(dist*i - x[i]);
	}
	
	return rst;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	ll ans = 1e18;
	ll lo, hi, x1, x2;
	
	
	cin>>n;
	for (int i=0; i<n; i++) cin>>x[i];
	
	lo = 0;
	hi = x[n-1];
	
	while (hi - lo >= 3) {
		x1 = (2*lo+hi) / 3;
		x2 = (lo+2*hi) / 3;
		(f(x1) > f(x2)) ? lo = x1 : hi = x2; 
	}
	
	for (int i = lo; i<=hi; i++){
		ans = min(ans, f(i));
	}
	
	cout<<ans<<'\n';
	
	return 0;
}