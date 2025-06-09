import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    private static List<Integer>[] adj;
    private static boolean[] visited;
    private static int startNode;
    private static int bestCycleLength;

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(
            new InputStreamReader(System.in)
        );
        StringTokenizer tokenizer = new StringTokenizer(reader.readLine());
        int T = Integer.parseInt(tokenizer.nextToken());

        for (int tc = 1; tc <= T; ++tc) {
            int N = Integer.parseInt(reader.readLine().trim());
            buildGraph(N, reader);
            bestCycleLength = 0;
            visited = new boolean[N + 1];

            // Enumerate cycles by choosing the minimal node as start
            for (startNode = 1; startNode <= N; ++startNode) {
                visited[startNode] = true;
                for (int neighbor : adj[startNode]) {
                    if (neighbor > startNode) {
                        dfs(neighbor, 2);
                    }
                }
                visited[startNode] = false;
            }

            System.out.printf("Case #%d: %d%n", tc, bestCycleLength);
        }
    }

    // Build the adjacency list from input
    @SuppressWarnings("unchecked")
    private static void buildGraph(int N, BufferedReader reader)
        throws IOException {
        adj = new ArrayList[N + 1];
        for (int i = 1; i <= N; ++i) {
            adj[i] = new ArrayList<>();
        }
        // initial triangle
        addEdge(1, 2);
        addEdge(2, 3);
        addEdge(3, 1);

        // each new node i attaches to A and B
        for (int i = 4; i <= N; ++i) {
            StringTokenizer st = new StringTokenizer(reader.readLine());
            int A = Integer.parseInt(st.nextToken());
            int B = Integer.parseInt(st.nextToken());
            addEdge(i, A);
            addEdge(i, B);
        }
    }

    // Undirected edge insertion
    private static void addEdge(int u, int v) {
        adj[u].add(v);
        adj[v].add(u);
    }

    // Depth-first search for cycles returning to startNode
    private static void dfs(int current, int depth) {
        if (current == startNode) {
            // We have formed a cycle of length == depth
            if (depth >= 3 && depth > bestCycleLength) {
                bestCycleLength = depth;
            }
            return;
        }
        if (visited[current]) {
            return;
        }
        visited[current] = true;

        for (int nxt : adj[current]) {
            // Only allow return to startNode; avoid revisiting other nodes
            if (nxt == startNode) {
                dfs(nxt, depth + 1);
            } else if (!visited[nxt]) {
                dfs(nxt, depth + 1);
            }
        }

        visited[current] = false;
    }
}