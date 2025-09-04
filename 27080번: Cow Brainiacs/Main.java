import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public final class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        long n = Long.parseLong(st.nextToken());
        int b = Integer.parseInt(st.nextToken());
        List<int[]> pf = factorize(b);
        List<long[]> rows = new ArrayList<>();
        for (int[] pa : pf) {
            int p = pa[0];
            int a = pa[1];
            long mod = 1;
            for (int i = 0; i < a; i++) {
                mod *= p;
            }
            long v = vpFactorial(n, p);
            rows.add(new long[]{p, a, v, mod});
        }
        long t = Long.MAX_VALUE;
        for (long[] r : rows) {
            t = Math.min(t, r[2] / r[1]);
        }

        long result = 0;
        long modAll = 1;
        boolean first = true;
        for (int i = 0; i < rows.size(); i++) {
            long p = rows.get(i)[0];
            long a = rows.get(i)[1];
            long v = rows.get(i)[2];
            long mod = rows.get(i)[3];
            long g = blockProduct((int) p, mod);
            long u = unitFactorial(n, (int) p, mod, g);
            long e = v - t * a;
            long r = mulMod(u, modPow(p, e, mod), mod);
            long kOther = 1 % mod;
            for (int j = 0; j < rows.size(); j++) {
                if (j == i) {
                    continue;
                }
                long pj = rows.get(j)[0];
                long aj = rows.get(j)[1];
                kOther = mulMod(kOther, modPow(pj, aj * t, mod), mod);
            }
            long inv = modInverse(kOther, mod);
            r = mulMod(r, inv, mod);
            if (first) {
                result = r;
                modAll = mod;
                first = false;
            } else {
                result = crtCombine(result, modAll, r, mod);
                modAll *= mod;
            }
        }
        System.out.println(result % b);
    }

    private static List<int[]> factorize(int x) {
        List<int[]> res = new ArrayList<>();
        int n = x;
        for (int p = 2; p * p <= n; p++) {
            if (n % p == 0) {
                int a = 0;
                while (n % p == 0) {
                    n /= p;
                    a++;
                }
                res.add(new int[]{p, a});
            }
        }
        if (n > 1) {
            res.add(new int[]{n, 1});
        }

        return res;
    }

    private static long vpFactorial(long n, int p) {
        long v = 0;
        long m = p;
        while (m <= n) {
            v += n / m;
            if (m > Long.MAX_VALUE / p) {
                break;
            }
            m *= p;
        }

        return v;
    }

    private static long blockProduct(int p, long mod) {
        long g = 1 % mod;
        for (long i = 1; i <= mod; i++) {
            if (i % p != 0) {
                g = (g * i) % mod;
            }
        }

        return g;
    }

    private static long unitFactorial(long n, int p, long mod, long g) {
        long res = 1 % mod;
        long m = mod;
        long x = n;
        while (x > 0) {
            long q = x / m;
            long r = x % m;
            if (q > 0) {
                res = mulMod(res, modPow(g, q, mod), mod);
            }
            res = mulMod(res, partialExcludingP(r, p, mod), mod);
            x /= p;
        }
        return res;
    }

    private static long partialExcludingP(long r, int p, long mod) {
        long prod = 1 % mod;
        for (long i = 1; i <= r; i++) {
            if (i % p != 0) {
                prod = (prod * i) % mod;
            }
        }

        return prod;
    }

    private static long modPow(long a, long e, long mod) {
        long x = 1 % mod;
        long base = a % mod;
        long exp =e;
        while (exp > 0) {
            if ((exp & 1L) == 1L) {
                x = mulMod(x, base, mod);
            }
            base = mulMod(base, base, mod);
            exp >>= 1;
        }
        return x;
    }

    private static long mulMod(long a, long b, long mod) {
        return ((a % mod) * (b % mod)) % mod;
    }

    private static long crtCombine(long a1, long m1, long a2, long m2) {
        long k = ((a2 - a1) % m2 + m2) % m2;
        long inv = modInverse(m1 % m2, m2);
        long t = mulMod(k, inv, m2);
        return a1 + m1 * t;
    }

    private static long modInverse(long a, long mod) {
        long[] eg = extGcd(a, mod);
        long x = eg[0];
        long g = eg[2];
        if (g != 1 && g != -1) {
            throw new ArithmeticException("no inverse");
        }
        long inv = x % mod;
        if (inv < 0) {
            inv += mod;
        }

        return inv;
    }

    private static long[] extGcd(long a, long b) {
        long oldR = a;
        long r = b;
        long oldS = 1;
        long s = 0;
        long oldT = 0;
        long t = 1;
        while (r != 0) {
            long q = oldR / r;
            long nr = oldR - q * r;
            oldR = r;
            r = nr;
            long ns = oldS - q * s;
            oldS = s;
            s = ns;
            long nt = oldT - q * t;
            oldT = t;
            t = nt;
        }
        return new long[]{oldS, oldT, oldR};
    }
}