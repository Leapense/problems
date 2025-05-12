import java.io.*;
import java.util.*;

public class Main {
    private static final long SCALE = 1000L;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder out = new StringBuilder();

        int K = Integer.parseInt(br.readLine().trim());
        for (int tc = 0; tc < K; tc++) {
            int N = Integer.parseInt(br.readLine().trim());
            long[] r = new long[N];

            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int i = 0; i < N; i++) {
                double x = Double.parseDouble(st.nextToken());
                r[i] = Math.round(x * SCALE);
            }

            out.append(solve(r) ? "YES" : "NO").append("\n");
        }

        System.out.print(out.toString());
    }

    private static boolean solve(long[] r) {
        int n = r.length;
        int limit = 1 << n;

        for (int mask = 0; mask < limit; mask++) {
            if (Integer.bitCount(mask) < 2)
                continue;

            long sum = 0, mx = 0;
            for (int i = 0; i < n; i++) {
                if ((mask & (1 << i)) != 0) {
                    sum += r[i];
                    if (r[i] > mx)
                        mx = r[i];
                }
            }

            if (mx <= sum - mx)
                return true;
        }

        return false;
    }
}