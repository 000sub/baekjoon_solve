#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n, m, cnt = 0;
	list<int> li;
	cin>>n>>m;
	
	for (int i=1;i<=n;i++){
		li.push_back(i);
	}
	
	for (int i=0;i<m;i++){
		int cur;
		cin >> cur;
		
		if (cur != li.front()){
			auto it = find(li.begin(), li.end(), cur);
			int idx = distance(li.begin(), it);
			if (idx > n/2){
				while (cur != li.front()){
					int tmp = li.back();
					li.pop_back();
					li.push_front(tmp);
					cnt++;
				}
			}
			
			else {
				while (cur != li.front()){
					int tmp = li.front();
					li.pop_front();
					li.push_back(tmp);
					cnt++;
				}
			}
		}
		li.pop_front();
		n--;

	}
	
	cout<<cnt;
	
	
	return 0;
}