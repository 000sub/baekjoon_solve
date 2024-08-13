#include <bits/stdc++.h>
#define PII pair<int,int>

using namespace std;

int p, s;
string str;
int arr[4];
int cur[4];
int ans = 0;

void check() {
	for (int i = 0; i < 4; i++) {
		if (cur[i] < arr[i]) return;
	}
	ans++;
}

void handle(char c, bool isAdd) {
	switch (c) {
	case 'A':
		isAdd ? cur[0]++ : cur[0]--;
		break;
	case 'C':
		isAdd ? cur[1]++ : cur[1]--;
		break;
	case 'G':
		isAdd ? cur[2]++ : cur[2]--;
		break;
	case 'T':
		isAdd ? cur[3]++ : cur[3]--;
		break;
	}
}
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> p >> s;
	cin >> str;
	for (int i = 0; i < 4; i++) cin >> arr[i];

	for (int i = 0; i < s; i++) {
		handle(str[i], true);
	}
	check();

	int lo = 0, hi = s - 1;
	while (1) {
		handle(str[lo], false);
		lo++;

		hi++;
		if (hi > p - 1) break;
		handle(str[hi], true);
		check();
	}

	cout << ans;
	
	return 0;
}