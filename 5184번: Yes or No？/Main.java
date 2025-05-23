import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int K = sc.nextInt();

        for (int dataset = 1; dataset <= K; dataset++) {
            int l = sc.nextInt();
            int r = sc.nextInt();
            int n = sc.nextInt();

            double[] y = new double[n];
            double base = 0;
            double[] diff = new double[n];
            for (int i = 0; i < n; i++) {
                y[i] = sc.nextDouble();
                base += (1 - y[i]);
                diff[i] = 2 * y[i] - 1;
            }

            double[][] dp = new double[n + 1][n + 1];
            for (int i = 0; i <= n; i++) {
                Arrays.fill(dp[i], -1e9);
            }

            dp[0][0] = 0;
            for (int i = 1; i <= n; i++) {
                for (int k = 0; k <= i; k++) {
                    dp[i][k] = dp[i - 1][k];
                    if (k > 0)
                        dp[i][k] = Math.max(dp[i][k], dp[i - 1][k - 1] + diff[i - 1]);
                }
            }

            double ans = -1e9;
            for (int k = l; k <= r; k++) {
                ans = Math.max(ans, dp[n][k]);
            }

            ans = base + ans;
            System.out.printf("Data Set %d:\n%.2f\n", dataset, ans);
        }
    }
}