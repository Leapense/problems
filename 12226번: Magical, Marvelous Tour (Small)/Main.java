import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for (int t = 1; t <= T; t++) {
            int N = sc.nextInt();
            long p = sc.nextLong(), q = sc.nextLong(), r = sc.nextLong(), s = sc.nextLong();
            long[] devices = new long[N];
            for (int i = 0; i < N; i++) {
                devices[i] = ((i * p + q) % r) + s;
            }
            long[] prefix = new long[N + 1];
            for (int i = 0; i < N; i++) {
                prefix[i + 1] = prefix[i] + devices[i];
            }
            long total = prefix[N];
            long best = Long.MAX_VALUE;
            for (int a = 0; a < N; a++) {
                int low = a, high = N - 1;
                while (low < high) {
                    int mid = (low + high) / 2;
                    long left = prefix[a];
                    long midSum = prefix[mid + 1] - prefix[a];
                    long right = total - prefix[mid + 1];
                    long midSumNext = prefix[mid + 2] - prefix[a];
                    long rightNext = total - prefix[mid + 2];
                    long currentMax = Math.max(left, Math.max(midSum, right));
                    long nextMax = Math.max(left, Math.max(midSumNext, rightNext));
                    if (nextMax > currentMax) {
                        high = mid;
                    } else {
                        low = mid + 1;
                    }
                }
                for (int b = Math.max(a, low - 1); b <= Math.min(N - 1, low + 1); b++) {
                    long left = prefix[a];
                    long midSum = prefix[b + 1] - prefix[a];
                    long right = total - prefix[b + 1];
                    long maxi = Math.max(left, Math.max(midSum, right));
                    best = Math.min(best, maxi);
                }
            }
            double probability = (double) (total - best) / total;
            System.out.printf("Case #%d: %.10f\n", t, probability);
        }
        sc.close();
    }
}
