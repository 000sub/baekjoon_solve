#include <bits/stdc++.h>

#define PII pair<int,int>
#define PIII pair<int,PII>

using namespace std;
typedef long long ll;

int arr[6][3], temp[6][3];
bool flag = false;

bool check() {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 3; j++) {
			if (arr[i][j] != temp[i][j]) return false;
		}
	}

	return true;
}

void BT(int i, int j) {
	if (i == 5) {
		if (check()) flag = true;
		return;
	}

	if (flag) return;
	//win
	temp[i][0]++;
	temp[j][2]++;
	j == 5 ? BT(i+1, i+2) : BT(i, j+1);
	temp[i][0]--;
	temp[j][2]--;

	//eq
	temp[i][1]++;
	temp[j][1]++;
	j == 5 ? BT(i + 1, i + 2) : BT(i, j + 1);
	temp[i][1]--;
	temp[j][1]--;

	//lose
	temp[i][2]++;
	temp[j][0]++;
	j == 5 ? BT(i + 1, i + 2) : BT(i, j + 1);
	temp[i][2]--;
	temp[j][0]--;

}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);

	for (int t = 0; t < 4; t++) {
		flag = false;
		bool valid = true;
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 3; j++) {
				cin >> arr[i][j];
				temp[i][j] = 0;
			}

			if (arr[i][0] + arr[i][1] + arr[i][2] != 5) valid = false;
		}
			
		if (valid) BT(0,1);

		flag ? cout<<1 : cout<<0;
		cout << " ";
	}
	cout << '\n';
	return 0;
}