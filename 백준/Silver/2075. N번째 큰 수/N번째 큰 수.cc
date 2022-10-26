#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n, cnt=0;
	priority_queue<int, vector<int>, greater<int>> pq;
	
	cin>>n;
	
	int temp;
	for (int i=0;i<n;i++){
		cin>>temp;
		pq.push(temp);
	}
	int total = n*n-n;
	for (int i=0;i<total;i++){
		cin>>temp;
		if (temp > pq.top()){
			pq.pop();
			pq.push(temp);
		}
	}
	cout << pq.top();	
	return 0;
	
}