import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.math.BigInteger;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        long n = Long.parseLong(br.readLine().trim());
        if (n < 10) {
            System.out.println(n);
            return;
        }

        String s = Long.toString(n);
        int m = s.length();
        long total = 0;

        for (int len = 1; len < m; ++len) {
            int k = (len + 1) / 2;
            total += 9L * pow10(k - 1);
        }

        int k = (m + 1) / 2;
        long firstHalf = Long.parseLong(s.substring(0, k));
        long minHalf = pow10(k - 1);
        long sameLen = firstHalf - minHalf + 1;
        long pal = buildPalindrome(firstHalf, m % 2 == 0);
        if (pal > n)
            sameLen--;
        total += sameLen;
        System.out.println(total);
    }

    private static long pow10(int exp) {
        long v = 1;
        while (exp-- > 0)
            v *= 10;
        return v;
    }

    private static long buildPalindrome(long half, boolean even) {
        long res = half;
        if (!even)
            half /= 10;
        while (half > 0) {
            res = res * 10 + (half % 10);
            half /= 10;
        }
        return res;
    }
}