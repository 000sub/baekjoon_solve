#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>

#define MAX 100001
using namespace std;
typedef long long ll;

int N;
vector<ll> v;

void check(ll num, ll k){
	for (; k>=0; k--){
		v.emplace_back(num*10+k);
		check(num*10+k, k-1);
	}
}

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>N;
	
	
	for (ll i=0; i<=9; i++){
		v.emplace_back(i);
		check(i, i-1);
	}
	
	sort(v.begin(), v.end());
	
	if (v.size() >= N) cout<<v[N-1]<<'\n';
	else cout<<-1<<'\n';

	return 0;
}