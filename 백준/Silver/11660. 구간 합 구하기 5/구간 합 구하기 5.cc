#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n,m;
	cin>>n>>m;
	int sum[n+1][n+1] = {0};
	
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			int tmp;
			cin>>tmp;
			sum[i][j] = sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+tmp; 
		}
	}
	
	for (int i=0;i<m;i++){
		int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		cout<<sum[x2][y2] - sum[x1-1][y2] - sum[x2][y1-1] + sum[x1-1][y1-1]<<'\n';
	}
	
	
	
	return 0;
}
