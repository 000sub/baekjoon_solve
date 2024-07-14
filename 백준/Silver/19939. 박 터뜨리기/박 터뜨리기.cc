#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <cstring>
#include <cmath>
#include <map>
typedef long long ll;
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, k, sum=0;
	cin>>n>>k;
	
	for (int i=1;i<=k;i++) sum+=i;
	if (n<sum) {
		cout<<-1;
		return 0;
	}
	(n-sum)%k == 0 ? cout<<k-1 : cout<<k;
	return 0;
}