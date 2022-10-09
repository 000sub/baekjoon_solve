#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	vector<pair<int,int>> v;
	priority_queue<int, vector<int>, greater<int>> pq;
	int n,s,e;
	cin>>n;
	
	for (int i=0;i<n;i++){
		cin>>s>>e;
		v.emplace_back(s,e);
	}
	
	sort(v.begin(), v.end());
	
	pq.push(v[0].second);
	for (int i=1;i<n;i++){
		if (pq.top() <= v[i].first){
			pq.pop();	
		}
		pq.push(v[i].second);
	}
	cout<<pq.size();
}