#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	bool arr[10001];
	
	fill(arr, arr+10001, true);
	
	
	for (int i=1; i<=10000; i++){
		int tmp_idx = i;
		int tmp = i;
		while (tmp_idx){
			tmp += tmp_idx%10;
			tmp_idx/=10;
		}
		
		if (tmp <= 10000) arr[tmp] = false;
	}
	
	for (int i=1; i<=10000; i++){
		if (arr[i] == true) {
			cout<<i<<'\n';
		}
	}
	
	return 0;
}