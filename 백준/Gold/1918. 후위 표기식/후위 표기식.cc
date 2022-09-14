#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <map>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	stack<char> stack;
	map<char, int> op;
	op.insert({'+',1});
	op.insert({'*',0});
	op.insert({'/',0});
	op.insert({'-',1});
	string s;
	
	cin>>s;
	for(int i=0;i<s.size();i++){
		char cur = s[i];
		
		if ('A'<=cur && cur<='Z'){
			cout<<cur;
		}
		
		else if (cur==')'){
			while (stack.top() != '('){
				cout<<stack.top();
				stack.pop();
			}
			stack.pop();
		}
		
		else if (cur=='('){
			stack.push(cur);
		}
		
		else {
			
			if (stack.empty()){
				stack.push(cur);
				continue;
			}
			
			if (stack.top() =='('){
				stack.push(cur);
				continue;
			}
			
			if (op[cur] < op[stack.top()]){
				stack.push(cur);
				continue;
			}
			
			else {
				while (!stack.empty()){
					if (stack.top()=='(' || op[cur] < op[stack.top()]){
						break;
					}
					
					cout<<stack.top();
					stack.pop();
				}
				
				stack.push(cur);
			}
		}
	}
	
	while (!stack.empty()){
		cout<<stack.top();
		stack.pop();
	}
	
	return 0;
}
