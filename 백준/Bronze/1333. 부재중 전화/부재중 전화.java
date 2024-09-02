import java.io.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String[] input = br.readLine().split(" ");
        int N = Integer.parseInt(input[0]);
        int L = Integer.parseInt(input[1]);
        int D = Integer.parseInt(input[2]);

        int len = N * L + (N-1) * 5;
        boolean[] song = new boolean[len];

        for (int i=0; i<len; i+=L+5) {
            for (int j=0; j<L; j++) if (i+j<len) song[i+j] = true;
        }

        for (int i=0; i<len; i+=D) {
            if (!song[i]) {
                bw.write("" + i);
                bw.flush();
                bw.close();
                br.close();
                return;
            }
        }
        int temp = D;
        while (temp < len) temp+=D;
        bw.write("" + temp);
        bw.flush();
        bw.close();
        br.close();
    }
}
