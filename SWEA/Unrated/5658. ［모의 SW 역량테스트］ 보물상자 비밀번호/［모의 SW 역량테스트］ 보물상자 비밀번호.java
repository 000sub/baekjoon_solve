import java.io.*;
import java.util.*;

public class Solution {

    static int T, N, K;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        T = Integer.parseInt(br.readLine());
        for (int tc = 1; tc <= T; tc++) {
            String[] input = br.readLine().split(" ");
            N = Integer.parseInt(input[0]);
            K = Integer.parseInt(input[1]);
            String s = br.readLine();
            
            s = s + s.substring(0, N/4 - 1);
            TreeSet<Integer> nums = new TreeSet<>();

            for (int i = 0; i < N; i++) {
                nums.add(Integer.parseInt(s.substring(i, i + N/4), 16));
            }
            
            Object[] array = nums.toArray();
            bw.write("#" + tc + " " + array[array.length - K] + "\n");
        }

        bw.flush();
        bw.close();
        br.close();
    }

}

