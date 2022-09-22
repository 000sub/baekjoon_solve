#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main(){
	int n, k, l, t=0;
	char dir = 'R';
	int board[101][101] = {0};
	queue<pair<int,int>> q;
	board[1][1] = 1;
	
	cin>>n>>k;
	
	for (int i=0;i<k;i++){
		int x,y;
		cin>>y>>x;
		board[y][x] = 2; //apple: 2
	}
	
	cin >> l;
	
	q.push(make_pair(1,1));
	
	for (int i=0;i<=l; i++){
		int prev_loct, loc_t;
		char c;
		
		if (i==l){
			loc_t = 50000;
		}
		else{
			cin>>loc_t>>c;
			loc_t-=t;
		}
		
		
		
	
		
		switch(dir){
			//move first -> change dir
			case 'R':
				while (loc_t--){
					int ty = q.front().first;
					int tx = q.front().second;
					int hy = q.back().first;
					int hx = q.back().second;
					t++;
					
					//if craash
					if (hx+1>n || board[hy][hx+1] == 1){
						cout<<t;
						return 0;
					}
					
					//find apple
					else if (board[hy][hx+1] == 2){
						board[hy][hx+1] = 1;
						q.push(make_pair(hy, hx+1));
					}
					
					//find blank
					else {
						board[hy][hx+1] = 1;
						board[ty][tx] = 0;
						q.push(make_pair(hy, hx+1));
						q.pop();
					}
				}
				
				
				if (c=='D'){
					dir='D';
				}
				else {
					dir='U';
				}
				
				break;
			case 'L':
				while (loc_t--){
					int ty = q.front().first;
					int tx = q.front().second;
					int hy = q.back().first;
					int hx = q.back().second;
					t++;
					
					//if craash
					if (hx-1<1 || board[hy][hx-1] == 1){
						cout<<t;
						return 0;
					}
					
					//find apple
					else if (board[hy][hx-1] == 2){
						board[hy][hx-1] = 1;
						q.push(make_pair(hy, hx-1));
					}
					
					//find blank
					else {
						board[hy][hx-1] = 1;
						board[ty][tx] = 0;
						q.push(make_pair(hy,hx-1));
						q.pop();
					}
				}
				
				if (c=='D'){
					dir='U';
				}
				else {
					dir='D';
				}
				
				break;
			case 'U':
				while (loc_t--){
					int ty = q.front().first;
					int tx = q.front().second;
					int hy = q.back().first;
					int hx = q.back().second;
					t++;
					
					//if craash
					if (hy-1<1 || board[hy-1][hx] == 1){
						cout<<t;
						return 0;
					}
					
					//find apple
					else if (board[hy-1][hx] == 2){
						board[hy-1][hx] = 1;
						q.push(make_pair(hy-1, hx));
					}
					
					//find blank
					else {
						board[hy-1][hx] = 1;
						board[ty][tx] = 0;
						q.push(make_pair(hy-1, hx));
						q.pop();
					}
				}
				
				if (c=='D'){
					dir='R';
				}
				else {
					dir='L';
				}
				
				break;
			case 'D':
				while (loc_t--){
					int ty = q.front().first;
					int tx = q.front().second;
					int hy = q.back().first;
					int hx = q.back().second;
					t++;
					
					//if craash
					if (hy+1>n || board[hy+1][hx] == 1){
						cout<<t;
						return 0;
					}
					
					//find apple
					else if (board[hy+1][hx] == 2){
						board[hy+1][hx] = 1;
						q.push(make_pair(hy+1, hx));
					}
					
					//find blank
					else {
						board[hy+1][hx] = 1;
						board[ty][tx] = 0;
						q.push(make_pair(hy+1, hx));
						q.pop();
					}
				}
				
				if (c=='D'){
					dir='L';
				}
				else {
					dir='R';
				}
				break;
		}
	}
	
	cout<<t;
	
	return 0;
}