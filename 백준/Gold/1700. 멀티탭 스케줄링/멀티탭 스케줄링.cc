#include <iostream>
#include <algorithm>
#include <cstring>

#define INF 1000000
using namespace std;

int n,k;
int used[100], order[100];

int get_dist(int idx, int val){
	for (int i = idx+1; i<k; i++){
		if (val == order[i]){
			return i-idx;
		}
	}
	
	return INF;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>k;
	
	int ans = 0;
	
	for (int i=0; i<k; i++) cin>>order[i];
	memset(used, -1, sizeof(used));
	
	for (int i=0; i<k; i++){
		
		int cur = order[i];
		bool has_empty = false;
		
		for (int j=0; j<n; j++) {
			if (used[j] == -1 || used[j] == cur){ //비어있는 곳 or 이미 있음
				used[j] = cur;
				has_empty = true;
				break;
			}
		}
		
		if (!has_empty) {
			int victim_idx = 0;
			int victim_dist = get_dist(i, used[victim_idx]);
			
			for (int j=1; j<n; j++){
				int tmp_dist = get_dist(i, used[j]);
				
				if (tmp_dist > victim_dist){
					victim_dist = tmp_dist;
					victim_idx = j;
				}
			}
			
			used[victim_idx] = cur;
			ans++;
		}
	}
	
	cout<<ans<<'\n';

	return 0;
}