#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n,s,sum,cnt = 0;
	cin>>n>>s;
	int arr[n];
	for (int i=0;i<n;i++){
		cin>>arr[i];
	}
	
	for (int i=1;i<pow(2,n);i++){
		sum = 0;
		for (int j=0;j<n;j++){
			if (i & (1<<j)) sum+=arr[j];
			
		}
		if (sum==s) cnt++;
	}
	
	cout<<cnt;
}