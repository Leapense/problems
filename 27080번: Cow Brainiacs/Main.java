import java.io.*;
import java.util.*;

public class Main {
    static class Pair {
        int p, a;
        Pair(int p, int a) { this.p = p; this.a = a; }
    }
    
    static List<Pair> factorize(int B) {
        List<Pair> f = new ArrayList<>();
        int b = B;
        for (int p = 2; p * p <= b; ++p) {
            if (b % p == 0) {
                int a = 0;
                while (b % p == 0) { b /= p; a++; }
                f.add(new Pair(p, a));
            }
        }
        if (b > 1) f.add(new Pair(b, 1));
        return f;
    }

    static long v_p_of_fact(long n, int p) {
        long v = 0, pk = p;
        while (pk <= n) {
            v += n / pk;
            if (pk > n / p) break;
            pk *= p;
        }
        return v;
    }

    static int modPow(int a, long e, int mod) {
        long res = 1 % mod;
        long base = a % mod;
        while (e > 0) {
            if ((e & 1) == 1) res = (res * base) % mod;
            base = (base * base) % mod;
            e >>= 1;
        }

        return (int)res;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int B = Integer.parseInt(st.nextToken());

        List<Pair> fac = factorize(B);

        long t = Long.MAX_VALUE;
        long[] v = new long[fac.size()];
        for (int i = 0; i < fac.size(); i++) {
            Pair pr = fac.get(i);
            v[i] = v_p_of_fact(N, pr.p);
            t = Math.min(t, v[i] / pr.a);
        }

        int[] r = new int[fac.size()];
        for (int i = 0; i < fac.size(); i++) {
            Pair pr = fac.get(i);
            r[i] = (int)(v[i] - t * pr.a);
        }

        int res = 1 % B;
        for (int i = 2; i <= N; i++) {
            long x = i;
            for (int j = 0; j < fac.size(); j++) {
                int p = fac.get(j).p;
                while (x % p == 0) x /= p;
            }

            res = (int)((res * (x % B)) % B);
        }

        for (int i = 0; i < fac.size(); i++) {
            int p = fac.get(i).p;
            if (r[i] > 0) res = (int)((res * 1L * modPow(p, r[i], B)) % B);
        }

        System.out.println(res % B);
    }
}