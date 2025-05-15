import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder out = new StringBuilder();

        int t = Integer.parseInt(br.readLine().trim());

        while (t-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());
            int l = Integer.parseInt(st.nextToken());

            // --- adjacency list ---
            @SuppressWarnings("unchecked")
            ArrayList<Integer>[] adj = new ArrayList[n + 1];
            for (int i = 1; i <= n; i++) adj[i] = new ArrayList<>();

            // --- read edges ---
            for (int i = 0; i < m; i++) {
                st = new StringTokenizer(br.readLine());
                int x = Integer.parseInt(st.nextToken());
                int y = Integer.parseInt(st.nextToken());
                adj[x].add(y);
            }

            boolean[] visited = new boolean[n + 1];
            int fallen = 0;

            // --- iterative DFS from every hand–pushed domino ---
            ArrayDeque<Integer> stack = new ArrayDeque<>();

            for (int i = 0; i < l; i++) {
                int z = Integer.parseInt(br.readLine().trim());
                if (visited[z]) continue;

                stack.clear();
                stack.push(z);

                while (!stack.isEmpty()) {
                    int cur = stack.pop();
                    if (visited[cur]) continue;
                    visited[cur] = true;
                    fallen++;

                    for (int nxt : adj[cur]) {
                        if (!visited[nxt]) stack.push(nxt);
                    }
                }
            }

            out.append(fallen).append('\n');
        }

        System.out.print(out.toString());
    }
}