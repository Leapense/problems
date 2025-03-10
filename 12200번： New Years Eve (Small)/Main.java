import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for (int t = 1; t <= T; t++) {
            int B = sc.nextInt();
            int L = sc.nextInt();
            int N = sc.nextInt();
            double[][][] dp = new double[L + 2][][];
            for (int i = 1; i <= L + 1; i++) {
                dp[i] = new double[i + 1][i + 1];
            }

            dp[1][1][1] = B * 750.0;
            for (int level = 1; level < L; level++) {
                for (int r = 1; r <= level; r++) {
                    for (int c = 1; c <= r; c++) {
                        double amount = dp[level][r][c];
                        if (amount > 250.0) {
                            double extra = amount - 250.0;
                            double distribute = extra / 3.0;
                            dp[level + 1][r][c] += distribute;
                            dp[level + 1][r + 1][c] += distribute;
                            dp[level + 1][r + 1][c + 1] += distribute;
                        }
                    }
                }
            }

            int targetRow = 0, targetCol = 0, remaining = N;
            for (int r = 1; r <= L; r++) {
                if (remaining <= r) {
                    targetRow = r;
                    targetCol = remaining;
                    break;
                }

                remaining -= r;
            }

            double res = Math.min(250.0, dp[L][targetRow][targetCol]);
            System.out.printf("Case #%d: %.7f\n", t, res);
        }

        sc.close();
    }
}