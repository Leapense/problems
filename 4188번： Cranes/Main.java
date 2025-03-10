import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        for (int tc = 0; tc < t; tc++) {
            int n = sc.nextInt();
            int[] x = new int[n];
            int[] y = new int[n];
            int[] r = new int[n];

            for (int i = 0; i < n; i++) {
                x[i] = sc.nextInt();
                y[i] = sc.nextInt();
                r[i] = sc.nextInt();
            }

            int maxArea = 0;
            int totalSubsets = 1 << n;
            for (int mask = 0; mask < totalSubsets; mask++) {
                boolean valid = true;
                int area = 0;

                for (int i = 0; i < n && valid; i++) {
                    if ((mask & (1 << i)) != 0) {
                        area += r[i] * r[i];
                        for (int j = i + 1; j < n; j++) {
                            if ((mask & (1 << j)) != 0) {
                                long dx = x[i] - x[j];
                                long dy = y[i] - y[j];
                                long distSq = dx * dx + dy * dy;
                                long sumR = r[i] + r[j];
                                if (distSq <= (long) sumR * sumR) {
                                    valid = false;
                                    break;
                                }
                            }
                        }
                    }
                }

                if (valid && area > maxArea) {
                    maxArea = area;
                }
            }

            System.out.println(maxArea);
        }

        sc.close();
    }
}