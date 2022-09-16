#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <map>
#include <vector>

using namespace std;

int main(){
   string str;
   
   while (1) {
		getline(cin, str);
		if (!str.compare("#")){
			break;
		}
		
		stack<string> s;
		
		for (int i=0; i<str.size();i++){
			
			if (str[i] == '<') {
				int sidx = i+1, eidx;
				
				while (str[i] != '>'){
					i++;
				}
				eidx = i-1;
				
				// <br/>
				if (str[eidx] =='/') continue;
				
				// <a href>
				for (int j=sidx;j<=eidx;j++){
					if (str[j] ==' '){
						eidx = j-1;
					}
				}
				
				string tag = str.substr(sidx, eidx-sidx+1);
				
				//close tag
				if (tag.size()>1 && tag[0] == '/'){
					if (s.empty()){
						s.push("illegal");
					}
					if (!s.empty() && s.top()== tag.substr(1, tag.length())){
						s.pop();
					}
				}
				
				//open tag
				else {
					s.push(tag);
				}
			}
		}
		
		if (s.empty()){
			cout<<"legal"<<'\n';
		} else {
			cout<<"illegal"<<'\n';
		}
			

   }

   
   return 0;
}