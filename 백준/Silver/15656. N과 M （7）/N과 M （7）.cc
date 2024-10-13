#include <bits/stdc++.h>

#define PII pair<int,int>
using namespace std;
typedef long long ll;

int N, M;
int arr[8];
vector<int> v;

void dfs(int cnt) {
	if (cnt == M) {
		for (int i : v) cout << i << " ";
		cout << '\n';
		return;
	}

	for (int i = 0; i < N; i++) {
		v.push_back(arr[i]);
		dfs(cnt + 1);
		v.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> arr[i];
	sort(arr, arr + N);
	dfs(0);

	return 0;
}