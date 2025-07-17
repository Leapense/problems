import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(reader.readLine());
        int[] prices = new int[n];
        StringTokenizer tokenizer = new StringTokenizer(reader.readLine());
        for (int i = 0; i < n; i++) 
        {
            prices[i] = Integer.parseInt(tokenizer.nextToken());
        }

        long profit = calculateMaxProfit(prices);
        System.out.print(profit);
    }

    private static long calculateMaxProfit(int[] prices) {
        long totalProfit = 0L;
        int maxFuturePrice = 0;
        for (int i = prices.length - 1; i >= 0; i--) {
            int currentPrice = prices[i];
            if (currentPrice > maxFuturePrice) {
                maxFuturePrice = currentPrice;
            } else {
                totalProfit += (maxFuturePrice - currentPrice);
            }
        }

        return totalProfit;
    }
}