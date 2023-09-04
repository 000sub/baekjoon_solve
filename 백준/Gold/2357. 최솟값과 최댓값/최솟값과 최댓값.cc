#include <iostream>
#include <algorithm>
#include <cstring>

#define MAX 100001
using namespace std;

int N, M;
int arr[MAX], min_seg[2*MAX], max_seg[2*MAX];

int get_min(int l, int r){
	int res = 1000000000;
	
	for (l+=N, r+=N; l!=r; l>>=1, r>>=1){
		if (l&1) res = min(res, min_seg[l++]);
		if (r&1) res = min(res, min_seg[--r]);
	}
	
	return res;
}

int get_max(int l, int r){
	int res =0;
	
	for (l+=N, r+=N; l!=r; l>>=1, r>>=1){
		if (l&1) res = max(res, max_seg[l++]);
		if (r&1) res = max(res, max_seg[--r]);
	}
	
	return res;
}

void update(int i, int v){
	min_seg[i+=N] = v;
	max_seg[i] = v;
	
	while (i>1){
		i>>=1;
		min_seg[i] = min(min_seg[i>>1], min_seg[i>>1|1]);
		max_seg[i] = max(max_seg[i>>1], max_seg[i>>1|1]);
	}
		
}
int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>N>>M;
	
	for (int i=0; i<N; i++) cin>>arr[i];
	for (int i=0; i<N; i++) {
		min_seg[i+N] = arr[i];
		max_seg[i+N] = arr[i];
	}
	for (int i=N-1; i>0; i--){
		min_seg[i] = min(min_seg[i<<1], min_seg[i<<1|1]);
		max_seg[i] = max(max_seg[i<<1], max_seg[i<<1|1]);
	}
	
	int a,b;
	
	for (int i=0; i<M; i++){
		cin>>a>>b;
		cout<<get_min(a-1,b)<<" "<<get_max(a-1, b)<<'\n';
	}	

	return 0;
}