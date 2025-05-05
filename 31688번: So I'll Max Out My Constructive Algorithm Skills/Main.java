import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        FastScanner fs = new FastScanner(System.in);
        StringBuilder out = new StringBuilder();
        int T = fs.nextInt();
        while (T-- > 0) {
            int n = fs.nextInt();
            int[][] h = new int[n][n];
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    h[i][j] = fs.nextInt();
                }
            }

            int total = n * n;
            int[] seq = new int[total];
            int idx = 0;
            for (int i = 0; i < n; ++i) {
                if ((i & 1) == 0) {
                    for (int j = 0; j < n; ++j)
                        seq[idx++] = h[i][j];
                } else {
                    for (int j = n - 1; j >= 0; --j)
                        seq[idx++] = h[i][j];
                }
            }

            int up = 0;
            for (int k = 1; k < total; ++k) {
                if (seq[k] > seq[k - 1])
                    ++up;
            }

            int down = total - 1 - up;

            if (up > down) {
                for (int l = 0, r = total - 1; l < r; ++l, --r) {
                    int tmp = seq[l];
                    seq[l] = seq[r];
                    seq[r] = tmp;
                }
            }

            for (int i = 0; i < total; ++i) {
                out.append(seq[i]);
                out.append(i + 1 == total ? '\n' : ' ');
            }
        }
        System.out.println(out.toString());
    }

    private static class FastScanner {
        private final byte[] buf = new byte[1 << 16];
        private int len = 0, ptr = 0;
        private final InputStream in;

        FastScanner(InputStream in) {
            this.in = in;
        }

        private int readByte() throws IOException {
            if (ptr >= len) {
                len = in.read(buf);
                ptr = 0;
                if (len <= 0)
                    return -1;
            }

            return buf[ptr++];
        }

        int nextInt() throws IOException {
            int c, sign = 1, val = 0;
            do {
                c = readByte();
            } while (c <= ' ');
            if (c == '-') {
                sign = -1;
                c = readByte();
            }
            for (; c > ' '; c = readByte())
                val = val * 10 + c - '0';
            return val * sign;
        }
    }
}