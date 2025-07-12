import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class Main
{
    private static List<List<Integer>> children;
    private static String[] messages;
    private static StringBuilder output = new StringBuilder();

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(reader.readLine());
        children = new ArrayList<>(n + 1);
        for (int i = 0; i <= n; i++) {
            children.add(new ArrayList<>());
        }
        messages = new String[n + 1];
        for (int i = 1; i <= n; i++) {
            int parent = Integer.parseInt(reader.readLine());
            messages[i] = reader.readLine();
            children.get(parent).add(i);
        }
        dfs(1, 0);
        System.out.print(output);
    }

    private static void dfs(int node, int depth) {
        for (int i = 0; i < depth; i++) {
            output.append('.');
        }
        output.append(messages[node]).append('\n');
        for (int child : children.get(node)) {
            dfs(child, depth + 1);
        }
    }
}