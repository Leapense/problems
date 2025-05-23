import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for (int t = 0; t < T; t++) {
            long n = sc.nextLong();
            long x = sc.nextLong();
            long y = sc.nextLong();
            int w = sc.nextInt();
            int h = sc.nextInt();

            for (long i = y; i < y + h; i++) {
                StringBuilder sb = new StringBuilder();
                for (long j = x; j < x + w; j++) {
                    sb.append((Long.bitCount(i & j) & 1) == 0 ? "1" : "-1");
                    if (j < x + w - 1)
                        sb.append(" ");
                }

                System.out.println(sb.toString());
            }

            System.out.println();
        }

        sc.close();
    }
}