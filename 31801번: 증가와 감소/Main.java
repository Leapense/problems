import java.io.*;

public class Main {
    static final int MAX = 1_000_000;
    static int[] pref = new int[MAX + 1];

    public static void main(String[] args) throws Exception {
        FastScanner fs = new FastScanner(System.in);
        int cnt = 0;
        for (int x = 1; x <= MAX; x++) {
            if (isIncThenDec(x)) cnt++;
            pref[x] = cnt;
        }

        int t = fs.nextInt();
        StringBuilder sb = new StringBuilder();
        for (int tc = 0; tc < t; tc++) {
            int a = fs.nextInt();
            int b = fs.nextInt();
            int ans = pref[b] - (a > 1 ? pref[a - 1] : 0);
            sb.append(ans).append('\n');
        }
        System.out.print(sb.toString());
    }

    static boolean isIncThenDec(int n) {
        if (n < 100) return false;
        int[] d = digits(n);
        int k = d.length;

        int i = 0;
        while (i + 1 < k && d[i] < d[i + 1]) i++;
        if (i == 0) return false;
        int peak = i;
        while (i + 1 < k && d[i] > d[i + 1]) i++;
        if (i != k - 1) return false;
        if (i == peak) return false;
        return true;
    }

    static int[] digits(int n) {
        int tmp = n, len = 0;
        while (tmp > 0) { len++; tmp /= 10; }
        int[] d = new int[len];
        for (int i = len - 1; i >= 0; i--) {
            d[i] = n % 10;
            n /= 10;
        }
        return d;
    }

    static class FastScanner {
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
            int c, sgn = 1, x = 0;
            do { c = read(); } while (c <= ' ');
            if (c == '-') { sgn = -1; c = read(); }
            while (c > ' ') {
                x = x * 10 + (c - '0');
                c = read();
            }

            return x * sgn;
        }
    }
}