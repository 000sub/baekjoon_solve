#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int t;
	string s;
	
	cin>>t;
	
	for (int i=0;i<t;i++){
		list<char> li;
		list<char>::iterator cur = li.begin();
		cin>>s;
		
		int n = s.size();
		for (int j=0;j<n;j++){
			char c = s[j];
			
			if (c=='<'){
				if (cur!=li.begin()) cur--;
			}
			
			else if (c=='>'){
				if (cur!=li.end()) cur++;
			}
			
			else if (c=='-'){
				if (cur != li.begin()) {
					cur = li.erase(--cur);
				}
			}
			
			else {
				li.insert(cur, c);
			}
		}
		
		for (auto j: li){
			cout<<j;
		}
		
		cout<<'\n';
		
	}
	
	
	return 0;
}