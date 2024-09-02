import java.io.*;
import java.util.*;

public class Main {

    static int[][] W, dp;
    static int N, ans = Integer.MAX_VALUE;
    static int INF = (int) 1e9;

    private static int dfs(int visited, int cur) {
        if (dp[cur][visited] != -1) return dp[cur][visited];

        if (visited == (1<<N) - 1) {
            if (W[cur][0] != 0) return W[cur][0];
            return INF;
        }

        dp[cur][visited] = INF;
        for (int i = 1; i < N; i++) {
            if ((visited & (1<<i)) != 0 || W[cur][i] == 0) continue;
            dp[cur][visited] = Math.min(dp[cur][visited], dfs(visited | (1 << i), i) + W[cur][i]);
        }

        return dp[cur][visited];
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        N = Integer.parseInt(br.readLine());
        W = new int[N][N];
        dp = new int[N][1<<N];
        for (int i = 0; i < N; i++) {
            String[] input = br.readLine().split(" ");
            for (int j = 0; j < N; j++) {
                W[i][j] = Integer.parseInt(input[j]);
            }

            Arrays.fill(dp[i], -1);
        }

        ans = dfs(1, 0);

        bw.write("" + ans);
        bw.flush();
        bw.close();
    }

}

