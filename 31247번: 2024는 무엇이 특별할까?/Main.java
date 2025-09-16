import java.io.*;

public class Main {
    static class FastScanner {
        private final InputStream in;
        private final byte[] buffer = new byte[1 << 16];
        private int ptr = 0, len = 0;
        FastScanner(InputStream is) { in = is; }
        private int read() throws IOException {
            if (ptr >= len) {
                len = in.read(buffer);
                ptr = 0;
                if (len <= 0) return -1;
            }
            return buffer[ptr++];
        }
        long nextLong() throws IOException {
            int c;
            do { c = read(); } while (c <= 32);
            int sign = 1;
            if (c == '-') { sign = -1; c = read(); }
            long val = 0;
            while (c > 32) {
                val = val * 10 + (c - '0');
                c = read();
            }

            return val * sign;
        }

        int nextInt() throws IOException { return (int)nextLong(); }
    }
    public static void main(String[] args) throws Exception {
        FastScanner fs = new FastScanner(System.in);
        StringBuilder sb = new StringBuilder();
        int T = (int) fs.nextLong();
        for (int t = 0; t < T; t++) {
            long N = fs.nextLong();
            long K = fs.nextLong();
            long ans = solve(N, K);
            sb.append(ans).append('\n');
        }

        System.out.print(sb.toString());
    }
    static long solve(long N, long K) {
        if (K >= 61) return 0L;

        long denom1 = 1L << (int) K;
        long q1 = N / denom1;

        long q2;
        if (K >= 60) {
            q2 = 0L;
        } else {
            long denom2 = denom1 << 1;
            q2 = N / denom2;
        }

        return q1 - q2;
    }
}