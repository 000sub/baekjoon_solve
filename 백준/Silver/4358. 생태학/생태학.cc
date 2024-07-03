#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <cmath>

using namespace std;

float calc(float n, float total) {
	return n / total * 100;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	map<string, int> m;
	string s;
	int total = 0;
	
	while (getline(cin, s)) {
		m[s]++; 
		total++;
	}
	
	cout << fixed;
	cout.precision(4);
	
	for (auto& entry : m) {
		cout<<entry.first<<" "<<calc((float)entry.second, (float)total)<<'\n';
	}
}