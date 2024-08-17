import java.io.*;
import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        String[] input = br.readLine().split(" ");
        int[] dy = {0, -1, 0, 1};
        int[] dx = {1, 0, -1, 0};
        boolean[][] arr = new boolean[101][101];
        int N;
        int x, y, d, g, ans = 0;
        List<Integer> dirs = new ArrayList<>();

        N = Integer.parseInt(input[0]);

        dirs.add(0);

        for (int i = 1; i <= 10; i++) {
            int size = dirs.size();
            for (int j = size - 1; j >= 0; j--) {
                dirs.add((dirs.get(j) + 1) % 4);
            }
        }

        for (int i = 0; i < N; i++) {
            input = br.readLine().split(" ");
            x = Integer.parseInt(input[0]);
            y = Integer.parseInt(input[1]);
            d = Integer.parseInt(input[2]);
            g = Integer.parseInt(input[3]);

            arr[y][x] = true;

            for (int j = 0; j < (1 << g); j++) {
                y += dy[(d + dirs.get(j)) % 4];
                x += dx[(d + dirs.get(j)) % 4];
                arr[y][x] = true;
            }
        }

        for (int i = 0; i < 100; i++)
            for (int j = 0; j < 100; j++)
                if (arr[i][j] && arr[i + 1][j] && arr[i][j + 1] && arr[i + 1][j + 1]) ans++;

        bw.write(ans + "\n");
        bw.flush();
        bw.close();
        br.close();
    }
}