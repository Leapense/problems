import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;
import java.util.List;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

public class Main
{
    private static final int MAX_METHODS = 400;
    private static final Map<String, Integer> idToIndex = new HashMap<>();
    private static final String[] indexToId = new String[MAX_METHODS + 1];
    private static List<Integer>[] adj;
    private static boolean[] visited;

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(reader.readLine().trim());
        if (n < 1 || n > MAX_METHODS) {
            System.out.println(0);
            return;
        }

        adj = new ArrayList[n];
        visited = new boolean[n];

        String[] identifiers = new String[n];
        String[] numCallersStr = new String[n];
        String[][] callerLists = new String[n][];

        for (int i = 0; i < n; i++) {
            String line = reader.readLine();
            while (line != null && line.isEmpty()) {
                line = reader.readLine();
            }

            StringTokenizer st = new StringTokenizer(line);
            String identifier = st.nextToken();
            identifiers[i] = identifier;
            String kStr = st.hasMoreTokens() ? st.nextToken() : "0";
            numCallersStr[i] = kStr;

            idToIndex.put(identifier, i);
            indexToId[i] = identifier;

            String callerLine = reader.readLine();
            if (callerLine == null || callerLine.isEmpty()) {
                callerLists[i] = new String[0];
            } else {
                StringTokenizer st2 = new StringTokenizer(callerLine);
                int k = Integer.parseInt(kStr);
                String[] temp = new String[k];
                for (int j = 0; j < k; j++) {
                    temp[j] = st2.nextToken();
                }

                callerLists[i] = temp;
            }
        }

        for (int i = 0; i < n; i++) {
            adj[i] = new ArrayList<>();
        }

        for (int i = 0; i < n; i++) {
            String[] callers = callerLists[i];
            int calleeIndex = idToIndex.get(identifiers[i]);
            for (String callerId : callers) {
                Integer callerIndex = idToIndex.get(callerId);
                if (callerIndex != null) {
                    adj[callerIndex].add(calleeIndex);
                }
            }
        }

        List<Integer> roots = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            String identifier = indexToId[i];
            if (identifier.endsWith("::PROGRAM")) {
                roots.add(i);
            }
        }

        for (int root : roots) {
            if (!visited[root]) {
                dfs(root);
            }
        }

        int unusedCount = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                unusedCount++;
            }
        }

        System.out.println(unusedCount);
    }

    private static void dfs(int u) {
        visited[u] = true;
        for (int v : adj[u]) {
            if (!visited[v]) {
                dfs(v);
            }
        }
    }
}