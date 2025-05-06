import java.io.*;
import java.util.*;

public class Main {
    static int[] parent, sz;
    static int maxSize;

    static int find(int x) {
        while (parent[x] != x) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }

        return x;
    }

    static void union(int a, int b) {
        int ra = find(a);
        int rb = find(b);
        if (ra == rb)
            return;

        if (sz[ra] < sz[rb]) {
            parent[ra] = rb;
            sz[rb] += sz[ra];
            maxSize = Math.max(maxSize, sz[rb]);
        } else {
            parent[rb] = ra;
            sz[ra] += sz[rb];
            maxSize = Math.max(maxSize, sz[ra]);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        parent = new int[n + 1];
        sz = new int[n + 1];

        for (int i = 1; i <= n; i++) {
            parent[i] = i;
            sz[i] = 1;
        }
        maxSize = (n > 0 ? 1 : 0);

        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            union(u, v);
        }

        System.out.println(maxSize);
    }
}