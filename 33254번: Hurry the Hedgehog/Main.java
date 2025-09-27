import java.io.*;
import java.util.*;

public class Main {
    static class FastScanner {
        private final InputStream in;
        private final byte[] buffer = new byte[1 << 16];
        private int ptr = 0, len = 0;

        FastScanner (InputStream is) {
            in = is;
        }

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
            do {
                c = read();
                if (c == -1) return Integer.MIN_VALUE;
            } while (c <= ' ');
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            while (c > ' ') {
                x = x * 10 + (c - '0');
                c = read();
            }
            return x * sgn;
        }
    }

    static int n, m, s;
    static boolean[] allowed;

    static int[] head, to, next;
    static int edgePtr = 0;

    static void initGraph(int n, int m) {
        head = new int[n + 1];
        Arrays.fill(head, -1);
        to = new int[2 * m];
        next = new int[2 * m];
        edgePtr = 0;
    }

    static void addEdge(int u, int v) {
        to[edgePtr] = v;
        next[edgePtr] = head[u];
        head[u] = edgePtr++;
    }

    static int bfs() {
        int[] dist = new int[n + 1];
        Arrays.fill(dist, -1);
        int[] q = new int[n + 5];
        int qs = 0, qe = 0;

        if (!allowed[1]) return -1;
        dist[1] = 0;
        q[qe++] = 1;

        while (qs < qe) {
            int u = q[qs++];
            if (u == n) break;
            for (int e = head[u]; e != -1; e = next[e]) {
                int v = to[e];
                if (!allowed[v]) continue;
                if (dist[v] != -1) continue;
                dist[v] = dist[u] + 1;
                q[qe++] = v;
            }
        }

        if (dist[n] == -1) return -1;
        return dist[n] + 1;
    }

    public static void main(String[] args) throws Exception {
        FastScanner fs = new FastScanner(System.in);

        n = fs.nextInt();
        m = fs.nextInt();
        s = fs.nextInt();

        allowed = new boolean[n + 1];
        if (n >= 1) allowed[1] = true;
        allowed[n] = true;

        int extra = Math.max(0, s - 2);
        for (int i = 0; i < extra; i++) {
            int v = fs.nextInt();
            if (1 <= v && v <= n) allowed[v] = true;
        }

        initGraph(n, m);
        for (int i = 0; i < m; i++) {
            int u = fs.nextInt();
            int v = fs.nextInt();
            if (u < 1 || u > n || v < 1 || v > n) continue;
            addEdge(u, v);
            addEdge(v, u);
        }

        int ans = bfs();
        System.out.println(ans);
    }
}