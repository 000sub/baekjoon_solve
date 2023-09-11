#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>

#define MAX 101

using namespace std;

const int INF = 1e9;
int N,M;
int dist[MAX][MAX]; 
void update(){
	
	
	for (int k=1; k<=N; k++){
		for (int i=1; i<=N; i++){
			for (int j=1; j<=N; j++){
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int a,b;
	
	cin>>N>>M;
	
	for (int i=1; i<=N; i++) for (int j=1; j<=N; j++) dist[i][j] = i==j ? 0 : INF;
	for (int i=0; i<M; i++){
		cin>>a>>b;
		dist[a][b] = 1;
		dist[b][a] = 1;
	}
	
	
	update();
	int ans = INF;
	int ans_i = -1;
	for (int i=N; i>=1; i--) {
		int tmp = 0;
		for (int j=1; j<=N; j++) {
			if (dist[i][j] != INF) tmp+=dist[i][j];
		}
		if (tmp <= ans){
			ans = tmp;
			ans_i = i;
		}
	}
	
	cout<<ans_i<<'\n';


	
	return 0;
}