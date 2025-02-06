import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static class Range {
        int low, high;

        Range(int low, int high) {
            this.low = low;
            this.high = high;
        }
    }

    static int N, M;
    static int[] K, Z;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        if (M == 0) {
            System.out.println(N);
            return;
        }

        K = new int[M + 1];
        Z = new int[M + 1];

        for (int i = 1; i <= M; i++) {
            st = new StringTokenizer(br.readLine());
            K[i] = Integer.parseInt(st.nextToken());
            Z[i] = Integer.parseInt(st.nextToken());
        }

        int lowL = Math.max(K[1] - 1, N - K[M] + 1);
        for (int i = 1; i < M; i++) {
            lowL = Math.max(lowL, K[i + 1] - K[i]);
        }

        int highL = N;
        int ansL = highL;
        while (lowL <= highL) {
            int mid = (lowL + highL) / 2;
            if (isFeasible(mid)) {
                ansL = mid;
                highL = mid - 1;
            } else {
                lowL = mid + 1;
            }
        }

        Range[] ranges = new Range[M + 1];

        ranges[0] = new Range(K[1] - 1, ansL);
        Range prev = ranges[0];
        boolean feasible = true;

        for (int i = 1; i <= M; i++) {
            int newLow = Math.max(prev.low, K[i]);
            int newHigh = Math.min(prev.high + Z[i], ansL + (K[i] - 1));

            if (newLow > newHigh) {
                feasible = false;
                break;
            }

            ranges[i] = new Range(newLow, newHigh);
            prev = ranges[i];
        }

        if (!feasible || N < ranges[M].low || N > ranges[M].high) {
            System.out.println("Error");
            return;
        }

        int[] X = new int[M + 1];
        X[M] = N;

        for (int i = M; i >= 1; i--) {
            int lowerBound = Math.max(ranges[i - 1].low, X[i] - Z[i]);
            int upperBound = Math.min(ranges[i - 1].high, X[i]);

            X[i - 1] = upperBound;
        }

        int a0 = X[0];
        int[] a = new int[M + 1];
        a[0] = a0;
        for (int i = 1; i <= M; i++) {
            a[i] = X[i] - X[i - 1];
        }

        StringBuilder sb = new StringBuilder();
        sb.append(a[0]).append("\n");

        for (int i = 1; i <= M; i++) {
            sb.append(a[i]).append("\n");
        }

        System.out.print(sb);
    }

    static boolean isFeasible(int L) {
        int lowVal = K[1] - 1, highVal = L;
        for (int i = 1; i <= M; i++) {
            int newLow = Math.max(lowVal, K[i]);
            int newHigh = Math.min(highVal + Z[i], L + (K[i] - 1));
            if (newLow > newHigh)
                return false;
            lowVal = newLow;
            highVal = newHigh;
        }

        return (N >= lowVal && N <= highVal);
    }
}