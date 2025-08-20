import java.io.BufferedInputStream;
import java.io.IOException;
import java.io.InputStream;

public class Main {
    private static final int MOD = 1_000_000_007;
    private static final class FastScanner {
        private final InputStream in;
        private final byte[] buffer = new byte[1 << 16];
        private int ptr = 0;
        private int len = 0;

        FastScanner(InputStream in) {
            this.in = in;
        }

        private int read() throws IOException {
            if (ptr >= len) {
                len = in.read(buffer);
                ptr = 0;
                if (len <= 0) {
                    return -1;
                }
            }
            return buffer[ptr++];
        }

        int nextInt() throws IOException {
            int c = read();
            while (c <= 32) {
                c = read();
            }
            int sign = 1;
            if (c == '-') {
                sign = -1;
                c = read();
            }

            int val = 0;
            while (c > 32) {
                val = val * 10 + (c - 48);
                c = read();
            }

            return val * sign;
        }
    }

    public static void main(String[] args) throws Exception {
        FastScanner fs = new FastScanner(new BufferedInputStream(System.in));
        int n = fs.nextInt();
        int m = fs.nextInt();

        int[] prev = new int[m];
        for (int c = 0; c < m; c++) {
            int cell = fs.nextInt();
            prev[c] = cell == 1 ? 1 : 0;
        }

        int[] cur = new int[m];
        for (int r = 1; r < n; r++) {
            for (int c = 0; c < m; c++) {
                int cell = fs.nextInt();
                if (cell == 0) {
                    cur[c] = 0;
                } else {
                    long sum = prev[c];
                    if (c > 0) {
                        sum += prev[c - 1];
                    }
                    if (c + 1 < m) {
                        sum += prev[c + 1];
                    }
                    cur[c] = (int)(sum % MOD);
                }
            }
            int[] tmp = prev;
            prev = cur;
            cur = tmp;
        }

        long answer = 0;
        for (int v : prev) {
            answer += v;
        }
        answer %= MOD;
        System.out.println(answer);
    }
}