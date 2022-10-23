#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int r,c,q, temp, cnt;
	int r1,c1,r2,c2;
	cin>>r>>c>>q;
	int psum[r+1][c+1] = {};
	
	for (int i=1;i<=r;i++){
		for (int j=1;j<=c;j++){
			cin>>temp;
			psum[i][j] = (long long)temp + psum[i][j-1] + psum[i-1][j] - psum[i-1][j-1];
		}
	}
	
	for (int i=0;i<q;i++){
		cin>>r1>>c1>>r2>>c2;
		cnt = (r2-r1+1)*(c2-c1+1);
		cout<<(psum[r2][c2] - psum[r1-1][c2] - psum[r2][c1-1] + psum[r1-1][c1-1])/cnt<<'\n';
	}
	
	
	return 0;
	
}