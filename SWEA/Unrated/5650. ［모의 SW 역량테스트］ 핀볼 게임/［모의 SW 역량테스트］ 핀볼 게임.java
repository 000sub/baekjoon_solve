import java.io.*;
import java.util.*;

public class Solution {
	
	static class Pos {
		int x, y;
		
		public Pos(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}
	
	static int T, N, ans;
	static int[][] arr;
	static int[] dx = {-1,0,1,0};
	static int[] dy = {0,-1,0,1};
	static List<Pos> starts;
	static List<Pos>[] wormholes;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		T = Integer.parseInt(br.readLine().trim());
		
		for (int tc=1; tc<=T; tc++) {
			N = Integer.parseInt(br.readLine().trim());
			arr = new int[N][N];
			starts = new ArrayList<>();
			ans = 0;
			wormholes = new List[11];
			for (int i=6; i<=10; i++) wormholes[i] = new ArrayList<Pos>();
			for (int i=0; i<N; i++) {
				String[] input = br.readLine().trim().split(" ");
				for (int j=0; j<N; j++) {
					arr[i][j] = Integer.parseInt(input[j]);
					if (arr[i][j] == 0) {
						starts.add(new Pos(i, j));
					}
					else if (arr[i][j]>=6 && arr[i][j]<=10) {
						wormholes[arr[i][j]].add(new Pos(i, j));
					}
				}
			}
			
			for (Pos start : starts) {
				for (int d=0; d<4; d++) {
					simulate(start, d);
				}
			}
			
			bw.write("#" + tc + " " + ans + "\n");
		}
		
		bw.flush();
		bw.close();
		br.close();
	}
	
	private static void simulate(Pos start, int d) {
		int score = 0;
		int x = start.x;
		int y = start.y;
		
		while (true) {
			int nx = 0, ny = 0;
			int num = arr[x][y];
			
			if (1<=num && num<=5) {
				score++;
				switch (num) {
					case 1: {
						if (d==0) d=2;
						else if (d==1) d=0;
						else if (d==2) d=3;
						else d=1;
						break;
					}
					case 2: {
						if (d==0) d=3;
						else if (d==1) d=2;
						else if (d==2) d=0;
						else d=1;
						break;
					}
					case 3: {
						if (d==0) d=1;
						else if (d==1) d=3;
						else if (d==2) d=0;
						else d=2;
						break;
					}
					case 4: {
						if (d==0) d=2;
						else if (d==1) d=3;
						else if (d==2) d=1;
						else d=0;
						break;
					}
					case 5: {
						d = (d%2==0) ? 2-d : 4-d;
						break;
					}
				}
			}
			
			nx = x + dx[d];
			ny = y + dy[d];
			
			if (nx<0||ny<0||nx>=N||ny>=N) {
				d = (d%2==0) ? 2-d : 4-d;
				score++;
				nx = x;
				ny = y;
			}
			
			if (arr[nx][ny] == -1 || (nx == start.x && ny == start.y)) break;
			
			if (arr[nx][ny] >= 6) {
				int wIdx = arr[nx][ny];
				for (int i=0; i<2; i++) {
					if (wormholes[wIdx].get(i).x == nx && wormholes[wIdx].get(i).y == ny) {
						nx = wormholes[wIdx].get(1-i).x;
						ny = wormholes[wIdx].get(1-i).y;
						break;
					}
				}
			}
			
			x = nx;
			y = ny;
			
		}
		ans = Math.max(ans,  score);
		
	}
}
