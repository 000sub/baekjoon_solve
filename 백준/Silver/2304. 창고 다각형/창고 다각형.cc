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
	
   int n, l, h, ans = 0;
   vector<pair<int,int>> v;
   stack<pair<int,int>> s, s2;
   
   cin>>n;
   
   for (int i=0;i<n;i++){
   		cin>>l>>h;
   		v.push_back(make_pair(l,h));
   }
   
   sort(v.begin(), v.end());
   
   
   s.push(v[0]); 
   for (int i=1; i<v.size(); i++){
   		if (s.top().second < v[i].second){
   			ans += s.top().second * (v[i].first - s.top().first);
   			s.push(v[i]);
		}
   }
   
   s2.push(v[n-1]);
   for (int i=n-2; i>=0; i--){
   		if (s2.top().second < v[i].second){
   			ans += s2.top().second * (s2.top().first - v[i].first);
   			s2.push(v[i]);
		}
   }
   
   ans += s.top().second * (s2.top().first - s.top().first + 1);
   
   cout<<ans;
   
   
   

   
   return 0;
}

   
   