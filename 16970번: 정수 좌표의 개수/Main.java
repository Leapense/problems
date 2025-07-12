import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int k = sc.nextInt();

        sc.close();
        int c = k - 1;
        long count = 0;
        int width = n + 1;
        int height = m + 1;
        for (int dx = 1; dx <= n; dx++) {
            if (dx == c) {
                count += (long)(width - dx) * height;
            }
        }
        for (int dy = 1; dy <= m; dy++) {
            if (dy == c) {
                count += (long)width * (height - dy);
            }
        }
        for (int dx = 1; dx <= n; dx++) {
            for (int dy = 1; dy <= m; dy++) {
                if (gcd(dx, dy) == c) {
                    count += 2L * (width - dx) * (height - dy);
                }
            }
        }

        System.out.println(count);
    }

    private static int gcd(int a, int b) {
        while (b != 0) {
            int temp = a % b;
            a = b;
            b = temp;
        }

        return a;
    }
}