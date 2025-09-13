import java.io.*;

public class Main {
    static final class FastScanner {
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
        int N = fs.nextInt();
        int[] diff = new int[361];

        for (int i = 0; i < N; i++) {
            int a = fs.nextInt();
            int b = fs.nextInt();
            if (b == 180) {
                diff[0] += 1;
                diff[360] -= 1;
                continue;
            }
            int c = (a + 180) % 360;
            int s = c - b;
            if (s < 0) s += 360;
            int e = c + b;
            if (e >= 360) e -= 360;

            if (s <= e) {
                diff[s] += 1;
                diff[e + 1] -= 1;
            } else {
                diff[0] += 1;
                diff[e + 1] -= 1;
                diff[s] += 1;
                diff[360] -= 1;
            }
        }

        int ans = 0, cur = 0;
        for (int ang = 0; ang < 360; ang++) {
            cur += diff[ang];
            if (cur > 0) ans++;
        }

        System.out.println(ans);
    }
}