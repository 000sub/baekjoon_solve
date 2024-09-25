#include <iostream>

#define PII pair<int,int>
#define PIII pair<int,PII>
using namespace std;

string s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	while (true) {
		getline(cin, s);
		if (s == "end") break;
		int oCnt = 0, xCnt = 0;
		int oBingo = 0, xBingo = 0;
		bool isFull = true;
		for (int i = 0; i < 9; i++) {
			if (s[i] == '.') isFull = false;
			else if (s[i] == 'O') oCnt++;
			else xCnt++;
		}
		if (s[0] == s[1] && s[1] == s[2] && s[2] == s[0] && s[0] != '.') s[0] == 'O' ? oBingo++ : xBingo++;
		if (s[3] == s[4] && s[4] == s[5] && s[5] == s[3] && s[3] != '.') s[3] == 'O' ? oBingo++ : xBingo++;
		if (s[6] == s[7] && s[7] == s[8] && s[8] == s[6] && s[6] != '.') s[6] == 'O' ? oBingo++ : xBingo++;

		if (s[0] == s[3] && s[3] == s[6] && s[6] == s[0] && s[0] != '.') s[0] == 'O' ? oBingo++ : xBingo++;
		if (s[1] == s[4] && s[4] == s[7] && s[7] == s[1] && s[1] != '.') s[1] == 'O' ? oBingo++ : xBingo++;
		if (s[2] == s[5] && s[5] == s[8] && s[8] == s[2] && s[2] != '.') s[2] == 'O' ? oBingo++ : xBingo++;

		if (s[0] == s[4] && s[4] == s[8] && s[8] == s[0] && s[0] != '.') s[0] == 'O' ? oBingo++ : xBingo++;
		if (s[2] == s[4] && s[4] == s[6] && s[6] == s[2] && s[2] != '.') s[2] == 'O' ? oBingo++ : xBingo++;

		int allBingo = oBingo + xBingo;

		if ((xBingo >= 1 && oBingo == 0 && xCnt == oCnt + 1) ||
			(xBingo == 0 && oBingo >= 1 && xCnt == oCnt) ||
			(oBingo == 0 && xBingo == 0 && xCnt == 5 && oCnt == 4))
			{
				cout << "valid\n";
			}
		else {
			cout << "invalid\n";
		}
	}
	return 0;
}