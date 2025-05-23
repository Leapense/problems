import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long[] valid = { 4L, 16L, 121L, 529L, 4096L, 17956L, 139129L, 609961L, 4726276L, 20720704L, 160552000L,
                703321500L };

        int tc = 1;
        while (true) {
            long a = sc.nextLong();
            long b = sc.nextLong();
            if (a == 0 && b == 0)
                break;

            int count = 0;
            for (long num : valid) {
                if (num > a && num < b)
                    count++;
            }

            System.out.println("Case " + tc + ": " + count);
            tc++;
        }

        sc.close();
    }
}