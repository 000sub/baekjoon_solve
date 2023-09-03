#include <iostream>
#include <algorithm>
#define MAX 1000001

using namespace std;
typedef long long ll;

int N, M;
ll seg[2*MAX];

ll get_sum(int l, int r){
	ll rst = 0;
	
	for (l+=N, r+=N; l!=r; l>>=1, r>>=1){
		if (l&1) rst+=seg[l++];
		if (r&1) rst+=seg[--r];
	}
	
	return rst;
}

void update(int i, ll v){
	i+=N;
	seg[i] += v;
	while (i>1){
		i>>=1;
		seg[i] = seg[i<<1] + seg[(i<<1)+1];
	}
}

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>N>>M;
	
	
	ll a,b,c;
	for (int i=0; i<M; i++){
		cin>>a>>b>>c;
		
		if (a==1) update(b-1, c);
		else cout<<get_sum(b-1, c)<<'\n';
	}

	return 0;
}