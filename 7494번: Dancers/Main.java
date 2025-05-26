import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main
{
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(reader.readLine().trim());
        long[] x = new long[n + 1];
        long[] y = new long[n + 1];

        for (int i = 1; i <= n; i++) {
            StringTokenizer st = new StringTokenizer(reader.readLine());
            x[i] = Long.parseLong(st.nextToken());
            y[i] = Long.parseLong(st.nextToken());
        }

        List<Edge> edges = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                long dx = x[i] - x[j];
                long dy = y[i] - y[j];
                edges.add(new Edge(i, j, dx * dx + dy * dy));
            }
        }

        edges.sort(Comparator.comparingLong((Edge e) -> e.dist).thenComparingInt(e -> e.i).thenComparingInt(e -> e.j));

        boolean[] used = new boolean[n + 1];
        List<Pair> result = new ArrayList<>();
        for (Edge e : edges) {
            if (!used[e.i] && !used[e.j]) {
                used[e.i] = used[e.j] = true;
                result.add(new Pair(e.i, e.j));
                if (result.size() == n / 2) {
                    break;
                }
            }
        }

        result.sort(Comparator.comparingInt((Pair p) -> p.i).thenComparingInt(p -> p.j));

        StringBuilder sb = new StringBuilder();
        for (Pair p : result) {
            sb.append(p.i).append(' ').append(p.j).append('\n');
        }

        System.out.print(sb);
    }

    private static class Edge {
        final int i;
        final int j;
        final long dist;

        Edge(int i, int j, long dist) {
            this.i = i;
            this.j = j;
            this.dist = dist;
        }
    }

    private static class Pair {
        final int i;
        final int j;
        Pair(int i, int j) {
            this.i = i;
            this.j = j;
        }
    }
}