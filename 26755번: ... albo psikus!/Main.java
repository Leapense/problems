import java.io.BufferedInputStream;
import java.io.IOException;

public class Main {
    private static final int BUFFER_SIZE = 1 << 16;
    private static final class FastScanner {
        private final BufferedInputStream in = new BufferedInputStream(System.in, BUFFER_SIZE);
        private final byte[] buffer = new byte[BUFFER_SIZE];
        private int ptr = 0;
        private int len = 0;

        private int read() throws IOException {
            if (ptr >= len) {
                len = in.read(buffer);
                ptr = 0;
                if (len <= 0) return -1;
            }
            return buffer[ptr++];
        }

        long nextLong() throws IOException {
            int c;
            do {
                c = read();
            } while (c <= 32 && c != -1);

            boolean neg = false;
            if (c == '-') {
                neg = true;
                c = read();
            }

            long val = 0;
            while (c > 32 && c != -1) {
                val = val * 10 + (c - '0');
                c = read();
            }

            return neg ? -val : val;
        }
    }

    private static long combinations2(long x) {
        return x <= 1 ? 0L : x * (x - 1) / 2;
    }

    public static void main(String[] args) throws Exception {
        FastScanner fs = new FastScanner();
        long n = fs.nextLong();
        long evenCount = 1;
        long oddCount = 0;
        int parity = 0;
        for (long i = 0; i < n; i++) {
            long v = fs.nextLong();
            parity ^= (int)(v & 1L);
            if (parity == 0) {
                evenCount++;
            } else {
                oddCount++;
            }
        }

        long result = combinations2(evenCount) + combinations2(oddCount);
        System.out.println(result);
    }
}