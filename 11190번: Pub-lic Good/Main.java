import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public final class Main {
    public static void main(final String[] args)
    {
        try {
            BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
            StringTokenizer st = new StringTokenizer(reader.readLine());
            int vertexCount = Integer.parseInt(st.nextToken());
            int edgeCount = Integer.parseInt(st.nextToken());

            List<Integer>[] adjacency = new ArrayList[vertexCount + 1];
            for (int i = 1; i <= vertexCount; i++) {
                adjacency[i] = new ArrayList<>();
            }

            for (int i = 0; i < edgeCount; i++) {
                st = new StringTokenizer(reader.readLine());
                int u = Integer.parseInt(st.nextToken());
                int v = Integer.parseInt(st.nextToken());
                adjacency[u].add(v);
                adjacency[v].add(u);
            }

            for (int i = 1; i <= vertexCount; i++) {
                if (adjacency[i].isEmpty()) {
                    System.out.println("Impossible");
                    return;
                }
            }

            boolean[] visited = new boolean[vertexCount + 1];
            int[] label = new int[vertexCount + 1];

            for (int i = 1; i <= vertexCount; i++) {
                if (!visited[i]) {
                    visited[i] = true;
                    label[i] = 0;

                    Queue<Integer> queue = new LinkedList<>();
                    queue.add(i);

                    while (!queue.isEmpty()) {
                        int current = queue.poll();
                        for (int neighbor : adjacency[current]) {
                            if (!visited[neighbor]) {
                                visited[neighbor] = true;
                                label[neighbor] = 1 - label[current];
                                queue.add(neighbor);
                            }
                        }
                    }
                }
            }

            StringBuilder outputBuilder = new StringBuilder();
            for (int i = 1; i <= vertexCount; i++) {
                if (label[i] == 0) {
                    outputBuilder.append("pub");
                } else {
                    outputBuilder.append("house");
                }
                if (i < vertexCount) {
                    outputBuilder.append(' ');
                }
            }

            System.out.println(outputBuilder.toString());
        } catch (IOException exception) {

        }
    }
}