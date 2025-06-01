import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main
{
    private static final int UPPER_BOUND = 10_000_000;

    public static void main(String[] args) throws IOException
    {
        boolean[] isPrime = buildPrimeTable(UPPER_BOUND);

        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            StringBuilder output = new StringBuilder();
            String line;

            while ((line = br.readLine()) != null) {
                int n = Integer.parseInt(line.trim());
                if (n == 0) {
                    break;
                }

                output.append(countGoldbachPartitions(n, isPrime)).append('\n');
            }

            System.out.print(output.toString());
        }
    }

    private static boolean[] buildPrimeTable(int limit) {
        boolean[] prime = new boolean[limit + 1];
        if (limit >= 2) {
            Arrays.fill(prime, true);
            prime[0] = false;
            prime[1] = false;
            int sqrt = (int) Math.sqrt(limit);

            for (int p = 2; p <= sqrt; p++) {
                if (prime[p]) {
                    for (int multiple = p * p; multiple <= limit; multiple += p) {
                        prime[multiple] = false;
                    }
                }
            }
        }

        return prime;
    }

    private static int countGoldbachPartitions(int n, boolean[] prime) {
        int count = 0;
        for (int p = 2; p <= n / 2; p++) {
            if (prime[p] && prime[n - p]) {
                count++;
            }
        }

        return count;
    }
}