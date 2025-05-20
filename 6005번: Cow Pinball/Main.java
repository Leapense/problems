import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int R = Integer.parseInt(br.readLine());

        int[][] triangle = new int[R][];
        int[][] dp = new int[R][];

        for (int i = 0; i < R; i++) {
            triangle[i] = new int[i + 1];
            dp[i] = new int[i + 1];
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j <= i; j++) {
                triangle[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        if (R == 0) {
            System.out.println(0);
            return;
        }

        dp[0][0] = triangle[0][0];

        for (int i = 1; i < R; i++) {
            for (int j = 0; j <= i; j++) {
                int current_value = triangle[i][j];
                int max_prev_score;

                if (j == 0) {
                    max_prev_score = dp[i - 1][0];
                } else if (j == i) {
                    max_prev_score = dp[i - 1][j - 1];
                } else {
                    max_prev_score = Math.max(dp[i - 1][j - 1], dp[i - 1][j]);
                }

                dp[i][j] = current_value + max_prev_score;
            }
        }

        int max_total_score = dp[R - 1][0];

        for (int j = 1; j < R; j++) {
            if (dp[R - 1][j] > max_total_score) {
                max_total_score = dp[R - 1][j];
            }
        }

        System.out.println(max_total_score);
    }
}