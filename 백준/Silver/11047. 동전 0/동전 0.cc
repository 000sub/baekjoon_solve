#include <iostream>
#include <vector>
using namespace std;


int main(){
	int n,k,a,cnt=0;
	vector<int> v;
	
	cin>>n>>k;
	
	for (int i=0;i<n;i++){
		cin>>a;
		v.push_back(a);
	}
	
	while (k>0){
		a = v.back();
		v.pop_back();
		while (k>=a){
			k-=a;
			cnt++;
		}
	}
	
	cout<<cnt;
}