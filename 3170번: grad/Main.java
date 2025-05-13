import java.io.*;
import java.util.*;

public class Main
{
    public static void main(String[] args) throws IOException {
        var br = new BufferedReader(new InputStreamReader(System.in));
        var st = new StringTokenizer(br.readLine());
        int X = Integer.parseInt(st.nextToken());
        int Y = Integer.parseInt(st.nextToken());
        int N = Integer.parseInt(br.readLine().trim());

        int[] ax = new int[N], ay = new int[N], cr = new int[N];

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            ax[i] = Integer.parseInt(st.nextToken());
            ay[i] = Integer.parseInt(st.nextToken());
            cr[i] = Integer.parseInt(st.nextToken());
        }

        int sx = X / 2, sy = 0;

        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < N; i++) adj.add(new ArrayList<>());

        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                long dx = ax[i] - ax[j];
                long dy = ay[i] - ay[j];
                long dist2 = dx * dx + dy * dy;
                long rsum = cr[i] + cr[j];
                if (dist2 <= rsum * rsum) {
                    adj.get(i).add(j);
                    adj.get(j).add(i);
                }
            }
        }
        boolean[] vis = new boolean[N];
        Deque<Integer> dq = new ArrayDeque<>();
        for (int i = 0; i < N; i++) {
            long dx = ax[i] - sx;
            long dy = ay[i] - sy;
            if (dx * dx + dy * dy <= (long)cr[i] * cr[i]) {
                vis[i] = true;
                dq.add(i);
            }
        }

        while (!dq.isEmpty()) {
            int u = dq.poll();
            for (int v : adj.get(u)) {
                if (!vis[v]) {
                    vis[v] = true;
                    dq.add(v);
                }
            }
        }

        int K = Integer.parseInt(br.readLine().trim());
        var out = new StringBuilder();
        for (int q = 0; q < K; q++) {
            st = new StringTokenizer(br.readLine());
            int dx = Integer.parseInt(st.nextToken());
            int dy = Integer.parseInt(st.nextToken());
            boolean ok = false;

            for (int i = 0; i < N; i++) {
                if (!vis[i]) continue;
                long ddx = ax[i] - dx;
                long ddy = ay[i] - dy;
                if (ddx * ddx + ddy * ddy <= (long)cr[i] * cr[i]) {
                    ok = true;
                    break;
                }
            }

            out.append(ok ? "DA\n" : "NE\n");
        }

        System.out.print(out);
    }
}