import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int k = 0; k < t; k++) {
            int L = sc.nextInt();
            int H = sc.nextInt();

            boolean found = false;
            StringBuilder sb = new StringBuilder();

            for (int i = L; i <= H; i++) {
                if (i <= 0)
                    continue;
                int cnt = countDiv(i);
                if (isPrime(cnt)) {
                    sb.append(i).append(" ");
                    found = true;
                }
            }

            if (!found)
                System.out.println(-1);
            else
                System.out.println(sb.toString().trim());
        }
    }

    static int countDiv(int n) {
        int count = 0;
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                if (i * i == n)
                    count++;
                else
                    count += 2;
            }
        }

        return count;
    }

    static boolean isPrime(int n) {
        if (n < 2)
            return false;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0)
                return false;
        }

        return true;
    }
}