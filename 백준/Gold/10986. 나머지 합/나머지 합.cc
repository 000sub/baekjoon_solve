#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n,m;
	long long tmp, ans=0;
	cin>>n>>m;
	long long arr[n+1] = {0};
	int cnt[1000] ={0};
	
	for (int i=1;i<=n;i++){
		cin>>tmp;
		arr[i] = arr[i-1]+tmp;
		arr[i] %= m;
		cnt[arr[i]]++;
	}
	
	for (int i=0;i<1000;i++){
		if (cnt[i]){
			tmp = (long long)cnt[i];
			
			ans += tmp*(tmp-1)/2;
			if (i==0){
				ans+=tmp;
			}
		}
	}
	
	cout<<ans;
}