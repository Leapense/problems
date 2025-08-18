import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main
{
    public static void main(String[] args) throws Exception
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine().trim());
        String s = br.readLine().trim();
        int len = s.length();
        long[] dp = new long[len + 1];
        dp[len] = 1L;
        for (int i = len - 1; i >= 0; i--) {
            long ways = dp[i + 1];
            if (i + 1 < len) {
                char c1 = s.charAt(i);
                char c2 = s.charAt(i + 1);
                if (c1 != '0') {
                    int value = (c1 - '0') * 10 + (c2 - '0');
                    if (value >= 10 && value <= 35 && value - 10 < n) {
                        ways += dp[i + 2];
                    }
                }
            }
            dp[i] = ways;
        }

        System.out.println(dp[0]);
    }
}