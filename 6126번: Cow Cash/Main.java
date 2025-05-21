import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        try (BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            final int coinTypes = Integer.parseInt(st.nextToken());
            final int target = Integer.parseInt(st.nextToken());

            final int[] coins = new int[coinTypes];
            for (int i = 0; i < coinTypes; i++) {
                coins[i] = Integer.parseInt(br.readLine().trim());
            }

            final long[] ways = new long[target + 1];
            ways[0] = 1L;

            for (int coin : coins) {
                for (int amount = coin; amount <= target; amount++) {
                    ways[amount] += ways[amount - coin];
                }
            }

            System.out.println(ways[target]);
        }
    }
}