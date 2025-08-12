import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;

public class Main {
    private static final int SCALE = 5;

    private static final class FastScanner {
        private final InputStream in;
        private final byte[] buffer = new byte[1 << 16];
        private int ptr = 0;
        private int len = 0;

        FastScanner(InputStream in) {
            this.in = in;
        }

        private int read() throws IOException {
            if (ptr >= len) {
                len = in.read(buffer);
                ptr = 0;
                if (len <= 0) {
                    return -1;
                }
            }
            return buffer[ptr++];
        }

        int nextInt() throws IOException {
            int c = read();
            while (c <= 32) {
                if (c == -1) {
                    return Integer.MIN_VALUE;
                }
                c = read();
            }
            int sign = 1;
            if (c == '-') {
                sign = -1;
                c = read();
            }
            int val = 0;
            while (c > 32) {
                val = val * 10 + (c - 48);
                c = read();
            }
            return val * sign;
        }
    }

    private static int lowerBound(long[] arr, long target) {
        int lo = 0;
        int hi = arr.length;
        while (lo < hi) {
            int mid = (lo + hi) >>> 1;
            if (arr[mid] >= target) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }

    public static void main(String[] args) throws IOException {
        FastScanner fs = new FastScanner(System.in);
        int n = fs.nextInt();
        int k = fs.nextInt();
        long[] thicknessScaled = new long[n];
        long current = 0L;
        for (int i = 0; i < n; i++) {
            int a = fs.nextInt();
            current += -(long) a;
            if (current < 0L) {
                current = 0L;
            }
            thicknessScaled[i] = current;
        }
        int[] required = new int[k];
        for (int j = 0; j < k; j++) {
            required[j] = fs.nextInt();
        }
        long[] sorted = Arrays.copyOf(thicknessScaled, n);
        Arrays.sort(sorted);
        StringBuilder sb = new StringBuilder();
        for (int j = 0; j < k; j++) {
            long threshold = (long) SCALE * (long) required[j];
            int idx = lowerBound(sorted, threshold);
            int count = n - idx;
            if (j > 0) {
                sb.append(' ');
            }
            sb.append(count);
        }
        System.out.println(sb.toString());
    }
}