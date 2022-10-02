#include <iostream>
#include <algorithm>
#include <string>
#define MAXNUM 200000
using namespace std;

int arr[26][MAXNUM+2] = {0};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	string s;
	
	int n, len;
	
	cin>>s>>n;
	len = s.size();
	for (int i=1;i<=len+1;i++){
		int tmp = -1; 
		
		if (i<=len) tmp = (int)s[i-1] - 97;
		
		for (int j=0;j<26;j++){
			if (j==tmp){
				arr[j][i] = arr[j][i-1] + 1;
			}
			else {
				arr[j][i] = arr[j][i-1];
			}
		}
	}
	
	for (int i=0;i<n;i++){
		char c;
		int s,e;
		
		cin>>c>>s>>e;
		int tmp = (int)c - 97;
		cout<< arr[tmp][e+1] - arr[tmp][s]<<'\n';
	}
	
	
	
	return 0;
}
