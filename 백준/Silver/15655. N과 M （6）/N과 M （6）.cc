#include <bits/stdc++.h>

#define PII pair<int,int>
using namespace std;

int N, M;
int arr[8];
vector<int> v;

void bt(int idx, int cnt) {
	if (cnt == M) {
		for (int i : v) cout << i << " ";
		cout << '\n';
		return;
	}

	if (idx == N) return;

	v.push_back(arr[idx]);
	bt(idx + 1, cnt + 1);
	v.pop_back();
	bt(idx + 1, cnt);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> arr[i];
	sort(arr, arr + N);

	bt(0, 0);

	return 0;
}