import java.util.Scanner;

public class Main
{
    public static void main(String[] args)
    {
        try (Scanner scanner = new Scanner(System.in)) {
            int testCases = scanner.nextInt();
            for (int i = 0; i < testCases; i++) {
                long numerator = scanner.nextLong();
                long denominator = scanner.nextLong();
                long answer = computeLastUnitFractionDenominator(numerator, denominator);
                System.out.println(answer);
            }
        }
    }

    private static long computeLastUnitFractionDenominator(long numerator, long denominator) {
        long lastDenominator = 0L;

        while (numerator != 0L)
        {
            long x = ceil(denominator, numerator);
            long newNumerator = numerator * x - denominator;
            long newDenominator = denominator * x;

            if (newNumerator == 0L) {
                lastDenominator = x;
                break;
            }

            long gcdValue = gcd(newNumerator, newDenominator);
            numerator = newNumerator / gcdValue;
            denominator = newDenominator / gcdValue;
            lastDenominator = x;
        }
        return lastDenominator;
    }

    private static long ceil(long b, long a) {
        return (b + a - 1) / a;
    }

    private static long gcd(long p, long q) {
        while (q != 0L) {
            long r = p % q;
            p = q;
            q = r;
        }

        return p;
    }
}