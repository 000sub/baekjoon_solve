#include <iostream>
#include <algorithm>
#include <queue>
#include <limits.h>
using namespace std;

int main(){
	int k,n,temp,cnt=0, prev=0;
	priority_queue<int,vector<int>,greater<int>> pq;
	cin>>k>>n;
	
	int arr[k];
	for (int i=0;i<k;i++){
		cin>>arr[i];
	}
	
	for (int i=0;i<k;i++){
		pq.push(arr[i]);
	}
	
	while (cnt!=n){
		temp = pq.top();
		if (temp==prev){
			pq.pop();
			continue;
		}
		
		for (int i=0;i<k;i++){
			int temp2 = temp * arr[i];
			if (INT_MAX/arr[i] > temp) pq.push(temp2);
		}
		
		prev = temp;
		pq.pop();
		cnt++;
	}
	cout<<temp;
	
	
}