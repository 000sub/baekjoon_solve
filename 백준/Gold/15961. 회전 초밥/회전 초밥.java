import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] input = br.readLine().split(" ");
        int N = Integer.parseInt(input[0]);
        int D = Integer.parseInt(input[1]);
        int K = Integer.parseInt(input[2]);
        int C = Integer.parseInt(input[3]);

        int ans = 0, locAns = 0;
        int[] cnt = new int[D+1];
        int[] arr = new int[N];

        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(br.readLine());
            if (i < K && cnt[arr[i]]++ == 0) {
                locAns++;
            }
            else if (i >= K) {
                if (--cnt[arr[i-K]] == 0) locAns--;
                if (cnt[arr[i]]++ == 0) locAns++;
            }
            if (locAns+1>ans && cnt[C] == 0) ans = locAns+1;
            if (locAns>ans) ans = locAns;
        }
        for (int i = K; i>0; i--) {
            if (--cnt[arr[N-i]] == 0) locAns--;
            if (cnt[arr[K-i]]++ == 0) locAns++;
            if (locAns+1>ans && cnt[C] == 0) ans = locAns+1;
            if (locAns>ans) ans = locAns;
        }
        bw.write(ans + "");
        bw.flush();
        bw.close();
        br.close();
    }
}