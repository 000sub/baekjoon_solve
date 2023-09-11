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
	
	int a,b,c;
	
	cin>>N>>M;
	
	for (int i=1; i<=N; i++) for (int j=1; j<=N; j++) dist[i][j] = i==j ? 0 : INF;
	for (int i=0; i<M; i++){
		cin>>a>>b>>c;
		dist[a][b] = min(dist[a][b], c);
	}
	
	
	update();
	
	for (int i=1; i<=N; i++) {
		for (int j=1; j<=N; j++) {
			dist[i][j] == INF ? cout<<0<<" " : cout<<dist[i][j]<<" ";
		}
		cout<<'\n';
	}


	
	return 0;
}