#include <iostream>
#include <algorithm>

using namespace std;

void move(int n, int x, int y){
	if (n==0) return;
	move(n-1, x, 6-x-y);
	cout<<x<<" "<<y<<'\n';
	move(n-1, 6-x-y, y);
	
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int N;
	int ans;
	
	cin>>N;
	ans = (1<<N) - 1;	
	cout<<ans<<'\n';
	move(N, 1,3);
	
	
	
	
	return 0;
}