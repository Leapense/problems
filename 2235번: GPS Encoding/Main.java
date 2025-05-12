import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        String perm;
        int problemCount = 0;
        StringBuilder output = new StringBuilder();

        while (!(perm = in.readLine()).equals("#")) {
            problemCount++;
            char[] alpha = perm.toCharArray();
            output.append("Problem ").append(problemCount).append("\n");

            String digits;
            while (!(digits = in.readLine()).equals("0")) {
                int n = digits.length();
                String[] dp = new String[n + 1];
                dp[n] = "";

                for (int i = n - 1; i >= 0; i--) {
                    int d1 = digits.charAt(i) - '0';
                    String best = alpha[d1] + dp[i + 1];

                    if (i + 1 < n) {
                        int d2 = (digits.charAt(i) - '0') * 10 + (digits.charAt(i + 1) - '0');
                        if (d2 >= 0 && d2 <= 25) {
                            String cand = alpha[d2] + dp[i + 2];
                            if (cand.length() < best.length()
                                    || (cand.length() == best.length() && cand.compareTo(best) > 0)) {
                                best = cand;
                            }
                        }
                    }

                    dp[i] = best;
                }

                output.append(dp[0]).append("\n");
            }

            output.append("\n");
        }

        System.out.print(output.toString());
    }
}