import java.util.*;
import java.io.*;

public class Main {
    static int[][] arr;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int K = Integer.parseInt(br.readLine());
        String[] input = br.readLine().split(" ");
        int h = Integer.parseInt(br.readLine());
        int N = 1<<K;
        arr = new int[N][N];

        int x = 0, y = 0;

        int xSize = N, ySize = N;

        for (String s : input) {
            if (s.equals("L")) ySize/=2;
            else if (s.equals("R")) {
                ySize/=2;
                y += ySize;
            }
            else if (s.equals("U")) xSize/=2;
            else if (s.equals("D")) {
                xSize/=2;
                x += xSize;
            }
        }

        int sx = x, ex = x, sy = y, ey = y;

        arr[x][y] = h;

        for (int i=input.length - 1; i>=0; i--) {
            String s = input[i];

            if (s.equals("R")) {
                sy -= ySize;
                ySize *= 2;
                for (int j=0; j<xSize; j++) {
                    for (int k=0; k<ySize/2; k++) {
                        int op = arr[sx+j][sy+ySize-k-1];
                        if (op == 1 || op == 3) arr[sx+j][sy+k] = op-1;
                        else arr[sx+j][sy+k] = op+1;
                    }
                }
            }
            else if (s.equals("L")) {
                ey += ySize;
                ySize *= 2;
                for (int j=0; j<xSize; j++) {
                    for (int k=0; k<ySize/2; k++) {
                        int op = arr[sx+j][sy+k];
                        if (op == 1 || op == 3) arr[sx+j][ey-k] = op-1;
                        else arr[sx+j][ey-k] = op+1;
                    }
                }

            }
            else if (s.equals("D")) {
                sx -= xSize;
                xSize *= 2;
                for (int j=0; j<ySize; j++) {
                    for (int k=0; k<xSize/2; k++) {
                        int op = arr[sx+xSize-k-1][sy+j];
                        if (op == 0 || op == 2) arr[sx+k][sy+j] = 2-op;
                        else if (op == 1) arr[sx+k][sy+j] = op+2;
                        else arr[sx+k][sy+j] = op-2;
                    }
                }
            }
            else if (s.equals("U")) {
                ex += xSize;
                xSize *= 2;
                for (int j=0; j<ySize; j++) {
                    for (int k=0; k<xSize/2; k++) {
                        int op = arr[sx+k][sy+j];
                        if (op == 0 || op == 2) arr[ex-k][sy+j] = 2-op;
                        else if (op == 1) arr[ex-k][sy+j] = op+2;
                        else arr[ex-k][sy+j] = op-2;
                    }
                }
            }
        }

        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                bw.write(arr[i][j] + " ");
            }
            bw.write("\n");
        }

        bw.flush();
        bw.close();
        br.close();
    }
}
