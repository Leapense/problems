import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int K = sc.nextInt();

        int[][] pascal = new int[N + 1][N + 1];

        pascal[0][0] = 1 % K;

        for (int i = 1; i <= N; i++) {
            pascal[i][0] = 1 % K;
            pascal[i][i] = 1 % K;

            for (int j = 1; j < i; j++) {
                pascal[i][j] = (pascal[i - 1][j - 1] + pascal[i - 1][j]) % K;
            }
        }

        long count = 0;
        for (int i = 0; i <= N; i++) {
            for (int j = 0; j <= i; j++) {
                if (pascal[i][j] == 0) {
                    count++;
                }
            }
        }

        System.out.println(count);
    }
}