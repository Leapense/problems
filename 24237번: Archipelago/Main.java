import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    private static class IslandLocation {
        final long x;
        final long y;
        public IslandLocation(long x, long y) {
            this.x = x;
            this.y = y;
        }
    }
    public static class IslandUtility implements Comparable<IslandUtility> {
        final int id;
        final int utility;
        public IslandUtility(int id, int utility) {
            this.id = id;
            this.utility = utility;
        }

        @Override
        public int compareTo(IslandUtility other) {
            if (this.utility != other.utility) {
                return Integer.compare(other.utility, this.utility);
            }
            return Integer.compare(this.id, other.id);
        }
    }
    private static class DSU {
        private final int[] parent;
        private final int[] componentSize;

        public DSU(int n) {
            parent = new int[n];
            componentSize = new int[n];
            for (int i = 0; i < n; i++) {
                parent[i] = i;
                componentSize[i] = 1;
            }
        }

        public int find(int i) {
            if (parent[i] == i) {
                return i;
            }
            parent[i] = find(parent[i]);
            return parent[i];
        }

        public void union(int i, int j) {
            int rootI = find(i);
            int rootJ = find(j);
            if (rootI != rootJ) {
                if (componentSize[rootI] < componentSize[rootJ]) {
                    int temp = rootI;
                    rootI = rootJ;
                    rootJ = temp;
                }
                parent[rootJ] = rootI;
                componentSize[rootI] += componentSize[rootJ];
            }
        }

        public int getSize(int i) {
            return componentSize[find(i)];
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        long d = Long.parseLong(st.nextToken());

        List<IslandLocation> islands = new ArrayList<>(n);
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            long x = Long.parseLong(st.nextToken());
            long y = Long.parseLong(st.nextToken());
            islands.add(new IslandLocation(x, y));
        }

        long dSquared = d * d;
        DSU dsu = new DSU(n);

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                IslandLocation island1 = islands.get(i);
                IslandLocation island2 = islands.get(j);

                long dx = island1.x - island2.x;
                long dy = island1.y - island2.y;
                long distSquared = dx * dx + dy * dy;
                if (distSquared <= dSquared) {
                    dsu.union(i, j);
                }
            }
        }

        List<IslandUtility> results = new ArrayList<>(n);
        for (int i = 0; i < n; i++) {
            results.add(new IslandUtility(i + 1, dsu.getSize(i)));
        }

        Collections.sort(results);

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; i++) {
            sb.append(results.get(i).id);
            if (i < n - 1) {
                sb.append(" ");
            }
        }

        System.out.println(sb.toString());
    }
}