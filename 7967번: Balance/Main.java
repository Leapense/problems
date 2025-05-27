import java.util.Scanner;

public class Main
{
    private static int n;
    private static int[] weights;
    private static long[][] dp;
    private static int fullMask;
    
    public static void main(String[] args)
    {
        readInput();
        initializeDp();
        long result = countWays(0, 0);
        System.out.println(result);
    }

    private static void readInput()
    {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        weights = new int[n];
        for (int i = 0; i < n; i++)
        {
            weights[i] = sc.nextInt();
        }
        sc.close();
        fullMask = (1 << n) - 1;
    }

    // DP 배열을 -1로 초기화하여 미방문 상태 표시
    private static void initializeDp() {
        int maxDiff = 0;
        for (int w : weights) {
            maxDiff += w;
        }

        dp = new long[1 << n][maxDiff + 1];
        for (int mask = 0; mask < (1 << n); mask++) {
            for (int d = 0; d <= maxDiff; d++) {
                dp[mask][d] = -1L;
            }
        }
    }

    private static long countWays(int mask, int diff) {
        if (mask == fullMask) {
            return 1L;
        }
        if (dp[mask][diff] != -1L) {
            return dp[mask][diff];
        }

        long ways = 0L;
        for (int i = 0; i < n; i++) {
            int bit = 1 << i;
            if ((mask & bit) != 0) {
                continue;
            }

            int nextMask = mask | bit;
            ways += countWays(nextMask, diff + weights[i]);
            if (diff >= weights[i]) {
                ways += countWays(nextMask, diff - weights[i]);
            }
        }

        dp[mask][diff] = ways;
        return ways;
    }
}