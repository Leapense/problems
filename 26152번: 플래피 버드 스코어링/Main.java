import java.io.IOException;
import java.io.InputStream;

public class Main {
    private static final InputStream INPUT = System.in;
    private static final byte[] BUFFER = new byte[1 << 16];
    private static int ptr = 0;
    private static int len = 0;

    private static int read() throws IOException {
        if (ptr >= len) {
            len = INPUT.read(BUFFER);
            ptr = 0;
            if (len <= 0) return -1;
        }
        return BUFFER[ptr++];
    }

    private static long nextLong() throws IOException {
        int c = read();
        while (c <= 32) {
            if (c == -1) return Long.MIN_VALUE;
            c = read();
        }
        int sign = 1;
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

    private static int rightmostGe(long[] arr, long w) {
        int lo = 0;
        int hi = arr.length - 1;
        int ans = -1;
        while (lo <= hi) {
            int mid = (lo + hi) >>> 1;
            if (arr[mid] >= w) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return ans + 1;
    }

    public static void main(String[] args) throws Exception {
        int n = (int) nextLong();
        long[] a = new long[n];
        for (int i = 0; i < n; i++) a[i] = nextLong();
        long[] pmin = new long[n];

        for (int i = 0; i < n; i++) {
            long b = nextLong();
            long gap = a[i] - b;
            if (i == 0) pmin[i] = gap;
            else pmin[i] = Math.min(pmin[i - 1], gap);
        }

        int q = (int) nextLong();
        StringBuilder out = new StringBuilder();
        for (int i = 0; i < q; i++) {
            long w = nextLong();
            int score = rightmostGe(pmin, w);
            out.append(score).append('\n');
        }

        System.out.print(out.toString());
    }
}