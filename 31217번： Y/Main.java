import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        int[] degree = new int[n + 1];

        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());
            degree[u]++;
            degree[v]++;
        }

        long result = 0;
        long MOD = 1000000007;

        for (int i = 1; i <= n; i++) {
            if (degree[i] >= 3) {
                long d = degree[i];
                long count = d * (d - 1) * (d - 2) / 6;
                result = (result + count) % MOD;
            }
        }

        System.out.println(result);
    }
}