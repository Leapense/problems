import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    static class Fraction {
        BigInteger num, den;

        Fraction(BigInteger num, BigInteger den) {
            if (den.signum() < 0) {
                num = num.negate();
                den = den.negate();
            }

            BigInteger g = num.gcd(den);
            if (g.equals(BigInteger.ZERO)) {
                this.num = num;
                this.den = den;
            } else {
                this.num = num.divide(g);
                this.den = den.divide(g);
            }
        }

        Fraction(long num, long den) {
            this(BigInteger.valueOf(num), BigInteger.valueOf(den));
        }

        Fraction add(Fraction other) {
            BigInteger n = this.num.multiply(other.den).add(other.num.multiply(this.den));
            BigInteger d = this.den.multiply(other.den);
            return new Fraction(n, d);
        }

        Fraction subtract(Fraction other) {
            BigInteger n = this.num.multiply(other.den).subtract(other.num.multiply(this.den));
            BigInteger d = this.den.multiply(other.den);
            return new Fraction(n, d);
        }

        Fraction multiply(Fraction other) {
            BigInteger n = this.num.multiply(other.num);
            BigInteger d = this.den.multiply(other.den);
            return new Fraction(n, d);
        }

        Fraction divide(Fraction other) {
            BigInteger n = this.num.multiply(other.den);
            BigInteger d = this.den.multiply(other.num);
            return new Fraction(n, d);
        }

        public String toString() {
            if (den.equals(BigInteger.ONE)) {
                return num.toString();
            }
            return num + "/" + den;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        int maxM = 0;
        int[] ms = new int[T];
        int[] ks = new int[T];

        for (int i = 0; i < T; i++) {
            ms[i] = sc.nextInt();
            ks[i] = sc.nextInt();
            if (ms[i] > maxM)
                maxM = ms[i];
        }

        Fraction[][] dp = new Fraction[maxM + 1][maxM + 2];
        dp[0][1] = new Fraction(1, 1);
        for (int j = 2; j <= maxM + 1; j++) {
            dp[0][j] = new Fraction(0, 1);
        }

        for (int m = 1; m <= maxM; m++) {
            dp[m] = new Fraction[m + 2];
            Fraction sum = new Fraction(0, 1);
            for (int j = 2; j <= m + 1; j++) {
                Fraction coef = new Fraction(m, j);
                dp[m][j] = coef.multiply(dp[m - 1][j - 1]);
                sum = sum.add(dp[m][j]);
            }

            dp[m][1] = new Fraction(1, 1).subtract(sum);
        }

        for (int i = 0; i < T; i++) {
            System.out.println(dp[ms[i]][ks[i]]);
        }

        sc.close();
    }
}