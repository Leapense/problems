import java.io.*;
import java.util.*;

public class Main {
    static int n, iPos, jPos;

    static int riffle(int p) {
        if (p <= n) return 2 * p - 1;
        return 2 * (p - n);
    }

    static int scuffle(int p) {
        if ((p & 1) == 1) return p + 1;
        return p - 1;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        iPos = Integer.parseInt(st.nextToken());
        jPos = Integer.parseInt(st.nextToken());

        if (iPos == jPos) {
            System.out.println(0);
            return;
        }

        int size = 2 * n;
        boolean[] vis = new boolean[size + 1];
        ArrayDeque<Integer> q = new ArrayDeque<>();
        ArrayDeque<Integer> d = new ArrayDeque<>();

        vis[iPos] = true;
        q.add(iPos);
        d.add(0);

        while (!q.isEmpty()) {
            int cur = q.poll();
            int dist = d.poll();

            int nr = riffle(cur);
            if (!vis[nr]) {
                if (nr == jPos) {
                    System.out.println(dist + 1);
                    return;
                }
                vis[nr] = true;
                q.add(nr);
                d.add(dist + 1);
            }

            int ns = scuffle(cur);
            if (!vis[ns]) {
                if (ns == jPos) {
                    System.out.println(dist + 1);
                    return;
                }

                vis[ns] = true;
                q.add(ns);
                d.add(dist + 1);
            }
        }

        System.out.println(-1);
    }
}