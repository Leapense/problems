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

        int nextInt() throws IOException {
            int c, sgn = 1, val = 0;
            do { c = read(); } while (c <= 32);
            if (c == '-') { sgn = -1; c = read(); }
            while (c > 32) {
                val = val * 10 + (c - '0');
                c = read();
            }

            return val * sgn;
        }
    }

    public static void main(String[] args) throws Exception {
        FastScanner fs = new FastScanner(System.in);
        int M = fs.nextInt();
        if (M <= 0) { System.out.println(1); return; }
        long prev = fs.nextInt();
        int read = 1;

        int maxUpRun = 0;
        int maxDownRun = 0;

        int curDir = 0;
        int curLen = 0;

        while (read < M) {
            long x = fs.nextInt();
            read++;

            if (x == prev) {
                continue;
            }

            int dir = (x > prev) ? +1 : -1;

            if (curDir == dir) {
                curLen += 1;
            } else {
                curDir = dir;
                curLen = 1;
            }

            if (dir == +1) {
                if (curLen > maxUpRun) maxUpRun = curLen;
            } else {
                if (curLen > maxDownRun) maxDownRun = curLen;
            }

            prev = x;
        }

        if (maxUpRun == 0 && maxDownRun == 0) {
            System.out.println(1);
            return;
        }
        int N = 1 + Math.max(maxUpRun, maxDownRun);
        System.out.println(N);
    }
}