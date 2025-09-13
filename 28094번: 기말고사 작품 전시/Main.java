import java.io.*;
import java.util.*;

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
            do {
                c = read();
            } while (c <= 32 && c != -1);
            long sgn = 1;
            if (c == '-') { sgn = -1; c = read(); }
            long val = 0;
            while (c > 32) {
                val = val * 10 + (c - '0');
                c = read();
            }
            return val * sgn;
        }

        int nextInt() throws IOException {
            return (int)nextLong();
        }
    }

    public static void main(String[] args) throws Exception {
        FastScanner fs = new FastScanner(System.in);
        StringBuilder out = new StringBuilder();
        int T = fs.nextInt();
        while (T-- > 0) {
            int N = fs.nextInt();
            int M = fs.nextInt();

            long[][] W = new long[N][N];
            for (int j = 0; j < M; j++) {
                long V = fs.nextLong();
                int A = fs.nextInt() - 1;
                int B = fs.nextInt() - 1;
                if (A != B) W[A][B] += V;
            }

            int FULL = (1 << N) - 1;
            long[][] gain = new long[N][1 << N];
            for (int k = 0; k < N; k++) {
                gain[k][0] = 0;
                for (int mask = 1; mask <= FULL; mask++) {
                    int lsb = mask & -mask;
                    int i = Integer.numberOfTrailingZeros(lsb);
                    gain[k][mask] = gain[k][mask ^ lsb] + W[i][k];
                }
            }

            long[] dpScore = new long[1 << N];
            long[] dpCount = new long[1 << N];
            Arrays.fill(dpScore, Long.MIN_VALUE / 4);
            dpScore[0] = 0;
            dpCount[0] = 1;

            for (int mask = 1; mask <= FULL; mask++) {
                long best = Long.MIN_VALUE / 4;
                long ways = 0;
                int sub = mask;
                while (sub != 0) {
                    int lsb = sub & -sub;
                    int k = Integer.numberOfTrailingZeros(lsb);
                    int prev = mask ^ (1 << k);
                    long cand = dpScore[prev] + gain[k][prev];
                    if (cand > best) {
                        best = cand;
                        ways = dpCount[prev];
                    } else if (cand == best) {
                        ways += dpCount[prev];
                    }
                    sub ^= lsb;
                }
                dpScore[mask] = best;
                dpCount[mask] = ways;
            }

            out.append(dpScore[FULL]).append(' ').append(dpCount[FULL]).append('\n');
        }

        System.out.print(out.toString());
    }
}