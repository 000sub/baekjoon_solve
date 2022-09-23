#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n,m;
	cin>>n>>m;
	int sum[n+1] = {0};
	
	for (int i=1;i<=n;i++){
		int tmp;
		cin>>tmp;
		sum[i] = sum[i-1] + tmp;
	}
	
	for (int i=0;i<m;i++){
		int s, e;
		cin>>s>>e;
		cout<<sum[e] - sum[s-1]<<'\n';
	}
	
	
	
	return 0;
}
