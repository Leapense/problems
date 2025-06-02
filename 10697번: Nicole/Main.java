import java.util.*;
import java.io.*;

public class Main
{
    private static final int MAX_N = 20;

    public static void main(String ... args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();

        for (int testCase = 1; testCase <= T; testCase++) {
            int n = sc.nextInt();
            int m = sc.nextInt();
            int[] satisfaction = new int[n];
            for (int i = 0; i < n; i++)
            {
                satisfaction[i] = sc.nextInt();
            }

            boolean[][] adj = new boolean[n][n];
            for (int i = 0; i < m; i++) {
                int u = sc.nextInt() - 1;
                int v = sc.nextInt() - 1;
                adj[u][v] = true;
                adj[v][u] = true;
            }

            int maxSum = -1;
            int totalMasks = 1 << n;
            for (int mask = 0; mask < totalMasks; mask++) {
                if (Integer.bitCount(mask) < 2) {
                    continue;
                }

                boolean valid = true;
                outer:
                for (int i = 0; i < n; i++) {
                    if ((mask & (1 << i)) != 0) {
                        for (int j = i + 1; j < n; j++) {
                            if ((mask & (1 << j)) != 0 && adj[i][j]) {
                                valid = false;
                                break outer;
                            }
                        }
                    }
                }
                if (!valid) {
                    continue;
                }

                int sum = 0;
                for (int i = 0; i < n; i++) {
                    if ((mask & (1 << i)) != 0) {
                        sum += satisfaction[i];
                    }
                }

                maxSum = Math.max(maxSum, sum);
            }
            System.out.println("Case " + testCase + ": " + maxSum);
        }

        sc.close();
    }
}