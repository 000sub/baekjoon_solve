#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
#define PII pair<int,int>

using namespace std;

bool cmp(PII& a, PII& b) {
	return a.first + a.second < b.first + b.second;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int n,b,p,s;
	vector<PII> cost;
	cin>>n>>b;
	
	for (int i=0; i<n; i++) {
		cin>>p>>s;
		cost.emplace_back(p,s);
	}
	
	sort(cost.begin(), cost.end(), cmp);
	
	
	int ans = 0;
	for (int i=0; i<cost.size(); i++) {
		int cnt = 1;
		int curB = b - (cost[i].first / 2 + cost[i].second);
		if (curB < 0) continue;
		
		for (int j=0; j<cost.size(); j++) {
			if (curB >= cost[j].first + cost[j].second && i!=j) {
				curB -= cost[j].first + cost[j].second;
				cnt++;
			}
		}
		
		ans = max(ans, cnt);
	}
	
	cout<<ans;	
	return 0;
}
