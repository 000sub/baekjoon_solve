#include <bits/stdc++.h>

#define PII pair<int,int>
#define PIII pair<int,PII>
using namespace std;
typedef long long ll;

int N;
int parent[101];

struct Node {
	int s;
	int e;
	double cost;

	bool operator<(Node& other) {
		return cost < other.cost;
	}
};

pair<double,double> stars[101];
vector<Node> v;

int Find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);
	if (x < y) parent[y] = x;
	else parent[x] = y;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		parent[i] = i;
		cin >> stars[i].first >> stars[i].second;
		for (int j = 0; j < i; j++) {
			double cost = sqrt((stars[i].first - stars[j].first) * (stars[i].first - stars[j].first) + (stars[i].second - stars[j].second) * (stars[i].second - stars[j].second));
			v.push_back({ i, j, cost });
		}
	}
	
	sort(v.begin(), v.end());
	double ans = 0.0;
	for (int i = 0; i < v.size(); i++) {
		if (Find(v[i].s) != Find(v[i].e)) {
			Union(v[i].s, v[i].e);
			ans += v[i].cost;
		}
	}

	cout.precision(3);
	cout << ans;

	return 0;
}