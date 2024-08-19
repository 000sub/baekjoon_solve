import java.io.*;
import java.util.LinkedList;
import java.util.Queue;

public class Main {
    static int N, M, sx, sy, ans = Integer.MAX_VALUE;
    static int[] dy = {0, -1, 0, 1};
    static int[] dx = {1, 0, -1, 0};
    static boolean[][][] visited;
    static char[][] board;
    static boolean moveOccurred = true;

    static class QItem {
        int x, y, cnt, state;

        QItem(int x, int y, int cnt, int state) {
            this.x = x;
            this.y = y;
            this.cnt = cnt;
            this.state = state;
        }
    }

    private static void BFS() {
        Queue<QItem> q = new LinkedList<>();

        visited[sx][sy][0] = true;
        q.add(new QItem(sx, sy, 0, 0));

        while (!q.isEmpty()) {
            QItem qItem = q.poll();
            int x = qItem.x;
            int y = qItem.y;
            int cnt = qItem.cnt;
            int state = qItem.state;

            if (board[x][y] == '1') {
                ans = Math.min(ans, cnt);
                continue;
            }

            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx < 0 || ny < 0 || nx > N - 1 || ny > M - 1 || visited[nx][ny][state] || board[nx][ny] == '#')
                    continue;

                if ('A' <= board[nx][ny] && board[nx][ny] <= 'F') {
                    if (((1 << (board[nx][ny] - 'A')) & state) == 0) continue;
                }

                visited[nx][ny][state] = true;
                if ('a' <= board[nx][ny] && board[nx][ny] <= 'f') {
                    int newState = state | (1 << (board[nx][ny] - 'a'));
                    visited[nx][ny][newState] = true;
                    q.add(new QItem(nx, ny, cnt + 1, newState));
                } else {
                    q.add(new QItem(nx, ny, cnt + 1, state));
                }

            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] input = br.readLine().split(" ");

        N = Integer.parseInt(input[0]);
        M = Integer.parseInt(input[1]);
        visited = new boolean[N][M][1 << 6];
        board = new char[N][M];

        for (int i = 0; i < N; i++) {
            String row = br.readLine();
            for (int j = 0; j < M; j++) {
                board[i][j] = row.charAt(j);
                if (board[i][j] == '0') {
                    sx = i;
                    sy = j;
                }
            }
        }

        BFS();

        if (ans == Integer.MAX_VALUE) bw.write("-1");
        else bw.write(ans + "");
        bw.flush();
        bw.close();
        br.close();
    }
}