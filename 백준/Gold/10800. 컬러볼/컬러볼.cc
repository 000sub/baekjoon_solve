#include <bits/stdc++.h>
#define PII pair<int,int>
#define PIII pair<int,PII>

using namespace std;
typedef long long ll;

typedef struct Ball {
	int color;
	int size;
	int idx;
} Ball;

vector<Ball> v;
int ans[200001], C[200001],S[2001];

bool cmp(Ball& a, Ball& b) {
	if (a.size != b.size) return a.size < b.size;
	return a.color < b.color;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N, c, s;

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> c >> s;
		v.push_back({ c,s,i });
	}

	sort(v.begin(), v.end(), cmp);

	int sum = 0;

	for (int i = 0; i < N; i++) {
		int color = v[i].color;
		int size = v[i].size;
		int idx = v[i].idx;

		ans[idx] = sum - C[color] - S[size];
		C[color] += size;
		S[size] += size;
		sum += size;
		if (i > 0 && v[i - 1].color == color && v[i - 1].size == size) ans[idx] = ans[v[i - 1].idx];
	}

	for (int i=1; i<=N; i++) cout << ans[i]<<'\n';
	return 0;
}