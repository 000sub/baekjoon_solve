import java.io.*;

public class Solution {
    static int M, A;
    static int[] aMove, bMove;
    static int[][] bc;
    static boolean[][][] canCharge;
    static int[] dx = {0, -1, 0, 1, 0};
    static int[] dy = {0, 0, 1, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int T = Integer.parseInt(br.readLine());
        for (int tc = 1; tc <= T; tc++) {
            String[] input = br.readLine().split(" ");
            M = Integer.parseInt(input[0]);
            A = Integer.parseInt(input[1]);
            aMove = new int[M];
            bMove = new int[M];
            canCharge = new boolean[11][11][A];
            bc = new int[A][4];
            input = br.readLine().split(" ");
            for (int i = 0; i < M; i++) aMove[i] = Integer.parseInt(input[i]);
            input = br.readLine().split(" ");
            for (int i = 0; i < M; i++) bMove[i] = Integer.parseInt(input[i]);
            for (int i = 0; i < A; i++) {
                input = br.readLine().split(" ");
                for (int j = 0; j < 4; j++) bc[i][j] = Integer.parseInt(input[j]);
            }

            for (int i = 0; i < A; i++) {
                int x = bc[i][1] - 1;
                int y = bc[i][0] - 1;
                int depth = bc[i][2];

                canCharge[x][y][i] = true;

                for (int j = -1 * depth; j <= depth; j++) {
                    for (int k = -1 * depth; k <= depth; k++) {
                        int nx = x + j;
                        int ny = y + k;
                        int dist = Math.abs(x - nx) + Math.abs(y - ny);

                        if (nx < 0 || ny < 0 || nx >= 10 || ny >= 10 || dist > depth) continue;
                        canCharge[nx][ny][i] = true;
                    }
                }
            }

            int aX = 0, aY = 0, bX = 9, bY = 9;
            int ans = 0;
            for (int i = 0; i <= M; i++) {
                int charge = 0;


                for (int j = 0; j < A; j++) {
                    for (int k = 0; k < A; k++) {
                        if (canCharge[aX][aY][j] && canCharge[bX][bY][k]) {
                            charge = j == k ? Math.max(charge, bc[j][3]) : Math.max(charge, bc[j][3] + bc[k][3]);
                        } else if (canCharge[aX][aY][j]) {
                            charge = Math.max(charge, bc[j][3]);
                        } else if (canCharge[bX][bY][j]) {
                            charge = Math.max(charge, bc[j][3]);
                        }
                    }
                }

                ans += charge;
                if (i == M) break;

                aX += dx[aMove[i]];
                aY += dy[aMove[i]];
                bX += dx[bMove[i]];
                bY += dy[bMove[i]];
            }
            bw.write("#" + tc + " " + ans + "\n");
        }
        bw.flush();
        bw.close();
        br.close();
    }
}