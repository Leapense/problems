import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();

        while (t-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int l1 = Integer.parseInt(st.nextToken());
            int l2 = Integer.parseInt(st.nextToken());
            int s1 = Integer.parseInt(st.nextToken());
            int s2 = Integer.parseInt(st.nextToken());

            int[] pass1 = new int[n - 1];
            int[] dribble1 = new int[n - 1];
            int[] pass2 = new int[n - 1];
            int[] dribble2 = new int[n - 1];

            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < n - 1; i++) {
                pass1[i] = Integer.parseInt(st.nextToken());
            }

            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < n - 1; i++) {
                dribble1[i] = Integer.parseInt(st.nextToken());
            }

            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < n - 1; i++) {
                pass2[i] = Integer.parseInt(st.nextToken());
            }

            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < n - 1; i++) {
                dribble2[i] = Integer.parseInt(st.nextToken());
            }

            int[] dp1 = new int[n];
            int[] dp2 = new int[n];
            Arrays.fill(dp1, Integer.MAX_VALUE);
            Arrays.fill(dp2, Integer.MAX_VALUE);

            dp1[0] = l1;
            dp2[0] = l2;

            for (int i = 0; i < n - 1; i++) {
                if (dp1[i] != Integer.MAX_VALUE) {
                    dp1[i + 1] = Math.min(dp1[i + 1], dp1[i] + dribble1[i]);
                    dp2[i + 1] = Math.min(dp2[i + 1], dp1[i] + pass1[i]);
                }
                if (dp2[i] != Integer.MAX_VALUE) {
                    dp2[i + 1] = Math.min(dp2[i + 1], dp2[i] + dribble2[i]);
                    dp1[i + 1] = Math.min(dp1[i + 1], dp2[i] + pass2[i]);
                }
            }

            int ans = Math.min(dp1[n - 1] + s1, dp2[n - 1] + s2);
            sb.append(ans).append("\n");
        }

        System.out.print(sb);
    }
}