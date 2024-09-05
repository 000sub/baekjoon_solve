import java.io.*;
import java.util.*;

public class Main {

    static int T, N, M, ans, cnt;
    static List<Integer>[] graph, revGraph;
    static boolean[] visited;

    private static void dfs(int x) {
        visited[x] = true;

        for (int next : revGraph[x]) {
            if (!visited[next]) {
                dfs(next);
                cnt++;
            }
        }
    }

    private static void dfs2(int x) {
        visited[x] = true;

        for (int next : graph[x]) {
            if (!visited[next]) {
                dfs2(next);
                cnt++;
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] input = br.readLine().split(" ");
        N = Integer.parseInt(input[0]);
        M = Integer.parseInt(input[1]);
        ans = 0;
        graph = new ArrayList[N+1];
        revGraph = new ArrayList[N+1];

        for (int i = 0; i < N + 1; i++) {
            graph[i] = new ArrayList<>();
            revGraph[i] = new ArrayList<>();
        }

        for (int i = 0, a, b; i < M; i++) {
            input = br.readLine().split(" ");
            a = Integer.parseInt(input[0]);
            b = Integer.parseInt(input[1]);

            graph[a].add(b);
            revGraph[b].add(a);
        }

        for (int i = 1; i <= N; i++) {
            cnt = 0;
            visited = new boolean[N + 1];
            dfs(i);
            dfs2(i);
            if (cnt == N-1) ans++;
        }

        bw.write(ans + "");

    bw.flush();
    bw.close();
    br.close();
    }
}