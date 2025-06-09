import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Main {
    private static final String PATTERN = "welcome to code jam";
    private static final int M = PATTERN.length();
    private static final int MOD = 10_000;

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int testCases = Integer.parseInt(reader.readLine().trim());

        for (int caseNum = 1; caseNum <= testCases; caseNum++) {
            String text = reader.readLine();
            int count = countSubsequences(text);
            String formatted = String.format("%04d", count);
            System.out.println("Case #" + caseNum + ": " + formatted);
        }
    }

    private static int countSubsequences(String text) {
        int N = text.length();
        int[][] dp = new int[M + 1][N + 1];

        for (int j = 0; j <= N; j++) {
            dp[0][j] = 1;
        }

        for (int i = 1; i <= M; i++) {
            dp[i][0] = 0;
            char pc = PATTERN.charAt(i - 1);
            for (int j = 1; j <= N; j++) {
                dp[i][j] = dp[i][j - 1];
                if (pc == text.charAt(j - 1)) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
                }
            }
        }

        return dp[M][N];
    }
}