import java.io.*;
import java.util.*;

public class Main {
    private static class DSU {
        int[] p, r;

        DSU(int n) {
            p = new int[n];
            r = new int[n];
            Arrays.setAll(p, i -> i);
        }

        int find(int x) {
            return p[x] == x ? x : (p[x] = find(p[x]));
        }

        void union(int a, int b) {
            a = find(a);
            b = find(b);
            if (a == b)
                return;
            if (r[a] < r[b]) {
                int t = a;
                a = b;
                b = t;
            }
            p[b] = a;
            if (r[a] == r[b])
                ++r[a];
        }
    }

    private static int[] colour;
    private static List<Integer>[] adj;
    private static long total;

    public static void main(String[] args) throws Exception {
        FastScanner fs = new FastScanner(System.in);
        int N = fs.nextInt(), K = fs.nextInt();

        DSU dsu = new DSU(N);
        List<int[]> diff = new ArrayList<>();

        for (int i = 0; i < K; ++i) {
            char type = fs.next().charAt(0);
            int x = fs.nextInt() - 1;
            int y = fs.nextInt() - 1;
            if (type == 'S') {
                dsu.union(x, y);
            } else {
                diff.add(new int[] { x, y });
            }
        }

        Map<Integer, Integer> compId = new HashMap<>();
        int C = 0;
        int[] cowToComp = new int[N];

        for (int i = 0; i < N; ++i) {
            int root = dsu.find(i);
            Integer id = compId.get(root);

            if (id == null) {
                id = C;
                compId.put(root, C);
                ++C;
            }
            cowToComp[i] = id;
        }

        adj = new ArrayList[C];
        Arrays.setAll(adj, i -> new ArrayList<>());
        for (int[] pair : diff) {
            int a = cowToComp[pair[0]];
            int b = cowToComp[pair[1]];
            if (a == b) {
                System.out.println(0);
                return;
            }
            adj[a].add(b);
            adj[b].add(a);
        }

        colour = new int[C];
        total = 0;
        dfs(0, C);
        System.out.println(total);
    }

    private static void dfs(int idx, int C) {
        if (idx == C) {
            ++total;
            return;
        }
        if (colour[idx] != 0) {
            dfs(idx + 1, C);
            return;
        }

        for (int c = 1; c <= 3; ++c) {
            if (canUse(idx, c)) {
                colour[idx] = c;
                dfs(idx + 1, C);
                colour[idx] = 0;
            }
        }
    }

    private static boolean canUse(int u, int c) {
        for (int v : adj[u]) {
            if (colour[v] == c)
                return false;
        }

        return true;
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
            }
            return len == -1 ? -1 : buf[ptr++];
        }

        String next() throws IOException {
            StringBuilder sb = new StringBuilder();
            int c;
            while ((c = readByte()) <= ' ')
                if (c == -1)
                    return null;
            sb.append((char) c);
            while ((c = readByte()) > ' ')
                sb.append((char) c);
            return sb.toString();
        }

        int nextInt() throws IOException {
            return Integer.parseInt(next());
        }
    }
}