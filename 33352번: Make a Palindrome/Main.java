import java.io.*;
import java.util.*;

public class Main {
    static final class FastScanner {
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
            do { c = read(); } while (c <= ' ' && c != -1);
            if (c == '-') { sgn = -1; c = read(); }
            while (c > ' ') {
                val = val * 10 + (c - '0');
                c = read();
            }
            return val * sgn;
        }

        String next() throws IOException {
            int c;
            StringBuilder sb = new StringBuilder();
            do { c = read(); } while (c <= ' ' && c != -1);
            while (c > ' ') {
                sb.append((char)c);
                c = read();
            }
            return sb.toString();
        }
    }

    public static void main(String[] args) throws Exception {
        FastScanner fs = new FastScanner(System.in);
        StringBuilder out = new StringBuilder();
        int t = fs.nextInt();
        for (int tc = 0; tc < t; tc++) {
            int n = fs.nextInt();
            String s = fs.next();
            int[][] cnt = new int[2][26];
            for (int i = 0; i < n; i++) {
                int g = i & 1;
                cnt[g][s.charAt(i) - 'a']++;
            }

            boolean ok;
            if ((n & 1) == 0) {
                ok = true;
                for (int c = 0; c < 26; c++) {
                    if (cnt[0][c] != cnt[1][c]) { ok = false; break; }
                }
            } else {
                int center = (n % 4 == 1) ? 0 : 1;
                int other = 1 - center;
                ok = true;

                for (int c = 0; c < 26 && ok; c++) {
                    if ((cnt[other][c] & 1) != 0) ok = false;
                }

                if (ok) {
                    int oddKinds = 0;
                    for (int c = 0; c < 26; c++) {
                        if ((cnt[center][c] & 1) != 0) oddKinds++;
                    }
                    if (oddKinds > 1) ok = false;
                }
            }

            out.append(ok ? "YES\n" : "NO\n");
        }
        System.out.print(out.toString());
    }
}