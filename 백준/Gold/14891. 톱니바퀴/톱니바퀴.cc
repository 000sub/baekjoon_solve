#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>

#define PII pair<int,int>
using namespace std;
typedef long long ll;
typedef unsigned char uc;

uc gears[4];
int dirs[4];
PII ops[101];
int k;


uc strToUc(string s) {
	uc res = 0;
	for (int i = 0; i < 8; i++) {
		res |= ((s[7-i] - '0') << i);
	}
	return res;
}

void input() {
	string s;
	for (int i = 0; i < 4; i++) {
		cin >> s;
		gears[i] = strToUc(s);
	}
	cin >> k;

	int a, b;
	for (int i = 0; i < k; i++) {
		cin >> a >> b;
		ops[i].first = a - 1;
		ops[i].second = b;
	}
}

bool canMove(uc prev, uc next) {
	return (prev & (1 << 5)) ^ (((next & (1 << 1)) << 4));
}

void rotate(int gearIdx, int dir) {
	uc gear = gears[gearIdx];

	if (dir == 1) {
		int temp = gear & 1;
		gear >>= 1;
		gear |= (temp << 7);
	}
	else if (dir == -1) {
		int temp = (gear & (1 << 7));
		gear <<= 1;
		gear |= (temp >> 7);
	}
	else return;

	gears[gearIdx] = gear;
}

void checkMove(int start, int startDir) {
	memset(dirs, 0, sizeof(dirs));
	dirs[start] = startDir;

	for (int i = start - 1; i >= 0; i--) {
		if (canMove(gears[i], gears[i + 1])) {
			dirs[i] = dirs[i + 1] * -1;
		}
		else break;
	}

	for (int i = start + 1; i < 4; i++) {
		if (canMove(gears[i - 1], gears[i])) {
			dirs[i] = dirs[i - 1] * -1;
		}
		else break;
	}
}

int calcScore() {
	int res = 0;
	for (int i = 0; i < 4; i++) {
		if (gears[i] & (1 << 7)) {
			res |= (1 << i);
		}
	}

	return res;
}

void simulate() {
	for (int i = 0; i < k; i++) {
		int gearIdx = ops[i].first;
		int dir = ops[i].second;

		checkMove(gearIdx, dir);
		for (int i = 0; i < 4; i++) {
			rotate(i, dirs[i]);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	input();
	simulate();

	cout << calcScore();


	return 0;
}