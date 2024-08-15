import java.io.*;

public class Main {

    static Pos[] cctvs = new Pos[8];
    static int cctvsIdx = 0;
    static int ans = Integer.MAX_VALUE;
    static int N, M;
    static int[][] board, arr;
    static int[] dx = {0, 1, 0, -1};
    static int[] dy = {-1, 0, 1, 0};

    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    static class Pos {
        int x;
        int y;

        public Pos(int i, int j) {
            x = i;
            y = j;
        }
    }

    private static void check() throws IOException {
        int cnt = 0;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (board[i][j] == 0 && arr[i][j] == 0) cnt++;
            }
        }

        ans = Math.min(ans, cnt);
        if (ans == 0) {
            bw.write(0 + "\n");
            bw.flush();
            bw.close();
            br.close();
            System.exit(0);
        }
    }

    private static void monitor(int x, int y, int d, boolean isPlus) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        while (nx >= 0 && nx < N && ny >= 0 && ny < M && board[nx][ny] != 6) {
            arr[nx][ny] = isPlus ? arr[nx][ny] + 1 : arr[nx][ny] - 1;
            nx += dx[d];
            ny += dy[d];
        }
    }

    private static void BT(int idx) throws IOException {
        if (idx == cctvsIdx) {
            check();
            return;
        }

        int x = cctvs[idx].x;
        int y = cctvs[idx].y;
        int type = board[x][y];

        switch (type) {
            case 1:
                for (int d = 0; d < 4; d++) {
                    monitor(x, y, d, true);
                    BT(idx + 1);
                    monitor(x, y, d, false);
                }
                break;
            case 2:
                for (int d = 0; d < 2; d++) {
                    monitor(x, y, d, true);
                    monitor(x, y, d + 2, true);
                    BT(idx + 1);
                    monitor(x, y, d, false);
                    monitor(x, y, d + 2, false);
                }
                break;
            case 3:
                for (int d = 0; d < 4; d++) {
                    monitor(x, y, d, true);
                    monitor(x, y, (d + 1) % 4, true);
                    BT(idx + 1);
                    monitor(x, y, d, false);
                    monitor(x, y, (d + 1) % 4, false);
                }
                break;
            case 4:
                for (int d = 0; d < 4; d++) {
                    for (int dd = 0; dd < 4; dd++) {
                        if (dd == d) continue;
                        monitor(x, y, dd, true);
                    }
                    BT(idx + 1);
                    for (int dd = 0; dd < 4; dd++) {
                        if (dd == d) continue;
                        monitor(x, y, dd, false);
                    }
                }
                break;
            case 5:
                for (int d = 0; d < 4; d++) {
                    monitor(x, y, d, true);
                }
                BT(idx + 1);
                for (int d = 0; d < 4; d++) {
                    monitor(x, y, d, false);
                }
                break;
        }


    }

    public static void main(String[] args) throws IOException {

        String[] input = br.readLine().split(" ");
        N = Integer.parseInt(input[0]);
        M = Integer.parseInt(input[1]);
        board = new int[N][M];
        arr = new int[N][M];

        for (int i = 0; i < N; i++) {
            input = br.readLine().split(" ");
            for (int j = 0; j < M; j++) {
                board[i][j] = Integer.parseInt(input[j]);
                if (board[i][j] >= 1 && board[i][j] <= 5) {
                    cctvs[cctvsIdx++] = new Pos(i, j);
                }
            }
        }

        BT(0);


        bw.write(ans + "\n");

        bw.flush();
        bw.close();
        br.close();
    }
}