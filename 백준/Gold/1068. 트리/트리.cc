#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int parent[50];

bool check(int idx, int x){
	while (idx != -1){
		if (idx == x) return false;
		idx = parent[idx];
	}
	return true;
}
bool is_leaf(int x){
	for (int i=0; i<N; i++){
		if (check(i, M) && parent[i] == x) return false;
	}
	
	return true;
}
int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>N;
	for (int i=0; i<N; i++) cin>>parent[i];
	cin>>M;
	
	int cnt=0;
	for (int i=0; i<N; i++){
		if (check(i, M) && is_leaf(i)) cnt++;
	}
	
	cout<<cnt<<'\n';
	
	

	return 0;
}