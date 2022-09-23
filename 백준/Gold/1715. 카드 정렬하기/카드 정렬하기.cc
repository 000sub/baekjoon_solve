#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <string>

typedef long long LL;
using namespace std;

int main(){
	int n;
	LL ans=0;
	cin>>n;
	
	priority_queue<LL, vector<LL>, greater<LL>> pq;
	
	for (int i=0;i<n;i++){
		int tmp;
		cin>>tmp;
		pq.push((LL)tmp);
	}
	
	while (pq.size()>1){
		LL t1, t2;
		t1 = pq.top();
		pq.pop();
		t2 = pq.top();
		pq.pop();
		ans = ans+t1+t2;
		pq.push(t1+t2);
	}

	
	cout<<ans;
	
	
	
	
	return 0;
}
