#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int N;
vector<pair<int, int>> v;
priority_queue<int, vector<int>, greater<int>> pq;

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>N;
	int n, s, e;
	for (int i=0; i<N; i++){
		cin>>n>>s>>e;
		v.emplace_back(s,e);

	}
	
	sort(v.begin(), v.end());
	int cnt = 1;
	pq.push(v[0].second);
	
	for (int i=1; i<N; i++){
		int end = pq.top();
		if (end > v[i].first) cnt++;
		else pq.pop();
		pq.push(v[i].second);
	}
	
	cout<<cnt<<'\n';

	return 0;
}