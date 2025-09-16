import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int s = Integer.parseInt(st.nextToken());
        int p = Integer.parseInt(st.nextToken());
        int q = Integer.parseInt(st.nextToken());

        boolean[] pre = new boolean[n + 1];
        boolean[] want = new boolean[n + 1];

        for (int i = 0; i < p; i++) {
            int x = Integer.parseInt(br.readLine().trim());
            pre[x] = true;
        }
        for (int i = 0; i < q; i++) {
            int x = Integer.parseInt(br.readLine().trim());
            want[x] = true;
        }

        int P = (n + m - 1) / m;
        long clickSum = 0;

        int needFirst = Integer.MAX_VALUE;
        int needLast = -1;

        for (int t = 1; t <= P; t++) {
            int L = (t - 1) * m + 1;
            int R = Math.min(t * m, n);
            int len = R - L + 1;

            int diff = 0;
            int bcnt = 0;

            for (int i = L; i <= R; i++) {
                if (pre[i] != want[i]) diff++;
                if (want[i]) bcnt++;
            }

            int costToggle = diff;
            int costClearThenPick = 1 + bcnt;
            int costAllThenUnpick = 1 + (len - bcnt);

            int ct = Math.min(costToggle, Math.min(costClearThenPick, costAllThenUnpick));
            clickSum += ct;
            if (ct > 0) {
                if (t < needFirst) needFirst = t;
                if (t > needLast) needLast = t;
            }
        }

        int move = 0;
        if (needLast != -1) {
            int L = needFirst, U = needLast;
            move = Math.min(Math.abs(s - L), Math.abs(s - U)) + (U - L);
        }

        System.out.println(clickSum + move);
    }
}