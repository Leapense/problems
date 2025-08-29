import java.io.IOException;
import java.util.Arrays;

public class Main {
    private static final class FastScanner {
        private final byte[] buffer = new byte[1 << 16];
        private int ptr = 0;
        private int len = 0;

        private int read() throws IOException {
            if (ptr >= len) {
                len = System.in.read(buffer);
                ptr = 0;
                if (len <= 0) return -1;
            }
            return buffer[ptr++];
        }

        long nextLong() throws IOException {
            int c;
            do {
                c = read();
            } while (c <= 32);
            long sign = 1;
            if (c == '-') {
                sign = -1;
                c = read();
            }
            long val = 0;
            while (c > 32) {
                val = val * 10 + (c - '0');
                c = read();
            }
            return val * sign;
        }
    }

    public static void main(String[] args) throws Exception {
        FastScanner fs = new FastScanner();
        int n = (int) fs.nextLong();
        long budget = fs.nextLong();
        int maxDiscountable = (int) fs.nextLong();

        long[] prices = new long[n];
        for (int i = 0; i < n; i++) {
            prices[i] = fs.nextLong();
        }

        Arrays.sort(prices);

        long[] prefix = new long[n + 1];
        for (int i = 1; i <= n; i++) {
            prefix[i] = prefix[i - 1] + prices[i - 1];
        }

        int lo = 0;
        int hi = n;
        while (lo < hi) {
            int mid = (lo + hi + 1) >>> 1;
            int m = Math.min(maxDiscountable, mid);
            long totalCost = (prefix[mid] + prefix[mid - m]) >>> 1;
            if (totalCost <= budget) {
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }

        System.out.println(lo);
    }
}