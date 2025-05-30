import java.io.*;
import java.util.*;

public class Main
{
    private static final class IntPair {
        final int from;
        final int to;

        IntPair(int from, int to) {
            this.from = from;
            this.to = to;
        }

        @Override
        public int hashCode() {
            return (from << 11) ^ to;
        }

        @Override
        public boolean equals(Object obj) {
            if (!(obj instanceof IntPair)) {
                return false;
            }

            IntPair other = (IntPair) obj;
            return from == other.from && to == other.to;
        }
    }

    public static void main(String[] args) throws IOException {
        FastScanner fs = new FastScanner();
        int v = fs.nextInt();
        int e = fs.nextInt();

        List<List<Integer>> graph = new ArrayList<>(v);
        List<List<Integer>> revGraph = new ArrayList<>(v);
        for (int i = 0; i < v; i++)
        {
            graph.add(new ArrayList<>());
            revGraph.add(new ArrayList<>());
        }
        for (int i = 0; i < e; i++) {
            int a = fs.nextInt();
            int b = fs.nextInt();
            graph.get(a).add(b);
            revGraph.get(b).add(a);
        }

        boolean[] visited = new boolean[v];
        Deque<Integer> order = new ArrayDeque<>();
        for (int i = 0; i < v; i++) {
            if (!visited[i]) {
                dfs1(i, graph, visited, order);
            }
        }

        int[] comp = new int[v];
        Arrays.fill(comp, -1);
        int compCnt = 0;
        while (!order.isEmpty())
        {
            int node = order.pop();
            if (comp[node] == -1) 
            {
                dfs2(node, revGraph, comp, compCnt++);
            }
        }

        List<List<Integer>> dag = new ArrayList<>(compCnt);
        for (int i = 0; i < compCnt; i++)
        {
            dag.add(new ArrayList<>());
        }

        Set<IntPair> edgeSet = new HashSet<>();
        for (int u = 0; u < v; u++) {
            for (int vtx : graph.get(u))
            {
                int cu = comp[u];
                int cv = comp[vtx];
                if (cu != cv && edgeSet.add(new IntPair(cu, cv))) {
                    dag.get(cu).add(cv);
                }
            }
        }

        int[] indeg = new int[compCnt];
        for (int u = 0; u < compCnt; u++)
        {
            for (int w : dag.get(u))
            {
                indeg[w]++;
            }
        }

        Deque<Integer> queue = new ArrayDeque<>();
        for (int i = 0; i < compCnt; i++) {
            if (indeg[i] == 0) {
                queue.add(i);
            }
        }
        int[] topo = new int[compCnt];
        int idx = 0;
        while (!queue.isEmpty())
        {
            int u = queue.poll();
            topo[idx++] = u;
            for (int w : dag.get(u)) {
                if (--indeg[w] == 0) {
                    queue.add(w);
                }
            }
        }

        BitSet[] reach = new BitSet[compCnt];
        for (int i = 0; i < compCnt; i++)
        {
            reach[i] = new BitSet(compCnt);
            reach[i].set(i);
        }

        for (int i = compCnt - 1; i >= 0; i--) {
            int u = topo[i];
            for (int w : dag.get(u))
            {
                reach[u].set(w);
                reach[u].or(reach[w]);
            }
        }

        fs.skipBlankLine();
        int q = fs.nextInt();
        StringBuilder sb = new StringBuilder(q * 2);
        for (int i = 0; i < q; i++)
        {
            int x = fs.nextInt();
            int y = fs.nextInt();
            int cx = comp[x];
            int cy = comp[y];

            boolean ok = (cx == cy) || reach[cx].get(cy);
            sb.append(ok ? '1' : '0').append('\n');
        }

        System.out.print(sb.toString());
    }

    private static void dfs1(int u, List<List<Integer>> g, boolean[] vis, Deque<Integer> order) {
        vis[u] = true;
        for (int v : g.get(u))
        {
            if (!vis[v])
            {
                dfs1(v, g, vis, order);
            }
        }

        order.push(u);
    }

    private static void dfs2(int u, List<List<Integer>> rg, int[] comp, int cid)
    {
        comp[u] = cid;
        for (int v : rg.get(u))
        {
            if (comp[v] == -1) {
                dfs2(v, rg, comp, cid);
            }
        }
    }

    private static final class FastScanner {
        private final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        private StringTokenizer st;

        int nextInt() throws IOException {
            while (st == null || !st.hasMoreTokens()) {
                String line = br.readLine();
                while (line != null && line.trim().isEmpty()) {
                    line = br.readLine();
                }

                if (line == null) {
                    throw new IOException("Unexpected end of input");
                }
                st = new StringTokenizer(line);
            }

            return Integer.parseInt(st.nextToken());
        }

        void skipBlankLine() throws IOException {
            br.mark(1 << 10);
            int c = br.read();
            if (c != '\n' && c != '\r' && c != -1)
            {
                br.reset();
            }
        }
    }
}