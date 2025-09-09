import java.io.*;

public class Main {
    private static class FastScanner {
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

        int nextInt() throws IOException {
            int c, sgn = 1, val = 0;
            do { c = read(); } while (c <= ' ');
            if (c == '-') { sgn = -1; c = read(); }
            while (c > ' ') {
                val = val * 10 + (c - '0');
                c = read();
            }

            return val * sgn;
        }
    }

    public static void main(String[] args) throws Exception {
        FastScanner fs = new FastScanner(System.in);
        int N = fs.nextInt();
        int M = fs.nextInt();
        int[] A = new int[N];
        for (int i = 0; i < N; i++) A[i] = fs.nextInt();

        int T = (9 * M + 9) / 10;
        
        final int MAXV = 1_000_000;
        int[] freq = new int[MAXV + 1];

        for (int i = 0; i < M; i++) {
            int x = A[i];
            int f = ++freq[x];
            if (f >= T) {
                System.out.println("YES");
                return;
            }
        }

        for (int r = M; r < N; r++) {
            int outVal = A[r - M];
            int inVal = A[r];

            --freq[outVal];
            int f = ++freq[inVal];
            if (f >= T) {
                System.out.println("YES");
                return;
            }
        }

        System.out.println("NO");
    }
}