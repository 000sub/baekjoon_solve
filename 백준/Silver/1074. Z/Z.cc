#include <iostream>
#include <algorithm>

using namespace std;



int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int N, r, c;
	int ans = 0;
	
	cin>>N>>r>>c;
	
	while (N) {
		int k = 1<<(N-1);
		if (k > r && k > c) {
			//do nothing
		} 
		else if (k <= r && k <= c) {
			ans += 3*(k*k);
			r-=k;
			c-=k;
		} 
		else if (k > r && k <= c) {
			ans += (k*k);
			c-=k;
		} 
		else {
			ans += 2*(k*k);
			r-=k;
		}
		
		N--;
	}
	
	cout<<ans;
	
	
	
	return 0;
}