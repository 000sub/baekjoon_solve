#include <iostream>
#include <cmath>
using namespace std;
unsigned long long n, k;


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	
	k = sqrt(n);
	if (k*k<n){
		k++;
	}
	cout<<k;
	
	return 0;
}
