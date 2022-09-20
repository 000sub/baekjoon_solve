#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	int n,k;
	cin>>n>>k;
	queue<int> q;
	vector<int> v;
	
	for (int i=1;i<=n;i++){
		q.push(i);
	}
	
	printf("<");
	
	while (n--){
		if (n==0){
			printf("%d>", q.front());
			break;
		}
		for (int i=0;i<k-1;i++){
			int tmp = q.front();
			q.pop();
			q.push(tmp);
		}
		printf("%d, ", q.front());
		q.pop();
	}
	
	
	return 0;
}
