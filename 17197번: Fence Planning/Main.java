import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main
{
    private static int[] parent;
    private static int[] minX, maxX, minY, maxY;

    public static void main(String[] args) throws Exception {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        int[] x = new int[n], y = new int[n];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(in.readLine());
            x[i] = Integer.parseInt(st.nextToken());
            y[i] = Integer.parseInt(st.nextToken());
        }

        parent = new int[n];
        for (int i = 0; i < n; i++) parent[i] = i;

        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(in.readLine());
            int a = Integer.parseInt(st.nextToken()) - 1;
            int b = Integer.parseInt(st.nextToken()) - 1;
            union(a, b);
        }

        for (int i = 0; i < n; i++) {
            parent[i] = find(i);
        }

        minX = new int[n]; maxX = new int[n];
        minY = new int[n]; maxY = new int[n];

        for (int i = 0; i < n; i++) {
            minX[i] = minY[i] = Integer.MAX_VALUE;
            maxX[i] = maxY[i] = Integer.MIN_VALUE;
        }

        for (int i = 0; i < n; i++) {
            int r = parent[i];
            if (x[i] < minX[r]) minX[r] = x[i];
            if (x[i] > maxX[r]) maxX[r] = x[i];
            if (y[i] < minY[r]) minY[r] = y[i];
            if (y[i] > maxY[r]) maxY[r] = y[i];
        }

        long best = Long.MAX_VALUE;
        for (int i = 0; i < n; i++) {
            if (parent[i] == i) {
                long w = maxX[i] - minX[i];
                long h = maxY[i] - minY[i];
                long peri = 2L * (w + h);
                if (peri < best) best = peri;
            }
        }

        System.out.println(best);
    }

    private static int find(int u) {
        return parent[u] == u ? u : (parent[u] = find(parent[u]));
    }

    private static void union(int u, int v) {
        int ru = find(u);
        int rv = find(v);
        if (ru != rv) {
            parent[rv] = ru;
        }
    }
}