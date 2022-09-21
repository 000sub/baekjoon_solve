#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	int n,k;
	cin>>n>>k;
	vector<char> v(n);
	for (int i=0;i<n;i++){
		v[i] = '?';
	}	
	
	int cur=0;
	for (int i=0; i<k;i++){
		int tmp;
		char c;
		cin>>tmp>>c;
		
		tmp%=n;
		if (cur-tmp >= 0){
			cur -= tmp;
		}
		else {
			cur = (cur-tmp)+n;
		}
		
		if (v[cur] != '?' && v[cur] != c){
			cout<<'!';
			return 0;
		}
		v[cur] = c;
	}
	
	for (int i=0;i<n;i++){
		for (int j=i+1;j<n;j++){
			if (v[i] == v[j] && v[i] != '?'){
				cout<<'!';
				return 0;
			}
		}
	}
	
	for (int i=0;i<n;i++){
		cout<<v[(i+cur)%n];
	}
	
	return 0;
}