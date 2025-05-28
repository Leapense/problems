import java.math.BigDecimal;
import java.math.RoundingMode;
import java.util.Scanner;

public final class Main
{
    private static final int MAX_MONTHS = 1_200;
    private Main() {

    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int testCases = sc.nextInt();
        for (int t = 0; t < testCases; t++) {
            BigDecimal ratePercent = sc.nextBigDecimal();
            long balanceCents = toCents(sc.nextBigDecimal());
            long monthlyPaymentCents = toCents(sc.nextBigDecimal());
            String result = calculateMonthsToRepay(ratePercent, balanceCents, monthlyPaymentCents);
            System.out.println(result);
        }

        sc.close();
    }

    private static long toCents(BigDecimal amountDollar) {
        return amountDollar
            .multiply(BigDecimal.valueOf(100))
            .setScale(0, RoundingMode.HALF_UP)
            .longValueExact();
    }

    private static String calculateMonthsToRepay(BigDecimal ratePercent, long initialBalanceCents, long monthlyPaymentCents) {
        long balance = initialBalanceCents;
        for (int month = 1; month <= MAX_MONTHS; month++) {
            BigDecimal rawInterest = BigDecimal.valueOf(balance).multiply(ratePercent).divide(BigDecimal.valueOf(100), 10, RoundingMode.HALF_UP);
            long interest = rawInterest.setScale(0, RoundingMode.HALF_UP).longValueExact();

            balance += interest;

            if (monthlyPaymentCents <= interest) {
                return "impossible";
            }

            balance -= monthlyPaymentCents;
            if (balance <= 0) {
                return String.valueOf(month);
            }
        }

        return "impossible";
    }
}