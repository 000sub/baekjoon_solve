#include <bits/stdc++.h>

#define PII pair<int,int>
#define PFF pair<float, float>

using namespace std;
typedef long long ll;

char u[3][3];
char d[3][3];
char f[3][3];
char b[3][3];
char l[3][3];
char r[3][3];
char temp[3][3];

void rotateArea(char arr[3][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			temp[j][2 - i] = arr[i][j];
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			arr[i][j] = temp[i][j];
		}
	}
}

void Lrotate(int cnt) {
	for (int i = 0; i < cnt; i++) {
		rotateArea(l);
		//u->temp, b -> u, d -> b, f -> d, temp -> f
		for (int i = 0; i < 3; i++) temp[i][0] = u[i][0];
		for (int i = 0; i < 3; i++) u[i][0] = b[i][0];
		for (int i = 0; i < 3; i++) b[i][0] = d[i][0];
		for (int i = 0; i < 3; i++) d[i][0] = f[i][0];
		for (int i = 0; i < 3; i++) f[i][0] = temp[i][0];
	}

	
}

void Rrotate(int cnt) {
	for (int i = 0; i < cnt; i++) {
		rotateArea(r);
		//u->temp, f->u, d->f, b->d, temp->b
		for (int i = 0; i < 3; i++) temp[i][2] = u[i][2];
		for (int i = 0; i < 3; i++) u[i][2] = f[i][2];
		for (int i = 0; i < 3; i++) f[i][2] = d[i][2];
		for (int i = 0; i < 3; i++) d[i][2] = b[i][2];
		for (int i = 0; i < 3; i++) b[i][2] = temp[i][2];
	}
}

void Urotate(int cnt) {
	for (int i = 0; i < cnt; i++) {
		rotateArea(u);
		//f->temp, r->f, b->r, l->b, temp->l
		for (int i = 0; i < 3; i++) temp[0][i] = f[0][i];
		for (int i = 0; i < 3; i++) f[0][i] = r[0][i];
		for (int i = 0; i < 3; i++) r[0][i] = b[2][2 - i];
		for (int i = 0; i < 3; i++) b[2][i] = l[0][2 - i];
		for (int i = 0; i < 3; i++) l[0][i] = temp[0][i];

	}
}

void Drotate(int cnt) {
	for (int i = 0; i < cnt; i++) {
		rotateArea(d);
		//f->temp, l->f, b->l, r->b, temp->r
		for (int i = 0; i < 3; i++) temp[2][i] = f[2][i];
		for (int i = 0; i < 3; i++) f[2][i] = l[2][i];
		for (int i = 0; i < 3; i++) l[2][i] = b[0][2 - i];
		for (int i = 0; i < 3; i++) b[0][i] = r[2][2 - i];
		for (int i = 0; i < 3; i++) r[2][i] = temp[2][i];
	}

	
}

void Frotate(int cnt) {
	for (int i = 0; i < cnt; i++) {
		rotateArea(f);
		//u->temp, l->u, d->l, r->d, temp->r
		for (int i = 0; i < 3; i++) temp[2][i] = u[2][i];
		for (int i = 0; i < 3; i++) u[2][i] = l[2 - i][2];
		for (int i = 0; i < 3; i++) l[i][2] = d[0][i];
		for (int i = 0; i < 3; i++) d[0][i] = r[2 - i][0];
		for (int i = 0; i < 3; i++) r[i][0] = temp[2][i];
	}
}

void Brotate(int cnt) {
	for (int i = 0; i < cnt; i++) {
		rotateArea(b);
		//u->temp, r->u, d->r, l->d, temp->l
		for (int i = 0; i < 3; i++) temp[0][i] = u[0][i];
		for (int i = 0; i < 3; i++) u[0][i] = r[i][2];
		for (int i = 0; i < 3; i++) r[i][2] = d[2][2 - i];
		for (int i = 0; i < 3; i++) d[2][i] = l[i][0];
		for (int i = 0; i < 3; i++) l[i][0] = temp[0][2 - i];
	}
}

void init() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			u[i][j] = 'w';
			d[i][j] = 'y';
			f[i][j] = 'r';
			b[i][j] = 'o';
			l[i][j] = 'g';
			r[i][j] = 'b';
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t, n;

	cin >> t;

	while (t--) {
		init();
		cin >> n;
		while (n--) {
			char s[5];
			cin >> s;

			if (s[0] == 'L') s[1] == '+' ? Lrotate(1) : Lrotate(3);
			else if (s[0] == 'R') s[1] == '+' ? Rrotate(1) : Rrotate(3);
			else if (s[0] == 'U') s[1] == '+' ? Urotate(1) : Urotate(3);
			else if (s[0] == 'D') s[1] == '+' ? Drotate(1) : Drotate(3);
			else if (s[0] == 'F') s[1] == '+' ? Frotate(1) : Frotate(3);
			else if (s[0] == 'B') s[1] == '+' ? Brotate(1) : Brotate(3);
		}

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cout << u[i][j];
			}
			cout << '\n';
		}
	}

	return 0;
}