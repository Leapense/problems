import java.io.*;

public class Main {
    private static class FastScanner {
        private final InputStream in;
        private final byte[] buffer = new byte[1 << 16];
        private int ptr = 0, len = 0;

        FastScanner(InputStream is) { this.in = is; }

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
                if (c == -1) return Long.MIN_VALUE;
            } while (c <= ' ');

            int sign = 1;
            if (c == '-') {
                sign = -1;
                c = read();
            }

            long val = 0;
            while (c > ' ') {
                val = val * 10 + (c - '0');
                c = read();
            }

            return val * sign;
        }
    }

    public static void main(String[] args) throws Exception {
        FastScanner fs = new FastScanner(System.in);

        long nL = fs.nextLong();
        long k = fs.nextLong();
        int n = (int) nL;

        long sumA = 0L;
        long maxCand = Long.MIN_VALUE;

        for (int i = 0; i < n; i++) {
            long a = fs.nextLong();
            sumA += a;
            long cand = a - (long) i * k;
            if (cand > maxCand) maxCand = cand;
        }

        long nn = nL;
        long result = nn * maxCand + k * nn * (nn - 1) / 2 - sumA;
        System.out.println(result);
    }
}