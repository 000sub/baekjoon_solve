#include <iostream>
#include <algorithm>
#include <vector>

#define MAX 100001
using namespace std;

int N, M;
vector<pair<int, int>> v;
int dp[100001];
int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>N>>M;
	
	int a,b;
	for (int i=0; i<M; i++){
		cin>>a>>b;
		v.emplace_back(a,b);
	}
	v.emplace_back(0,0);
	
	sort(v.begin(), v.end());
	
	for (int i=1; i<=M; i++){
		for (int j=1; j<=100000; j++){
			if (j - v[i].first >=0) dp[j] = max(dp[j], dp[j-v[i].first] + v[i].second);
		}
	}
	
	for (int i=1; i<=100000; i++){
		if (dp[i] >= N) {
			cout<<i<<'\n';
			break;
		}
	}

	return 0;
}