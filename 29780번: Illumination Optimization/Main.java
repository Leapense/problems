import java.io.*;
import java.util.*;

public class Main {

    static class FastScanner {
        private final BufferedReader br;
        private StringTokenizer st;
        FastScanner(InputStream in) { br = new BufferedReader(new InputStreamReader(in)); }
        String next() throws IOException {
            while (st == null || !st.hasMoreTokens()) st = new StringTokenizer(br.readLine());
            return st.nextToken();
        }
        long nextLong() throws IOException { return Long.parseLong(next()); }
        int nextInt() throws IOException { return Integer.parseInt(next()); }
    }

    public static void main(String[] args) throws Exception {
        FastScanner fs = new FastScanner(System.in);
        StringBuilder out = new StringBuilder();
        int T = fs.nextInt();
        for (int tc = 1; tc <= T; tc++) {
            long M = fs.nextLong();
            long R = fs.nextLong();
            int N = fs.nextInt();

            long[] X = new long[N];
            for (int i = 0; i < N; i++) X[i] = fs.nextLong();

            String result = solve(M, R, X);
            out.append("Case #").append(tc).append(": ").append(result).append('\n');
        }
        System.out.print(out.toString());
    }

    private static String solve(long M, long R, long[] X) {
        int n = X.length;
        int idx = 0;
        long covered = 0;      // [0, covered] 까지 밝히는 중
        int used = 0;

        while (covered < M) {
            long bestEnd = covered;
            // 시작점이 covered 이하인 모든 구간 중 가장 멀리 가는 구간 찾기
            while (idx < n && X[idx] - R <= covered) {
                bestEnd = Math.max(bestEnd, X[idx] + R);
                idx++;
            }
            if (bestEnd == covered) return "IMPOSSIBLE"; // 확장 불가
            used++;
            covered = bestEnd;
        }
        return String.valueOf(used);
    }
}
