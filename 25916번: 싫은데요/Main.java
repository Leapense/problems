import java.io.*;

public class Main {
    public static void main(String[] args) throws Exception {
        FastScanner fs = new FastScanner(System.in);
        int n = fs.nextInt();
        long M = fs.nextLong();
        long[] a = new long[n];
        for (int i = 0;  i < n; i++) a[i] = fs.nextLong();
        long sum = 0L;
        long ans = 0L;
        int l = 0;
        for (int r = 0; r < n; r++) {
            sum += a[r];
            while (sum > M && l <= r) {
                sum -= a[l++];
            }
            if (sum > ans) ans = sum;
        }
        System.out.println(ans);
    }

    static class FastScanner {
        private final InputStream in;
        private final byte[] buffer = new byte[1 << 16];
        private int ptr = 0;
        private int len = 0;
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
            while ((c = read()) <= ' ') {
                if (c == -1) return Long.MIN_VALUE;
            }
            int sign = 1;
            if (c == '-') {
                sign = -1;
                c = read();
            }
            long val = 0L;
            while (c > ' ') {
                val = val * 10 + (c - '0');
                c = read();
            }

            return val * sign;
        }
        int nextInt() throws IOException {
            return (int) nextLong();
        }
    }
}