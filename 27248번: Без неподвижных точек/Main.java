import java.io.*;

public class Main {
    static int n, t;
    static int printed = 0;
    static int[] p;
    static boolean[] used;
    static StringBuilder out = new StringBuilder();

    public static void main(String[] args) throws Exception {
        FastScanner fs = new FastScanner(System.in);
        n = fs.nextInt();
        t = fs.nextInt();

        p = new int[n + 1];
        used = new boolean[n + 1];

        dfs(1);
        System.out.print(out.toString());
    }

    static boolean dfs(int pos) {
        if (printed >= t) return true;
        if (pos > n) {
            printLine();
            printed++;
            return printed >= t;
        }

        for (int v = 1; v <= n; v++) {
            if (v == pos || used[v]) continue;
            if (pos == n - 1) {
                int last = -1;
                for (int w = 1; w <= n; w++) {
                    if (!used[w] && w != v) {
                        last = w;
                        break;
                    }
                }

                if (last == n) continue;
            }

            used[v] = true;
            p[pos] = v;

            if (dfs(pos + 1)) return true;

            used[v] = false;
        }

        return false;
    }

    static void printLine() {
        for (int i = 1; i <= n; i++) {
            if (i > 1) out.append(' ');
            out.append(p[i]);
        }
        out.append('\n');
    }

    static class FastScanner {
        private final InputStream in;
        private final byte[] buffer = new byte[1 << 16];
        private int ptr = 0, len = 0;

        FastScanner(InputStream is) {in = is;}
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
            do { c = read(); } while (c <= 32);
            if (c == '-') { sgn = -1; c = read(); }
            for (; c > 32; c = read()) x = x * 10 + (c - '0');
            return x * sgn;
        }
    }
}