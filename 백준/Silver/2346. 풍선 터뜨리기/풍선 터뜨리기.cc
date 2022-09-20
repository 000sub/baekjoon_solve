#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

int main(){
	int n, tmp;
	deque<pair<int,int>> d;
	
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>tmp;
		d.push_back(make_pair(i, tmp));
	}
	
	while (n--){
		
		if (!n){
			printf("%d", d.front().first);
			break;
		}
		
		int idx, val;
		idx = d.front().first;
		val = d.front().second;
		printf("%d ", idx);
		d.pop_front();
		if (val>0){
			val--;
		}

		
		while (val>0){
			pair<int,int> p = d.front();
			d.pop_front();
			d.push_back(p);
			val--;
		}
		
		while (val<0){
			pair<int,int> p = d.back();
			d.pop_back();
			d.push_front(p);
			val++;
		}
	}
	
	return 0;
}