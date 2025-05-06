import java.io.*;
import java.util.*;

public class Main {
    private static final long NEG = Long.MIN_VALUE / 4;

    public static void main(String[] args) throws Exception {
        FastScanner fs = new FastScanner(System.in);

        int N = fs.nextInt();
        int M = fs.nextInt();
        int V = N + 1; // 0 + rides

        long[][] w = new long[V][V];
        for (long[] row : w)
            Arrays.fill(row, -1L);

        for (int i = 0; i < M; ++i) {
            int u = fs.nextInt();
            int v = fs.nextInt();
            long d = fs.nextLong();

            if (u == v)
                continue; // 모든 self-loop 제거
            if (d > w[u][v])
                w[u][v] = d; // 가장 긴 간선 보관
        }

        int FULL = (1 << N) - 1;
        long[][] dp = new long[1 << N][N + 1];
        for (long[] row : dp)
            Arrays.fill(row, NEG);

        /* 출발: 0 -> i */
        for (int i = 1; i <= N; ++i)
            if (w[0][i] >= 0)
                dp[1 << (i - 1)][i] = w[0][i];

        for (int mask = 0; mask <= FULL; ++mask) {
            for (int v = 1; v <= N; ++v) {
                long cur = dp[mask][v];
                if (cur == NEG)
                    continue;
                for (int nxt = 1; nxt <= N; ++nxt) {
                    if ((mask & (1 << (nxt - 1))) != 0)
                        continue;
                    long edge = w[v][nxt];
                    if (edge < 0)
                        continue;
                    int nmask = mask | (1 << (nxt - 1));
                    dp[nmask][nxt] = Math.max(dp[nmask][nxt], cur + edge);
                }
            }
        }

        long ans = -1;
        for (int v = 1; v <= N; ++v) {
            long back = w[v][0];
            if (back < 0)
                continue;
            long val = dp[FULL][v];
            if (val == NEG)
                continue;
            ans = Math.max(ans, val + back);
        }
        System.out.println(ans);
    }

    /* ----------------- 빠른 입력 ----------------- */
    private static class FastScanner {
        private final byte[] buf = new byte[1 << 16];
        private int ptr = 0, len = 0;
        private final InputStream in;

        FastScanner(InputStream in) {
            this.in = in;
        }

        private int readByte() throws IOException {
            if (ptr >= len) {
                len = in.read(buf);
                ptr = 0;
                if (len <= 0)
                    return -1;
            }
            return buf[ptr++];
        }

        long nextLong() throws IOException {
            int c;
            long sign = 1, val = 0;
            while ((c = readByte()) <= ' ')
                if (c == -1)
                    throw new EOFException();
            if (c == '-') {
                sign = -1;
                c = readByte();
            }
            while (c > ' ') {
                val = val * 10 + (c - '0');
                c = readByte();
            }
            return val * sign;
        }

        int nextInt() throws IOException {
            return (int) nextLong();
        }
    }
}