import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    static final int MOD = 1_000_000_007;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] nm = br.readLine().split(" ");
        int n = Integer.parseInt(nm[0]);
        int m = Integer.parseInt(nm[1]);

        long[][] dp = new long[n + 1][m + 1];

        dp[1][1] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (i == 1 && j == 1) continue;

                long fromTop = dp[i-1][j];
                long fromLeft = dp[i][j-1];
                long fromDiag = dp[i-1][j-1];

                dp[i][j] = (fromTop + fromLeft + fromDiag) % MOD;
            }
        }

        System.out.println(dp[n][m] % MOD);
    }
}