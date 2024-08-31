#include <bits/stdc++.h>

#define PII pair<int,int>
#define PIII pair<int,PII>

using namespace std;
typedef long long ll;
const int INF = 1e9;

int N, S, P;
int parent[501];
PII planets[501];
vector<tuple<double, int, int> > v;

inline double getDist(int x1, int y1, int x2, int y2) {
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int Find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = Find(parent[x]);
}

bool Union(int x, int y) {
	x = Find(x);
	y = Find(y);
	if (x == y) return false;
	if (x > y) parent[x] = y;
	else parent[y] = x;
	return true;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	while (N--) {
		cin >> S >> P;

		for (int i = 0; i < P; i++) parent[i] = i;

		for (int i = 0; i < P; i++) {
			cin >> planets[i].first >> planets[i].second;
		}

		for (int i = 0; i < P - 1; i++) {
			for (int j = i + 1; j < P; j++) {
				v.push_back({ getDist(planets[i].first, planets[i].second, planets[j].first, planets[j].second), i, j });
			}
		}

		double ans = 0.0;
		sort(v.begin(), v.end(), [](tuple<double, int, int>& a, tuple<double, int, int>& b) {return get<0>(a) < get<0>(b); });
		if (S - 1 >= P - 1) {
			cout << fixed << setprecision(2) << ans;
			v.clear();
			continue;
		}
		for (int i = 0, cnt=0; i < v.size(); i++) {
			auto &[c, a, b] = v[i];
			if (Union(a, b)) cnt++;
			if (cnt + S - 1 == P - 1) { ans = c;  break; }
		}
		cout << fixed << setprecision(2) << ans << '\n';
		v.clear();
	}
	return 0;


}