#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;


int isfinished(int n, int arr[25][25]){
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			if (arr[i][j] == 1){
				return 0;
			}
		}
	} 
	
	return 1;
}

int main(){

	int arr[25][25] = {0};
	int n;
	int dx[4] = {1,-1,0,0};
	int dy[4] = {0,0,1,-1};
	vector<int> v;
	
	cin>>n;
	
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			scanf("%1d", &arr[i][j]);
		}
	}
	
	while (!isfinished(n, arr)){
		queue<pair<int,int>> q;
		int i, j, cnt=0;
		
		for (i=0;i<n;i++){
			for (j=0;j<n;j++){
				if (arr[i][j] == 1){
					q.push(make_pair(i,j));
					arr[i][j] = 0;
					i=n+1;
					j=n+1;
				}
			}
		}
		
		while (!q.empty()){
			int y = q.front().first;
			int x = q.front().second;
			q.pop();
			cnt++;
			
			for (int k=0; k<4; k++){
				int nx = x+dx[k];
				int ny = y+dy[k];
				
				if (nx>=0 && nx<n && ny>=0 && ny<n && arr[ny][nx]){
					q.push(make_pair(ny, nx));
					arr[ny][nx] = 0;
				}
				
			}
		}
		
		v.push_back(cnt); 	
	}
	
	sort(v.begin(), v.end());
	cout<<v.size()<<'\n';
	for (int i=0;i<v.size();i++){
		cout<<v[i]<<'\n';
	}
	
	return 0;
}
