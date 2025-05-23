import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        while (true) {
            int n = Integer.parseInt(br.readLine().trim());
            if (n == 0)
                break;
            long maxSum = Long.MIN_VALUE;
            long currentSum = 0;
            for (int i = 0; i < n; i++) {
                int profit = Integer.parseInt(br.readLine().trim());
                if (i == 0) {
                    currentSum = profit;
                    maxSum = profit;
                } else {
                    currentSum = Math.max(profit, currentSum + profit);
                    maxSum = Math.max(maxSum, currentSum);
                }
            }
            out.println(maxSum);
        }
        out.flush();
    }
}