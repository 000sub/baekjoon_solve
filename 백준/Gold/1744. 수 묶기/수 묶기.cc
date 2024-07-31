#include <bits/stdc++.h>

#define PII pair<int,int>

using namespace std;
typedef long long ll;

int n, temp;
vector<int> p, m;

int main() {
	 ios::sync_with_stdio(false);
	 cin.tie(0); cout.tie(0);

	 
	 cin >> n;
	 for (int i = 0; i < n; i++) {
		 cin >> temp;
		 if (temp > 0) p.push_back(temp);
		 else m.push_back(temp);
	 }

	 int ans = 0;

	 sort(p.begin(), p.end(), greater<>());
	 sort(m.begin(), m.end());

	 if (p.size() % 2) {
		 ans += p[p.size() - 1];
		 p.pop_back();
	 }

	 for (int i = 0; i < p.size(); i += 2) {
		 if (p[i] == 1 || p[i + 1] == 1) ans += p[i] + p[i + 1];
		 else ans += p[i] * p[i + 1];
	 }

	 if (m.size() % 2) {
		 ans += m[m.size() - 1];
		 m.pop_back();
	 }

	 for (int i = 0; i < m.size(); i += 2) {
		 ans += m[i] * m[i + 1];
	 }
	 

	 cout << ans;
	

	return 0;
}	