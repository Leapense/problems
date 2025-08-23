import java.io.IOException;
import java.io.InputStream;
import java.util.TreeSet;

public class Main {
    private static final class FastScanner {
        private final InputStream in;
        private final byte[] buffer;
        private int ptr;
        private int len;

        FastScanner(InputStream in) {
            this.in = in;
            this.buffer = new byte[1 << 16];
            this.ptr = 0;
            this.len = 0;
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

        long nextLong() throws IOException {
            int c = read();
            while (c <= ' ') {
                c = read();
            }
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

            return sign == 1 ? val : -val;
        }
    }

    private static long gcd(long a, long b) {
        a = Math.abs(a);
        b = Math.abs(b);
        while (b != 0) {
            long t = a % b;
            a = b;
            b = t;
        }
        return a;
    }

    private static void addDivisors(long n, TreeSet<Long> out) {
        if (n <= 0) {
            return;
        }
        for (long d = 1; d * d <= n; d++) {
            if (n % d == 0) {
                out.add(d);
                long other = n / d;
                if (other != d) {
                    out.add(other);
                }
            }
        }
    }

    public static void main(String[] args) throws Exception {
        FastScanner fs = new FastScanner(System.in);
        int t = (int) fs.nextLong();
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < t; i++) {
            long w = fs.nextLong();
            long l = fs.nextLong();
            TreeSet<Long> ans = new TreeSet<>();
            ans.add(1L);
            ans.add(2L);
            long g1 = gcd(w - 2, l);
            long g2 = gcd(w - 1, l - 1);
            long g3 = gcd(w, l - 2);
            addDivisors(g1, ans);
            addDivisors(g2, ans);
            addDivisors(g3, ans);
            sb.append(ans.size());
            for (long a : ans) {
                sb.append(' ').append(a);
            }
            if (i + 1 < t) {
                sb.append('\n');
            }
        }

        System.out.print(sb.toString());
    }
}