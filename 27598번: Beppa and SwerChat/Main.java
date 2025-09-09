import java.io.*;

public class Main {
    static class FastScanner {
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
            int c, s = 1, x = 0;
            do { c = read(); } while (c <= ' ');
            if (c == '-') { s = -1; c = read(); }
            while (c > ' ') {
                x = x * 10 + (c - '0');
                c = read();
            }

            return x * s;
        }
    }

    public static void main(String[] args) throws Exception {
        FastScanner fs = new FastScanner(System.in);
        StringBuilder out = new StringBuilder();
        int t = fs.nextInt();
        while (t-- > 0) {
            int n = fs.nextInt();

            int[] pos = new int[n + 1];
            for (int i = 0; i < n; i++) {
                int id = fs.nextInt();
                pos[id] = i;
            }

            int[] b = new int[n];
            for (int i = 0; i < n; i++) b[i] = fs.nextInt();

            int kept = 0;
            int lastPos = Integer.MAX_VALUE;

            for (int i = n - 1; i >= 0; i--) {
                int p = pos[b[i]];
                if (p < lastPos) {
                    kept++;
                    lastPos = p;
                } else {
                    break;
                }
            }

            int answer = n - kept;
            out.append(answer).append('\n');
        }

        System.out.print(out.toString());
    }
}