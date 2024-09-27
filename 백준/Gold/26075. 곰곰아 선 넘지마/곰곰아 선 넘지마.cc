#include <bits/stdc++.h>

#define PII pair<int,int>
#define PIII pair<int,PII>
using namespace std;
typedef long long ll;

int N, M;
ll ans = 0;
char s[100001], t[100001];
vector<int> v1, v2;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;

	char ch;
	for (int i = 0; i < N + M; i++) {
		cin >> ch;
		if (ch == '1') v1.push_back(i);
	}

	for (int i = 0; i < N + M; i++) {
		cin >> ch;
		if (ch == '1') v2.push_back(i);
	}



	for (int i = 0; i < M; i++) {
		ans += abs(v1[i] - v2[i]);
	}

	if (ans % 2)
		cout << (ans / 2)*(ans / 2) + (ans / 2 + 1)*(ans / 2 + 1);
	else
		cout << (ans / 2)*(ans / 2) + (ans / 2)*(ans / 2);
	return 0;
}