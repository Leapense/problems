import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        long l = Long.parseLong(br.readLine().trim());
        long r = Long.parseLong(br.readLine().trim());

        int limit = (int)Math.sqrt(r);
        List<Integer> primes = sievePrimes(limit);

        List<Long> sqf = new ArrayList<>();
        for (long x = l; x <= r; x++) {
            if (isSquareFree(x, primes)) {
                sqf.add(x);
            }
        }

        long ans = 0;
        for (int i = 0; i < sqf.size(); i++) {
            for (int j = i + 1; j < sqf.size(); j++) {
                if (gcd(sqf.get(i), sqf.get(j)) == 1L) {
                    ans++;
                }
            }
        }

        System.out.println(ans);
    }

    private static List<Integer> sievePrimes(int n) {
        boolean[] comp = new boolean[n + 1];
        List<Integer> primes = new ArrayList<>();
        for (int i = 2; i * i <= n; i++) {
            if (!comp[i]) {
                for (int j = i * i; j <= n; j += i) comp[j] = true;
            }
        }
        for (int i = 2; i <= n; i++) {
            if (!comp[i]) primes.add(i);
        }
        return primes;
    }

    private static boolean isSquareFree(long x, List<Integer> primes) {
        long t = x;
        for (int p : primes) {
            long pp = 1L * p * p;
            if (pp > t) break;
            if (t % pp == 0) return false;
            if (t % p == 0) {
                while(t % p == 0) t /= p;
            }
        }
        return true;
    }

    private static long gcd(long a, long b) {
        while (b != 0) {
            long t = a % b;
            a = b;
            b = t;
        }

        return Math.abs(a);
    } 
}