import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main
{
    private static final int MOD = 2010;

    public static void main(String[] args) throws IOException {
        try (BufferedReader reader = new BufferedReader(new InputStreamReader(System.in))) {
            int n = Integer.parseInt(reader.readLine().trim());
            long result = 0L;

            for (int i = 1; i <= n; i++) {
                for (int s = 1; s <= i; s++) {
                    int d = gcd(s, i);
                    long sAll = ((long) (s - 1) * (i - 1) + d - 1) / 2 + s;
                    long sPartial = floorSum(s - 1, i, s, s);
                    long tSi = sAll - sPartial;

                    result = (result + (tSi % MOD)) % MOD;
                }
            }

            System.out.println(result);
        }
    }

    private static long floorSum(long n, long m, long a, long b) {
        long ans = 0L;

        while (true) {
            if (a >= m) {
                ans += (n - 1) * n * (a / m) / 2;
                a %= m;
            }
            if (b >= m) {
                ans += n * (b / m);
                b %= m;
            }
            long yMax = a * n + b;
            if (yMax < m) {
                break;
            }

            long newN = yMax / m;
            b = yMax % m;
            long temp = m;
            m = a;
            a = temp;
            n = newN;
        }

        return ans;
    }

    private static int gcd(int a, int b) {
        while (b != 0) {
            int tmp = a % b;
            a = b;
            b = tmp;
        }

        return a;
    }
}