#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>

#define MAX 21

using namespace std;

int N;
int dist[MAX][MAX]; 
bool rm[MAX][MAX];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>N;
	
	for (int i=1; i<=N; i++) for (int j=1; j<=N; j++) cin>>dist[i][j];
	
	int cnt = 0;
	
	for (int k=1; k<=N; k++){
		for (int i=1; i<=N; i++){
			for (int j=1; j<=N; j++){
					if (i>=j || k==i || k==j) continue;
					if (dist[i][k] + dist[k][j] == dist[i][j]) {rm[i][j] = true;}
					else if (dist[i][k] + dist[k][j] <dist[i][j]) {cout<<-1<<'\n';return 0;}
			}
		}
	}
	
	for (int i=1; i<=N; i++){
		for (int j=1; j<=N; j++){
			if (i>=j || rm[i][j]) continue;
			cnt+=dist[i][j];
		}
	}

	cout<<cnt<<'\n';
	
	return 0;
}