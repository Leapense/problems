
/*  BAEKJOON 31545 – Jaeu’s Retake 1
    verified on the samples and the hidden tests that killed the first approach  */
import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        /* --- pool size ----------------------------------------------------- */
        st = new StringTokenizer(br.readLine());
        int w = Integer.parseInt(st.nextToken());
        int h = Integer.parseInt(st.nextToken());

        /* --- lanes and destination ---------------------------------------- */
        st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int d = Integer.parseInt(st.nextToken());

        int[] a = new int[n + 1]; // lane boundaries, 1‑based, a[0]=0
        a[0] = 0;
        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= n; ++i)
            a[i] = Integer.parseInt(st.nextToken());

        int[] p = new int[n + 1]; // densities, 1‑based
        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= n; ++i)
            p[i] = Integer.parseInt(st.nextToken());

        /* --- prefix vertical times S[i] = Σ_{j=1..i} L_j * P_j ------------- */
        long[] S = new long[n + 1]; // S[0]=0
        for (int i = 1; i <= n; ++i) {
            int len = a[i] - a[i - 1];
            S[i] = S[i - 1] + 1L * len * p[i];
        }

        /* --- lane that contains y = d ------------------------------------- */
        int t = 1;
        while (t <= n && d > a[t])
            ++t; // smallest t with a_{t-1} < d ≤ a_t

        long C_d = S[t - 1] + 1L * (d - a[t - 1]) * p[t];

        long best = C_d + 1L * w * p[t]; // k = t (no extra climb)

        /* --- try climbing to every cheaper lane above t ------------------- */
        for (int k = t + 1; k <= n; ++k) {
            long Ck_1 = S[k - 1]; // cost up to a_{k-1}
            long candidate = 2 * Ck_1 - C_d + 1L * w * p[k];
            if (candidate < best)
                best = candidate;
        }

        System.out.println(best);
    }
}
