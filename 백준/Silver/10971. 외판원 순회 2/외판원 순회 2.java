import java.io.*;
import java.util.*;

public class Main {

    static int[][] W;
    static int N, ans = Integer.MAX_VALUE;

    private static void dfs(int visited, int val, int cur) {
        if (visited == (1<<N) - 1) {
            if (W[cur][0] != Integer.MAX_VALUE)
                ans = Math.min(ans, val + W[cur][0]);
            return;
        }

        for (int i = 1; i < N; i++) {
            if ((visited & (1<<i)) == 0) {
                if (W[cur][i] != Integer.MAX_VALUE) {
                    dfs(visited | (1 << i), val + W[cur][i], i);
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        N = Integer.parseInt(br.readLine());
        W = new int[N][N];
        for (int i = 0; i < N; i++) {
            String[] input = br.readLine().split(" ");
            for (int j = 0; j < N; j++) {
                W[i][j] = Integer.parseInt(input[j]);
                if (W[i][j] == 0) W[i][j] = Integer.MAX_VALUE;;
            }
        }

        dfs(1, 0, 0);

        bw.write("" + ans);
        bw.flush();
        bw.close();
    }

}

