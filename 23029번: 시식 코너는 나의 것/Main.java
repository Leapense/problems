import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] food = new int[N + 1];
        for (int i = 1; i <= N; i++) {
            food[i] = sc.nextInt();
        }

        long[][] dp = new long[N + 1][3];

        dp[1][0] = 0;
        dp[1][1] = food[1];
        dp[1][2] = 0;

        for (int i = 2; i <= N; i++) {
            dp[i][0] = Math.max(dp[i - 1][0], Math.max(dp[i - 1][1], dp[i - 1][2]));
            dp[i][1] = dp[i - 1][0] + food[i];
            dp[i][2] = dp[i - 1][1] + food[i] / 2;
        }

        long answer = Math.max(dp[N][0], Math.max(dp[N][1], dp[N][2]));
        System.out.println(answer);
    }
}