import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int S = Integer.parseInt(st.nextToken());
        int N = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        int[] E = new int[N];
        for (int i = 0; i < N; i++) {
            E[i] = Integer.parseInt(st.nextToken());
        }

        st = new StringTokenizer(br.readLine());
        int K = Integer.parseInt(st.nextToken());
        int L = Integer.parseInt(st.nextToken());

        long minCost = Long.MAX_VALUE;
        int frogIndex = -1;

        for (int i = 0; i < N; i++) {
            int pos = E[i];
            int D = Math.abs(pos - S);
            int dmax = Math.min(K, D);
            int X = Math.min(2 * dmax, D);

            long cost = 2L * K + (long) L * D - (1L + L) * X;

            if (cost < minCost) {
                minCost = cost;
                frogIndex = i + 1;
            }
        }

        bw.write(minCost + " " + frogIndex + "\n");
        bw.flush();
        bw.close();
        br.close();
    }
}