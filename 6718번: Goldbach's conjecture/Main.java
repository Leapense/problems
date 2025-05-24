import java.util.Scanner;

public class Main {
    public static boolean isPrime(int n) {
        if (n < 2)
            return false;
        if (n == 2)
            return true;
        if (n % 2 == 0)
            return false;

        for (int i = 3; i * i <= n; i += 2) {
            if (n % i == 0)
                return false;
        }

        return true;
    }

    public static int countGoldbachPairs(int n) {
        int count = 0;

        for (int p1 = 2; p1 <= n / 2; p1++) {
            if (isPrime(p1)) {
                int p2 = n - p1;
                if (isPrime(p2)) {
                    count++;
                }
            }
        }

        return count;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        while (true) {
            int n = sc.nextInt();

            if (n == 0)
                break;

            int pairCount = countGoldbachPairs(n);
            System.out.println(pairCount);
        }

        sc.close();
    }
}