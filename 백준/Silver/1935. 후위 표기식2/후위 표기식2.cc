#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <map>
#include <vector>

using namespace std;

int main(){
   stack<long double> s;
   int n;
   string str;
   map <char, int> m;
   cin >> n >> str;
   
   for (int i=0;i<n;i++){
		int tmp;
		cin >> tmp;
		
		m.insert({(char)i+65, tmp});		
   }
   
   for (int i=0;i<str.size();i++){
   		if (str[i] >= 'A' && str[i] <= 'Z'){
			s.push((long double)m[str[i]]);   
		}
		else{
			long double t1, t2;
			t1 = (long double)s.top();
			s.pop();
			t2 = (long double)s.top();
			s.pop();
			
			if (str[i] == '+'){
				s.push((long double)t1+t2);
			}
			else if (str[i] == '-'){
				s.push((long double)t2-t1);
			}
			else if (str[i] == '*'){
				s.push((long double)t1*t2);
			}
			else if (str[i] == '/'){
				s.push((long double)t2/t1);
			}
			
			
		}
   }
   
   printf("%.2Lf", s.top());
   
   

   
   return 0;
}

   
   