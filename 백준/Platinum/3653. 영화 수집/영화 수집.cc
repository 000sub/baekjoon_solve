#include <iostream>
#include <algorithm>
#include <cstring>

#define MAX 100001
using namespace std;

int N, M;
int seg[4*MAX+100];
int pos[100001];

int get_cnt(int l, int r){
	if (l>r) return 0;
	int res =0;
	
	for (; l!=r; l>>=1, r>>=1){
		if (l&1) res += seg[l++];
		if (r&1) res += seg[--r];
	}
	
	
	return res;
}
void update(int x, int i, int num){
	seg[x]--;
	
	while (x>1){
		x>>=1;
		seg[x] = seg[x<<1] + seg[x<<1|1]; 
	}
	
	seg[i+=3*MAX]++;
	int new_pos = i;
	pos[num] = new_pos;
	while (i>1){
		i>>=1;
		seg[i] = seg[i<<1] + seg[i<<1|1];
	}
		
}
int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	cin>>T;
	for (int tc=0; tc<T; tc++){
		memset(seg, 0, sizeof(seg));
		
		cin>>N>>M;
		
		for (int i=0; i<N; i++) pos[i] = 2*MAX + N-i-1;
		for (int i=0; i<N; i++) seg[i+2*MAX] = 1;
		for (int i=2*MAX-1; i>0; i--) seg[i]= seg[i<<1] + seg[i<<1|1];
		
		int k;
		
		for (int i=0; i<M; i++){
			cin>>k;
			cout<<get_cnt(pos[k-1]+1, 4*MAX)<<" ";
			update(pos[k-1], i, k-1);
		}
	
		cout<<'\n';
	}
	
	
	
	

	return 0;
}