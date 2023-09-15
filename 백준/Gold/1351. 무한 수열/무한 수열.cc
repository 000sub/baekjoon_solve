#include <iostream>
#include <algorithm>
#include <map>

using namespace std;
typedef long long ll;

ll N, P, Q;
map<ll, ll> m;

ll Find(ll x){
	if (m.count(x)) return m[x];		
	return m[x] = Find(x/P) + Find(x/Q);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>N>>P>>Q;
	m[0] = 1;
	cout<<Find(N)<<'\n';

	return 0;
}