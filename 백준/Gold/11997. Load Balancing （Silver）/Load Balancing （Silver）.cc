#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<int,int>> v;
vector<int> vx, vy;
int n, x, y, tmpx, tmpy;
int m = 1000;
int q1,q2,q3,q4;
int arr[1001][1001] = {};

int func(int y, int x, int y2, int x2)
{
	return arr[y2][x2] - arr[y2][x] - arr[y][x2] + arr[y][x];
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	
	cin >> n;
	
	
	for (int i=0;i<n;i++){
		cin>>x>>y;
		v.emplace_back(x, y);
		vx.push_back(x);
		vy.push_back(y);
	}
	
	sort(vx.begin(), vx.end());
	sort(vy.begin(), vy.end());
	vx.erase(unique(vx.begin(), vx.end()), vx.end());
	vy.erase(unique(vy.begin(), vy.end()), vy.end());
	
	for (int i=0;i<n;i++){
		tmpx = lower_bound(vx.begin(), vx.end(), v[i].first) - vx.begin() + 1;
		tmpy = lower_bound(vy.begin(), vy.end(), v[i].second) - vy.begin() + 1;
		arr[tmpx][tmpy] = 1;
	}
	
	for (int i=1;i<=1000;i++){
		for (int j=1;j<=1000;j++){
			arr[i][j] = arr[i][j] + arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1];
		}
	}
	
	for (int i=0;i<=1000;i++){
		for (int j=0;j<=1000;j++){
			q1 = func(0, 0, i, j);
			q2 = func(i, j, 1000, 1000);
			q3 = func(0, j, i, 1000);
			q4 = func(i, 0, 1000, j);
			m = min(m,max({q1,q2,q3,q4}));
		}
	}
	
	cout<<m;
	return 0;
	
}