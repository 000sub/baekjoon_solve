#include <iostream>
#include <algorithm>
#include <string>
#define MAXNUM 200000
using namespace std;

int arr[26][MAXNUM+2] = {0};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int l,p,v;
	int i=1;
	
	while (1){
		int ans = 0;
		cin>>l>>p>>v;
		
		if (l==0 && p==0 && v==0) break;
		
		ans += (v/p) * l;
		ans += min(l,v%p);
		
		
		cout<<"Case "<<i++<<": "<<ans<<'\n';
	}
	
	
	return 0;
}
