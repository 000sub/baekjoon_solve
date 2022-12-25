#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;



int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n, k;
	vector<int> v;
	
	cin>>n;
	
	for (int i=1; i<100; i++){
		int tmp = i*(i+1) / 2 ;
		if (tmp > 1000) break;
		v.emplace_back(tmp);
	}
	
	for (int i=0;i<n;i++){
		cin>>k;
		
		int flag = 0;
		for (int x=0; x<v.size(); x++){
			for (int y=0; y<v.size(); y++){
				for (int z=0; z<v.size(); z++){
					if (v[x] + v[y] + v[z] == k){
						flag = 1;
						break;
					}
				}
			}
		}
		
		cout<<flag<<'\n';
		
	}
	
	return 0;
}