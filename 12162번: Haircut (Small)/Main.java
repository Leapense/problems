import java.util.Scanner;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public final class Main
{
    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(new BufferedReader(new InputStreamReader(System.in)))) {
            int testCases = scanner.nextInt();
            for (int i = 1; i <= testCases; ++i) {
                int numBarbers = scanner.nextInt();
                long myPlaceInLine = scanner.nextLong();
                int[] haircutTimes = new int[numBarbers];
                for (int j = 0; j < numBarbers; j++) {
                    haircutTimes[j] = scanner.nextInt();
                }

                System.out.println("Case #" + i + ": " + solve(numBarbers, myPlaceInLine, haircutTimes));
            }
        }
    }

    private static int solve(int numBarbers, long myPlaceInLine, int[] haircutTimes) {
        if (myPlaceInLine <= numBarbers) {
            return (int) myPlaceInLine;
        }

        long low = 0;
        long high = 100_001L * 1_000_000_000L;
        long finishTime = -1;

        while (low <= high) {
            long mid = low + (high - low) / 2;
            long customersServed = countCustomersServedBy(mid, numBarbers, haircutTimes);

            if (customersServed >= myPlaceInLine) {
                finishTime = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        long servedBefore = countCustomersServedBy(finishTime - 1, numBarbers, haircutTimes);
        long remainingCustomers = myPlaceInLine - servedBefore;

        for (int i = 0; i < numBarbers; i++) {
            if (finishTime % haircutTimes[i] == 0) {
                remainingCustomers--;
                if (remainingCustomers == 0) {
                    return i + 1;
                }
            }
        }
        return -1;
    }

    private static long countCustomersServedBy(long time, int numBarbers, int[] haircutTimes) {
        if (time < 0) {
            return 0;
        }

        long totalServed = 0;
        for (int i = 0; i < numBarbers; i++) {
            totalServed += (time / haircutTimes[i]) + 1;
        }

        return totalServed;
    }
}