import java.io.*;
import java.util.*;

public class Main {
    static List<Integer> primes = new ArrayList<>();
    static Map<Integer, Integer> idx = new HashMap<>();
    static List<Integer>[] adj;
    static Boolean[][] dp;
    static int[][] next;
    static int Bidx;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int A = Integer.parseInt(st.nextToken());
        int B = Integer.parseInt(st.nextToken());
        int N = Integer.parseInt(st.nextToken());

        for (int x = 11; x <= 97; x++) if (isPrime(x)) {
            idx.put(x, primes.size());
            primes.add(x);
        }
        if (!idx.containsKey(A) || !idx.containsKey(B)) {
            System.out.println("-1");
            return;
        }

        int V = primes.size();
        adj = new ArrayList[V];

        for (int i = 0; i < V; i++) adj[i] = new ArrayList<>();
        for (int i = 0; i < V; i++) {
            int p = primes.get(i);
            int last = p % 10;
            for (int j = 0; j < V; j++) {
                int q = primes.get(j);
                int first = q / 10;
                if (last == first) adj[i].add(j);
            }
        }

        int Aidx = idx.get(A);
        Bidx = idx.get(B);
        int needEdges = N - 2;

        dp = new Boolean[V][Math.max(0, needEdges) + 1];
        next = new int[V][Math.max(0, needEdges) + 1];
        for (int i = 0; i < V; i++) Arrays.fill(next[i], -1);

        boolean ok = dfs(Aidx, needEdges);
        if (!ok) {
            System.out.println("-1");
            return;
        }

        List<Integer> path = new ArrayList<>();
        int u = Aidx, k = needEdges;
        path.add(u);
        while (k > 0) {
            u = next[u][k];
            path.add(u);
            k--;
        }

        if (path.get(path.size() - 1) != Bidx) {
            System.out.println("-1");
            return;
        }

        StringBuilder sb = new StringBuilder();
        sb.append(primes.get(path.get(0)));
        for (int t = 1; t < path.size(); t++) {
            int q = primes.get(path.get(t));
            sb.append(q % 10);
        }
        if (sb.length() != N) {
            System.out.println("-1");
            return;
        }
        System.out.println(sb.toString());
    }

    static boolean dfs(int u, int k) {
        if (dp[u][k] != null) return dp[u][k];
        if (k == 0) return dp[u][k] = (u == Bidx);
        for (int v : adj[u]) {
            if (dfs(v, k - 1)) {
                next[u][k] = v;
                return dp[u][k] = true;
            }
        }

        return dp[u][k] = false;
    }

    static boolean isPrime(int x) {
        if (x < 2) return false;
        if (x % 2 == 0) return x == 2;
        for (int d = 3; d * d <= x; d += 2) {
            if (x % d == 0) return false;
        }

        return true;
    }
}