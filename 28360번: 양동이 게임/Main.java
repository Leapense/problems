import java.io.*;
import java.util.*;
public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        List<Integer>[] adj = new ArrayList[N + 1];
        for (int i = 1; i <= N; i++) adj[i] = new ArrayList<>();

        int[] outdeg = new int[N + 1];
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int v = Integer.parseInt(st.nextToken());
            int w = Integer.parseInt(st.nextToken());
            adj[v].add(w);
            outdeg[v]++;
        }
        double[] amt = new double[N + 1];
        amt[1] = 100.0;
        for (int v = 1; v <= N; v++) {
            if (outdeg[v] == 0) continue;
            double share = amt[v] / outdeg[v];
            for (int w : adj[v]) {
                amt[w] += share;
            }
            amt[v] = 0.0;
        }
        double ans = 0.0;
        for (int i = 1; i <= N; i++) ans = Math.max(ans, amt[i]);

        System.out.printf("%.10f%n", ans);
    }
}