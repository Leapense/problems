import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int C = sc.nextInt();
        int H = sc.nextInt();
        int[] dp = new int[C + 1];
        for (int i = 0; i < H; i++) {
            int bale = sc.nextInt();
            for (int j = C; j >= bale; j--) {
                dp[j] = Math.max(dp[j], dp[j - bale] + bale);
            }
        }

        System.out.println(dp[C]);
    }
}