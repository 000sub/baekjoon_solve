import java.io.*;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] input = br.readLine().split(" ");
        int N = Integer.parseInt(input[0]);
        int L = Integer.parseInt(input[1]);
        int[][] arr = new int[N][N];

        for (int i = 0; i < N; i++) {
            input = br.readLine().split(" ");
            for (int j = 0; j < N; j++) {
                arr[i][j] = Integer.parseInt(input[j]);
            }
        }

        boolean[] visited = new boolean[N];
        int ans = 0;
        boolean flag;

        for (int i = 0; i < N; i++) {

            Arrays.fill(visited, false);

            for (int j = 0; j < N - 1; j++) {
                int cur = arr[i][j];
                int next = arr[i][j + 1];

                if (cur != next) {
                    if (Math.abs(cur - next) != 1) break;

                    if (cur > next) {
                        flag = true;
                        for (int k = 0; k < L; k++) {
                            if (j + 1 + k >= N || visited[j + 1 + k] || arr[i][j + 1 + k] != next) {
                                flag = false;
                                break;
                            }
                        }
                        if (!flag) break;
                        Arrays.fill(visited, j + 1, j + 1 + L, true);
                    } else {
                        flag = true;
                        for (int k = 0; k < L; k++) {
                            if (j - k < 0 || visited[j - k] || arr[i][j - k] != cur) {
                                flag = false;
                                break;
                            }
                        }
                        if (!flag) break;
                        Arrays.fill(visited, j - L + 1, j + 1, true);
                    }
                }

                if (j == N - 2) ans++;
            }

            Arrays.fill(visited, false);

            for (int j = 0; j < N - 1; j++) {
                int cur = arr[j][i];
                int next = arr[j + 1][i];

                if (cur != next) {
                    if (Math.abs(cur - next) != 1) break;

                    if (cur > next) {
                        flag = true;
                        for (int k = 0; k < L; k++) {
                            if (j + 1 + k >= N || visited[j + 1 + k] || arr[j + 1 + k][i] != next) {
                                flag = false;
                                break;
                            }
                        }
                        if (!flag) break;
                        Arrays.fill(visited, j + 1, j + 1 + L, true);
                    } else {
                        flag = true;
                        for (int k = 0; k < L; k++) {
                            if (j - k < 0 || visited[j - k] || arr[j - k][i] != cur) {
                                flag = false;
                                break;
                            }
                        }
                        if (!flag) break;
                        Arrays.fill(visited, j - L + 1, j + 1, true);
                    }
                }

                if (j == N - 2) ans++;

            }
        }

        bw.write(ans + "\n");
        bw.flush();
        bw.close();
        br.close();
    }
}