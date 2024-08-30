#include <bits/stdc++.h>

#define PII pair<int,int>
#define PIII pair<int,PII>

using namespace std;
typedef long long ll;
int N;
int A[21][21];
bool visited[21][21];
int ans = 1e9, temp[5];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) cin >> A[i][j];
	
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			for (int d1 = 1; d1 < N; d1++) {
				for (int d2 = 1; d2 < N; d2++) {
					if (x + d1 + d2 >= N || y - d1 < 0 || y + d2 >= N) continue;
					memset(temp, 0, sizeof(temp));
					memset(visited, false, sizeof(visited));

					for (int i = 0; i <= d1 + d2; i++) {
						int sy = i <= d1 ? y - i :  y - 2*d1 + i;
						int ey = i <= d2 ? y + i : y + 2*d2 - i;
						for (int j = sy; j <= ey; j++) {
							visited[x+i][j] = true;
							temp[4] += A[x+i][j];
						}
					}
					
					for (int i = 0; i < x + d1; i++) {
						for (int j = 0; j <= y; j++) {
							if (!visited[i][j]) temp[0] += A[i][j];
						}
					}

					for (int i = 0; i <= x + d2; i++) {
						for (int j = y+1; j < N; j++) {
							if (!visited[i][j]) temp[1] += A[i][j];
						}
					}

					for (int i = x+d1; i < N; i++) {
						for (int j = 0; j < y-d1+d2; j++) {
							if (!visited[i][j]) temp[2] += A[i][j];
						}
					}

					for (int i = x+d2+1; i < N; i++) {
						for (int j = y-d1+d2; j < N; j++) {
							if (!visited[i][j]) temp[3] += A[i][j];
						}
					}

					int minD = 1e9, maxD = -1;
					for (int i = 0; i < 5; i++) {
						maxD = max(maxD, temp[i]);
						minD = min(minD, temp[i]);
					}

					ans = min(ans, maxD - minD);
				}
			}
		}
	}

	cout << ans;
	return 0;
}