import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        int[] masks = new int[M];
        int[] counts = new int[M];

        for (int i = 0; i < M; i++) {
            String line = br.readLine();
            String[] parts = line.split(" ");
            String maskStr = parts[0];
            masks[i] = 0;
            for (int j = 0; j < N; j++) {
                if (maskStr.charAt(j) == '1') {
                    masks[i] |= (1 << (N - 1 - j));
                }
            }

            counts[i] = Integer.parseInt(parts[1]);
        }

        int limit = 1 << N;
        int firstSolution = -1;
        boolean multiple = false;

        for (int bits = 0; bits < limit; bits++) {
            boolean ok = true;
            for (int i = 0; i < M; i++) {
                if (Integer.bitCount(bits & masks[i]) != counts[i]) {
                    ok = false;
                    break;
                }
            }
            if (!ok)
                continue;

            if (firstSolution == -1) {
                firstSolution = bits;
            } else {
                multiple = true;
                break;
            }
        }

        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        if (firstSolution < 0) {
            bw.write("IMPOSSIBLE\n");
        } else if (multiple) {
            bw.write("NOT UNIQUE\n");
        } else {
            StringBuilder sb = new StringBuilder();
            for (int j = N - 1; j >= 0; j--) {
                sb.append(((firstSolution >> j) & 1) == 1 ? '1' : '0');
            }

            bw.write(sb.toString());
            bw.write("\n");
        }
        bw.flush();
        br.close();
    }
}