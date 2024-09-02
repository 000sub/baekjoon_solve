import java.util.*;
import java.io.*;

public class Main {
	static boolean[][] visited;
	static int N,M,K;
	static int[] dx = {-1,0,1,0};
	static int[] dy = {0,1,0,-1};
	
	static class Pos {
		int x,y;
		
		Pos(int x, int y) {
			this.x=x;
			this.y=y;
		}
	}
	
	private static int BFS(int x, int y) {
		Queue<Pos> q = new ArrayDeque<>();
		visited[x][y] = true;
		q.offer(new Pos(x, y));
		int cnt = 0;
		while (!q.isEmpty()) {
			Pos cur = q.poll();
			cnt++;
			
			for (int d=0; d<4; d++) {
				int nx = cur.x + dx[d];
				int ny = cur.y + dy[d];
				
				if (nx<0||ny<0||nx>=M||ny>=N||visited[nx][ny]) continue;
				visited[nx][ny] = true;
				q.offer(new Pos(nx, ny));
			}
		}
		
		
		return cnt;
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		String[] input = br.readLine().split(" ");
		M = Integer.parseInt(input[0]);
		N = Integer.parseInt(input[1]);
		K = Integer.parseInt(input[2]);
		
		visited = new boolean[M][N];
		
		for (int i=0;i<K;i++) {
			input = br.readLine().split(" ");
			int sx = Integer.parseInt(input[1]);
			int sy = Integer.parseInt(input[0]);
			int ex = Integer.parseInt(input[3]);
			int ey = Integer.parseInt(input[2]);
			
			for (int j=sx; j<=ex-1; j++) for (int k=sy; k<=ey-1; k++) visited[j][k] = true;
		}
		
		int cnt = 0;
		List<Integer> li = new ArrayList<>();
		for (int i=0; i<M; i++) {
			for (int j=0; j<N; j++) {
				if (!visited[i][j]) {
					cnt++;
					li.add(BFS(i,j));
				}
			}
		}
		
		bw.write(cnt + "\n");
		li.sort(Integer::compare);
		for (Integer i : li) bw.write(i + " ");
		bw.write("\n");
		
		bw.flush();
		bw.close();
		br.close();
	}
}
