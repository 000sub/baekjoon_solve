#include <iostream>
#include <algorithm>
#include <vector>

typedef long long ll;
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b){
	return a.first > b.first;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int L, N, rF, rB;
	int pos, val;
	vector<pair<int, int> > v;
	ll ans = 0;
	
	cin>>L>>N>>rF>>rB;
	
	for (int i=0; i<N; i++){
		
		cin>>pos>>val;
		v.emplace_back(val, pos);
	}
	
	sort(v.begin(), v.end(), cmp);
	
	
	int curpos = 0;
	pos = 0; val = 0;
	
	for (int i=0; i<N; i++){
		val = v[i].first;
		pos = v[i].second;
				
		if (curpos >= pos) continue;
		
		ans += 1LL * (pos - curpos) * (rF-rB) * val;
		curpos = pos;
	}
	
	cout<<ans;

	
	return 0;
}