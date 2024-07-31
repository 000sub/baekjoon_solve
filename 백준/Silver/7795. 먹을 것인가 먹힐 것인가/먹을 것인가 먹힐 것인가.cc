#include <bits/stdc++.h>

#define PII pair<int,int>

using namespace std;
typedef long long ll;

int main() {
	 ios::sync_with_stdio(false);
	 cin.tie(0); cout.tie(0);

	 int t, n, m, temp;
	 vector<int> a, b;

	 cin >> t;

	 while (t--) {
		 cin >> n >> m;
		 for (int i = 0; i < n; i++) {
			 cin >> temp;
			 a.push_back(temp);
		 }
		 for (int i = 0; i < m; i++) {
			 cin >> temp;
			 b.push_back(temp);
		 }

		 sort(b.begin(), b.end());

		 int ans = 0;
		 for (int i = 0; i < a.size(); i++) {
			 ans += lower_bound(b.begin(), b.end(), a[i]) - b.begin();
		 }

		 cout << ans << '\n';

		 a.clear(); b.clear();
	 }
	 
	

	return 0;
}	