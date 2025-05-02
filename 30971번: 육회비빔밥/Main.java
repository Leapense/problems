import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());
        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        int[] A = new int[N], B = new int[N], C = new int[N];
        st = new StringTokenizer(in.readLine());
        for (int i = 0; i < N; i++)
            A[i] = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(in.readLine());
        for (int i = 0; i < N; i++)
            B[i] = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(in.readLine());
        for (int i = 0; i < N; i++)
            C[i] = Integer.parseInt(st.nextToken());

        int FULL = (1 << N) - 1;
        int INF_NEG = Integer.MIN_VALUE / 2;

        int[][] dp = new int[1 << N][N];
        for (int[] row : dp)
            Arrays.fill(row, INF_NEG);

        for (int i = 0; i < N; i++) {
            dp[1 << i][i] = 0;
        }

        for (int mask = 1; mask <= FULL; mask++) {
            for (int last = 0; last < N; last++) {
                if (dp[mask][last] <= INF_NEG)
                    continue;

                for (int nxt = 0; nxt < N; nxt++) {
                    int bit = 1 << nxt;
                    if ((mask & bit) != 0)
                        continue;

                    if ((long) C[last] * C[nxt] > K)
                        continue;
                    int nextMask = mask | bit;
                    int gain = A[last] * B[nxt];
                    dp[nextMask][nxt] = Math.max(dp[nextMask][nxt], dp[mask][last] + gain);
                }
            }
        }

        int ans = INF_NEG;
        for (int i = 0; i < N; i++) {
            ans = Math.max(ans, dp[FULL][i]);
        }

        System.out.println(ans < 0 ? -1 : ans);
    }
}