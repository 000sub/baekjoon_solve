import java.io.*;
import java.util.*;

public class Main {
    static int N, L, R, ans = -1;
    static int[] dy = {0, -1, 0, 1};
    static int[] dx = {1, 0, -1, 0};
    static boolean[][] visited;
    static int[][] board;
    static boolean moveOccurred = true;

    static class Pos {
        int x, y;

        public Pos(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    private static void BFS(int x, int y) {
        Queue<Pos> queue = new LinkedList<>();
        boolean[][] isAlly = new boolean[N][N];

        queue.add(new Pos(x, y));
        isAlly[x][y] = true;
        int cnt = 1;
        int sum = board[x][y];

        while (!queue.isEmpty()) {
            Pos cur = queue.poll();
            for (int d = 0; d < 4; d++) {
                int nx = cur.x + dx[d];
                int ny = cur.y + dy[d];

                if (nx < 0 || ny < 0 || nx > N - 1 || ny > N - 1 || visited[nx][ny] || isAlly[nx][ny]) continue;

                int gap = Math.abs(board[cur.x][cur.y] - board[nx][ny]);

                if (L <= gap && gap <= R) {
                    isAlly[nx][ny] = true;
                    queue.add(new Pos(nx, ny));
                    sum += board[nx][ny];
                    cnt++;
                }
            }
        }

        if (cnt == 1) return;

        int val = sum / cnt;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (isAlly[i][j]) {
                    board[i][j] = val;
                    visited[i][j] = true;
                }
            }
        }

        moveOccurred = true;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] input = br.readLine().split(" ");

        N = Integer.parseInt(input[0]);
        L = Integer.parseInt(input[1]);
        R = Integer.parseInt(input[2]);
        visited = new boolean[N][N];
        board = new int[N][N];

        for (int i = 0; i < N; i++) {
            input = br.readLine().split(" ");
            for (int j = 0; j < N; j++) {
                board[i][j] = Integer.parseInt(input[j]);
            }
        }

        while (moveOccurred) {
            moveOccurred = false;

            for (boolean[] row : visited) {
                Arrays.fill(row, false);
            }

            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (!visited[i][j]) BFS(i, j);
                }
            }
            ans++;
        }


        bw.write(ans + "\n");
        bw.flush();
        bw.close();
        br.close();
    }
}