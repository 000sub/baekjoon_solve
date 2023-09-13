#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>

#define MAX 51

using namespace std;

int N;
int dist[MAX][MAX]; 
const int INF = 1e9;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>N;
	
	char c;
	for (int i=1; i<=N; i++) for (int j=1; j<=N; j++) {
		cin>>c;
		dist[i][j] = (c=='N') ? INF : 1;
	}
		
	for (int k=1; k<=N; k++){
		for (int i=1; i<=N; i++){
			for (int j=1; j<=N; j++){
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	
	int ans = 0;
	int tmp;
	for (int i=1;i<=N;i++){
		tmp = 0;
		for (int j=1;j<=N;j++){
			if (i==j) continue;
			if (dist[i][j] == 1 || dist[i][j] == 2) tmp++;
		}
		
		ans = max(ans, tmp);
	}

	cout<<ans<<'\n';
	
	return 0;
}