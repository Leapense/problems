import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int m = Integer.parseInt(st.nextToken());
            int n = Integer.parseInt(st.nextToken());

            long[][] dp = new long[n + 1][m + 1];
            long[][] prefixSum = new long[n + 1][m + 1];
            dp[1][1] = 1;
            for (int j = 1; j <= m; j++) {
                prefixSum[1][j] = 1;
            }

            for (int i = 2; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    long ways = 2 * prefixSum[i - 1][j] - dp[i - 1][j];
                    dp[i][j] = ways;
                    prefixSum[i][j] = prefixSum[i][j - 1] + dp[i][j];
                }
            }

            System.out.println(prefixSum[n][m]);
        }
    }
}