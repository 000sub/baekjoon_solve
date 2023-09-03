#include <iostream>
#include <algorithm>
#include <queue>
#define MAX 1000001
#define MOD 1000000007
using namespace std;
typedef long long ll;

int N, M,K;
ll arr[MAX], seg[2*MAX];

ll get_mul(int l, int r){
	ll rst = 1;
	
	for (l+=N, r+=N; l!=r; l>>=1, r>>=1){
		if (l&1) rst= rst * seg[l++] % MOD;
		if (r&1) rst= rst * seg[--r] % MOD;
	}
	
	return rst;
}

void update(int i, ll v){
	i+=N;
	seg[i] = v;
	while (i>1){
		i>>=1;
		seg[i] = seg[i<<1] * seg[(i<<1)+1] % MOD;
	}
}

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>N>>M>>K;
	
	for (int i=0; i<N; i++) cin>>arr[i];
	for (int i=0; i<N; i++) seg[i+N] = arr[i];
	for (int i=N-1; i>0; --i) seg[i] = seg[i<<1] * seg[i<<1|1] % MOD;
	
	ll a,b,c;
	for (int i=0; i<M+K; i++){
		cin>>a>>b>>c;
		
		if (a==1) update(b-1, c);
		else cout<<get_mul(b-1, c) % MOD<<'\n';
	}

	return 0;
}