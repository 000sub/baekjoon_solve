#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <set>
#include <string>
#include <map>

#define PII pair<int,int>
using namespace std;

int N;
int arr[3][201];
int cnt[3][101];
int score[201];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
    cin>>N;
	for (int i=0; i<N; i++) {
		for (int j=0; j<3; j++) {
			cin>>arr[j][i];
			cnt[j][arr[j][i]]++;
		}
	}

	for (int i=0; i<3; i++) {
		for (int j=0; j<N; j++) {
			if (cnt[i][arr[i][j]] == 1) {
				score[j] += arr[i][j];
			}
		}
	}

	for (int i=0; i<N; i++) {
		cout << score[i] << '\n';
	}

    return 0;
}