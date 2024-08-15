import java.io.*;

public class Main {

    static int N, M, H, ans = Integer.MAX_VALUE;
    static boolean[][] arr;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    private static boolean check() {
        for (int i = 1; i <= N; i++) {
            int cur = i;
            for (int j = 1; j <= H; j++) {
                if (arr[j][cur]) cur++;
                else if (cur > 1 && arr[j][cur - 1]) cur--;
            }

            if (i != cur) return false;
        }

        return true;
    }

    private static void BT(int yIdx, int xIdx, int cnt) {
        if (cnt > 3 || cnt > ans) return;
        if (check()) {
            ans = cnt;
            return;
        }

        for (int i = yIdx; i <= H; i++) {
            for (int j = 1; j < N; j++) {
                if (i == yIdx && j < xIdx) continue;
                if (arr[i][j] || (j > 1 && arr[i][j - 1]) || arr[i][j + 1]) continue;

                arr[i][j] = true;
                BT(i, j, cnt + 1);
                arr[i][j] = false;
            }
        }
    }

    public static void main(String[] args) throws IOException {
        String[] input = br.readLine().split(" ");
        N = Integer.parseInt(input[0]);
        M = Integer.parseInt(input[1]);
        H = Integer.parseInt(input[2]);

        arr = new boolean[H + 1][N + 1];

        for (int i = 0; i < M; i++) {
            input = br.readLine().split(" ");
            arr[Integer.parseInt(input[0])][Integer.parseInt(input[1])] = true;
        }

        if (M == 0) {
            bw.write("0");
            bw.flush();
            bw.close();
            br.close();
            return;
        }

        BT(1, 1, 0);

        if (ans == Integer.MAX_VALUE) {
            bw.write("-1");
            bw.flush();
            bw.close();
            br.close();
            return;
        }

        bw.write(ans + "\n");
        bw.flush();
        bw.close();
        br.close();
    }
}