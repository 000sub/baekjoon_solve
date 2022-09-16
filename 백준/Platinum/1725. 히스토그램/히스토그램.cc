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
   stack<pair<int,int>> stack;
   int n, cur;
   long long ans=0;
   
   cin>>n;
   
   for (int i=1;i<=n;i++){
		cin>>cur;
		
    	while (!stack.empty() && cur<=stack.top().first){
            int tmp = stack.top().first;
            stack.pop();
            if (stack.empty()){
				ans = max(ans, (long long)(i-1)*tmp);
			} 
			else{
				ans = max(ans, (long long)(i-1-stack.top().second)*tmp);
			}
        }
        stack.push(make_pair(cur, i));
   }
   
   while (!stack.empty()){
        int tmp = stack.top().first;
        stack.pop();
    	if (stack.empty()){
			ans = max(ans, (long long)n*tmp);
		} 
		else{
			ans = max(ans, (long long)(n-stack.top().second)*tmp);
		}
   }
   
   cout<<ans;
   
   
   return 0;
}