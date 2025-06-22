import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main
{
    public static void main(String[] args) throws IOException {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int h = Integer.parseInt(st.nextToken());
            int w = Integer.parseInt(st.nextToken());

            int[][] imageB1 = readImage(br, h, w);
            int[][] imageB2 = readImage(br, h, w);

            long result = solveQuilting(h, w, imageB1, imageB2);
            System.out.println(result);
        }
    }

    private static int[][] readImage(BufferedReader br, int h, int w) throws IOException {
        int[][] image = new int[h][w];
        for (int i = 0; i < h; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < w; j++) {
                image[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        return image;
    }

    private static long solveQuilting(int h, int w, int[][] b1, int[][] b2) {
        long[][] cost = new long[h][w];
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                long diff = (long) b1[i][j] - b2[i][j];
                cost[i][j] = diff * diff;
            }
        }

        long[][] dp = new long[h][w];

        for (int j = 0; j < w; j++) {
            dp[0][j] = cost[0][j];
        }

        for (int i = 1; i < h; i++) {
            for (int j = 0; j < w; j++) {
                long minPrevCost;

                if (j == 0) {
                    minPrevCost = dp[i - 1][j];
                    if (w > 1) {
                        minPrevCost = Math.min(minPrevCost, dp[i - 1][j + 1]);
                    }
                } else if (j == w - 1) {
                    minPrevCost = Math.min(dp[i - 1][j], dp[i - 1][j - 1]);
                } else {
                    minPrevCost = Math.min(dp[i - 1][j - 1], Math.min(dp[i - 1][j], dp[i - 1][j + 1]));
                }

                dp[i][j] = cost[i][j] + minPrevCost;
            }
        }

        long minTotalCost = Long.MAX_VALUE;
        for (int j = 0; j < w; j++) {
            if (dp[h - 1][j] < minTotalCost) {
                minTotalCost = dp[h - 1][j];
            }
        }

        return minTotalCost;
    }
}