import java.io.*;
import java.util.*;

public class Main {
    static final long MOD = 1_000_000_007L;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        int h = Integer.parseInt(st.nextToken());
        int w = Integer.parseInt(st.nextToken());

        int[] r = new int[h];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < h; i++) r[i] = Integer.parseInt(st.nextToken());

        int[] c = new int[w];
        st = new StringTokenizer(br.readLine());
        for (int j = 0; j < w; j++) c[j] = Integer.parseInt(st.nextToken());

        int[][] state = new int[h][w];

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < r[i]; j++) {
                if (!set(state, i, j, 1)) {
                    System.out.println(0);
                    return;
                }
            }
            if (r[i] < w) {
                if (!set(state, i, r[i], -1)) {
                    System.out.println(0);
                    return;
                }
            }
        }

        for (int j = 0; j < w; j++) {
            for (int i = 0; i < c[j]; i++) {
                if (!set(state, i, j, 1)) {
                    System.out.println(0);
                    return;
                }
            }
            if (c[j] < h) {
                if (!set(state, c[j], j, -1)) {
                    System.out.println(0);
                    return;
                }
            }
        }

        long free = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (state[i][j] == 0) free++;
            }
        }

        System.out.println(powmod(2, free, MOD));
    }

    static boolean set(int[][] state, int i, int j, int val) {
        if (state[i][j] == 0) {
            state[i][j] = val;
            return true;
        }
        return state[i][j] == val;
    }

    static long powmod(long a, long e, long mod) {
        long res = 1 % mod;
        long base = a % mod;
        long exp = e;
        while (exp > 0) {
            if ((exp & 1) == 1) res = (res * base) % mod;
            base = (base * base) % mod;
            exp >>= 1;
        }

        return res;
    }
}