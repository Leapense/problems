import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main
{
    private static final int MAX_DIGITS = 8;
    private static final long LIMIT = 100_000_000L;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String input = sc.nextLine().trim();
        sc.close();

        int decimalPlaces = 0;
        String normalized = input;
        if (input.contains(".")) {
            decimalPlaces = input.length() - input.indexOf('.') - 1;
            normalized = input.replace(".", "");
        }

        long p;
        try {
            p = Long.parseLong(normalized);
        } catch (NumberFormatException e) {
            System.out.println("No solution");
            return;
        }

        long[] pow10 = new long[decimalPlaces + MAX_DIGITS + 2];
        pow10[0] = 1L;
        for (int i = 1; i < pow10.length; i++) {
            pow10[i] = pow10[i - 1] * 10L;
        }

        List<Long> solutions = new ArrayList<>();

        for (int k = 1; k <= MAX_DIGITS; k++) {
            long tenKminus1 = pow10[k - 1];
            for (int a = 1; a <= 9; a++) {
                long L = p - pow10[decimalPlaces + 1];
                long R = pow10[decimalPlaces] - p * tenKminus1;

                if (L == 0L) {
                    continue;
                }

                long numerator = a * R;
                if (numerator % L != 0) {
                    continue;
                }

                long b = numerator / L;
                if (b < 0L || b >= tenKminus1) {
                    continue;
                }

                long n = a * tenKminus1 + b;
                if (n >= LIMIT) {
                    continue;
                }

                long rotated = b * 10L + a;
                if (n * p == rotated * pow10[decimalPlaces]) {
                    solutions.add(n);
                }
            }
        }

        if (solutions.isEmpty()) {
            System.out.println("No solution");
        } else {
            Collections.sort(solutions);
            for (long number : solutions) {
                System.out.println(number);
            }
        }
    }
}