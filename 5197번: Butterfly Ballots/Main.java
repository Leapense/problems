import java.io.*;
import java.util.*;

public class Main {
    private static final String POSSIBLE = "Possible";
    private static final String IMPOSSIBLE = "Impossible";

    public static void main(String[] args) throws Exception {
        FastScanner fs = new FastScanner(System.in);
        StringBuilder out = new StringBuilder();

        int K = fs.nextInt();

        for (int tc = 1; tc <= K; ++tc) {
            int n = fs.nextInt();
            int[] v = new int[n];
            for (int i = 0; i < n; ++i)
                v[i] = fs.nextInt();

            Arrays.sort(v, 1, n);

            boolean ok = true;
            final int threshold = 2 * v[0] + v[n - 1];

            for (int i = 1; i < n && ok; ++i) {
                int lo = (i + 1) / 2;
                int hi = (2 * n - i - 1) / 2;
                if (threshold < v[lo] + v[hi])
                    ok = false;
            }

            out.append("Data Set ").append(tc).append(":\n")
                    .append(ok ? POSSIBLE : IMPOSSIBLE).append('\n');
        }

        System.out.print(out);
    }

    private static final class FastScanner {
        private final byte[] buffer = new byte[1 << 16];
        private int bId = 0, size = 0;
        private final InputStream in;

        FastScanner(InputStream in) {
            this.in = in;
        }

        private byte read() throws IOException {
            if (bId == size) {
                size = in.read(buffer);
                bId = 0;
                if (size == -1)
                    buffer[0] = -1;
            }
            return buffer[bId++];
        }

        int nextInt() throws IOException {
            int c, sign = 1, res = 0;
            while ((c = read()) <= ' ') {
            }
            if (c == '-') {
                sign = -1;
                c = read();
            }
            do {
                res = res * 10 + (c - '0');
            } while ((c = read()) > ' ');
            return res * sign;
        }
    }
}