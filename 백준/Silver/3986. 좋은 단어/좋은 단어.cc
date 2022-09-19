#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <map>
#include <vector>

using namespace std;

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n, cnt = 0;
	string str;
	cin >> n;
	
	for (int i=0;i<n;i++){
		stack<char> s;
		cin>>str;
		for (char c: str){
			if (s.empty()){
				s.push(c);
			}
			else if (s.top() == c){
				s.pop();
			}
			else {
				s.push(c);
			}
		}
		
		if (s.empty()){
			cnt++;
		}
	}
	cout<<cnt;
	
	return 0;
}