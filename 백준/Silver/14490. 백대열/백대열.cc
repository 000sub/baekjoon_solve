#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <set>
#include <string>
#include <map>

#define PII pair<int,int>
using namespace std;
typedef long long ll;

int a, b;

int gcd(int x, int y) {
	return x % y == 0 ? y : gcd(y, x % y);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	scanf("%d:%d", &a, &b);

	int GCD = gcd(a, b);

	printf("%d:%d", a/GCD, b/GCD);
    
    return 0;
}