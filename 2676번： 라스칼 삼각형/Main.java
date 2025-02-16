import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int T = sc.nextInt();
        StringBuilder sb = new StringBuilder();

        while (T-- > 0) {
            long n = sc.nextLong();
            long m = sc.nextLong();

            long k = Math.min(m, n - m);
            long result = k * (n - k) + 1;

            sb.append(result).append("\n");
        }

        System.out.print(sb);
        sc.close();
    }
}