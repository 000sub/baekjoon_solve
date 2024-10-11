import java.io.*;
import java.util.*;

public class Solution {
	static int T, N, W, H, ans;
	static int[][] arr;
	static int[] dx = {0,-1,0,1};
	static int[] dy = {1,0,-1,0};
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		T = Integer.parseInt(br.readLine());
		
		for (int tc=1; tc<=T; tc++) {
			String[] input = br.readLine().split(" ");
			N = Integer.parseInt(input[0]);
			W = Integer.parseInt(input[1]);
			H = Integer.parseInt(input[2]);
			ans = Integer.MAX_VALUE;
			
			arr = new int[H][W];
			
			for (int i=0; i<H; i++) {
				input = br.readLine().split(" ");
				for (int j=0; j<W; j++) {
					arr[i][j] = Integer.parseInt(input[j]);
				}
			}
			
			play(arr, 0);
			
			bw.write("#" + tc + " " + ans + "\n");
		}
		
		
		
		bw.flush();
		bw.close();
		br.close();
	}
	
	private static void rearrange(int[][] map) {
		for (int i=0; i<W; i++) {
			for (int j=H-1; j>=1; j--) {
				if (map[j][i] > 0) continue;
				int next = j-1;
				while (next >= 0 && map[next][i] == 0) next--;
				if (next < 0) break;
				map[j][i] = map[next][i];
				map[next][i] = 0;
			}
		}
	}
	
	private static int[][] clearMap(int x, int y, int[][] map) {
		int[][] temp = new int[H][W];
		for (int i=0; i<H; i++) {
			System.arraycopy(map[i], 0, temp[i], 0, W);
		}
		
		Queue<int[]> q = new ArrayDeque<int[]>();
		q.offer(new int[] {x, y, temp[x][y]});
		temp[x][y] = 0;
		
		while (!q.isEmpty()) {
			int[] cur = q.poll();
			
			for (int i=1; i<cur[2]; i++) {
				for (int d=0; d<4; d++) {
					int nx = cur[0] + dx[d] * i;
					int ny = cur[1] + dy[d] * i;
					if (nx<0||ny<0||nx>=H||ny>=W||temp[nx][ny]==0) continue;
					q.offer(new int[]{nx,ny,temp[nx][ny]});
					temp[nx][ny] = 0;
				}
			}
		}
		
		return temp;
	}
	
	private static int check(int[][] map) {
		int cnt = 0;
		for (int i=0; i<H; i++) {
			for (int j=0; j<W; j++) {
				if (map[i][j] > 0) cnt++;
			}
		}
		return cnt;
	}
	
	private static void play(int[][] map, int cnt) {
		if (check(map) == 0) {
			ans = 0;
			return;
		}
		if (cnt == N) {
			ans = Math.min(ans, check(map));
			return;
		}
		
		for (int i=0; i<W; i++) {
			for (int j=0; j<H; j++) {
				if (map[j][i] > 0) {
					int[][] temp = clearMap(j, i, map);
					rearrange(temp);
					play(temp, cnt+1);
					break;
				}
			}
		}
	}
}