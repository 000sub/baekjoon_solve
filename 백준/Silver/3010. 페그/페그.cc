#include <bits/stdc++.h>
#include <cstdio>
#define PII pair<int,int>
#define PIII pair<int,PII>

using namespace std;
typedef long long ll;
char arr[10][10];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

int main(void) {
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			arr[i][j] = getchar();
		}
		getchar();
	}

	int ans = 0;

	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			if (arr[i][j] == '.') {
				for (int d = 0; d < 4; d++) {
					if (arr[i + dx[d]][j + dy[d]] == 'o'
						&& arr[i + 2 * dx[d]][j + 2 * dy[d]] == 'o') ans++;
				}
			}
		}
	}

	printf("%d", ans);
	return 0;
}