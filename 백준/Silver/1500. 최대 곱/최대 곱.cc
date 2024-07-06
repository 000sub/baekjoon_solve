#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <cmath>

typedef long long ll;

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	ll S, K;
	
	cin>>S>>K;
	
	ll ans = 1;
	for (int i=0; i<S%K; i++) ans*= S/K+1;
	for (int i=S%K; i<K; i++) ans*= S/K;
	cout<<ans<<'\n';
}