import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main
{
    private static final int MAX_N = 76;
    private static final long[] dp = new long[MAX_N + 1];

    public static void main(String[] args) throws IOException
    {
        precompute();
        solve();
    }

    private static void precompute() {
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;

        for (int i = 3; i <= MAX_N; i++) {
            dp[i] = dp[i - 2] + dp[i - 3];
        }
    }

    private static void solve() throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int caseNumber = 1;
        String line;

        while ((line = reader.readLine()) != null) {
            int n = Integer.parseInt(line.trim());
            if (n == 0) {
                break;
            }

            long result = calculateMixtures(n);
            System.out.println("Case #" + caseNumber + ": " + result);
            caseNumber++;
        }
    }

    private static long calculateMixtures(int n) {
        if (n <= 2) {
            return 0;
        }
        if (n == 3) {
            return 1;
        }
        return dp[n];
    }
}