import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        String S = sc.next();
        int len = S.length();

        int[] dp = new int[len + 1];
        Arrays.fill(dp, Integer.MAX_VALUE);
        dp[0] = 0;

        for (int i = 0; i < len; i++) {
            if (dp[i] == Integer.MAX_VALUE)
                continue;

            for (int j = 1; j <= 3; j++) {
                if (i + j > len)
                    break;
                String sub = S.substring(i, i + j);
                if (sub.charAt(0) == '0' && sub.length() > 1)
                    continue;

                int num = Integer.parseInt(sub);

                if (num >= 1 && num <= 641) {
                    dp[i + j] = Math.min(dp[i + j], dp[i] + 1);
                }
            }
        }

        System.out.println(dp[len]);
        sc.close();
    }
}