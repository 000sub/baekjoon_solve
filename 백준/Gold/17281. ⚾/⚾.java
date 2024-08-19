import java.util.*;
import java.io.*;

public class Main {
    static int N, ans;
    static int[] tgt;
    static int[][] arr;

    private static boolean np() {
        int i = 8;
        int j = i;
        int k = i;

        while (i > 0 && tgt[i - 1] >= tgt[i]) i--;

        if (i == 0) return false;

        while (tgt[i - 1] >= tgt[j]) j--;
        swap(tgt, i - 1, j);

        while (i < k) swap(tgt, i++, k--);

        return true;

    }

    private static void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        N = Integer.parseInt(br.readLine());

        arr = new int[N][9];
        tgt = new int[9];
        for (int i=0; i<9; i++) tgt[i] = i;
        ans = 0;


        for (int i=0; i<N; i++) {
            String[] input = br.readLine().split(" ");
            for (int j=0; j<9; j++) {
                arr[i][j] = Integer.parseInt(input[j]);
            }
        }

        do {
            while (tgt[3] != 0 && np());

            if (tgt[3] != 0) {
                bw.write(ans + "");
                bw.flush();
                bw.close();
                br.close();
                System.exit(0);
            }

            int score = 0;
            int stage = 0;
            int outCnt = 0;
            int curIdx = 0;
            int[] state = new int[3];
            Arrays.fill(state, -1);
            while (stage < N) {
                boolean flag = false;
                for (int i=0; i<3; i++) {
                    if (state[i] == tgt[curIdx]) {
                        curIdx = (curIdx + 1) % 9;
                        flag = true;
                    }
                }
                if (flag) continue;

                switch (arr[stage][tgt[curIdx]]) {
                    case 0:
                        outCnt++;
                        break;
                    case 1:
                        if (state[2] != -1) {
                            score++;
                            state[2] = -1;
                        }
                        if (state[1] != -1) {
                            state[2] = state[1];
                            state[1] = -1;
                        }
                        if (state[0] != -1) {
                            state[1] = state[0];
                            state[0] = -1;
                        }
                        state[0] = tgt[curIdx];
                        break;
                    case 2:
                        if (state[2] != -1) {
                            score++;
                            state[2] = -1;
                        }
                        if (state[1] != -1) {
                            score++;
                            state[1] = -1;
                        }
                        if (state[0] != -1) {
                            state[2] = state[0];
                            state[0] = -1;
                        }
                        state[1] = tgt[curIdx];
                        break;
                    case 3:
                        if (state[2] != -1) {
                            score++;
                            state[2] = -1;
                        }
                        if (state[1] != -1) {
                            score++;
                            state[1] = -1;
                        }
                        if (state[0] != -1) {
                            score++;
                            state[0] = -1;
                        }
                        state[2] = tgt[curIdx];
                        break;
                    case 4:
                        if (state[2] != -1) {
                            score++;
                            state[2] = -1;
                        }
                        if (state[1] != -1) {
                            score++;
                            state[1] = -1;
                        }
                        if (state[0] != -1) {
                            score++;
                            state[0] = -1;
                        }
                        score++;
                        break;
                }

                curIdx = (curIdx + 1) % 9;

                if (outCnt == 3) {
                    stage++;
                    outCnt = 0;
                    Arrays.fill(state, -1);
                }
            }

            ans = Math.max(ans, score);
        } while (np());

        bw.write(ans + "");
        bw.flush();
        bw.close();
        br.close();
    }
}