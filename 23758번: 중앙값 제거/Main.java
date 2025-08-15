import java.io.BufferedInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;

public class Main {
    private static final int BUFFER_SIZE = 1 << 20;
    public static void main(String[] args) throws IOException {
        FastScanner scanner = new FastScanner(System.in);
        int n = scanner.nextInt();
        int[] values = new int[n];
        for (int i = 0; i < n; i++) {
            values[i] = scanner.nextInt();
        }

        Arrays.sort(values);
        int k = (n + 1) / 2;
        long sumFloorLog2 = 0L;
        for (int i = 0; i < k; i++) {
            sumFloorLog2 += floorLog2(values[i]);
        }

        long result = sumFloorLog2 + 1;
        System.out.println(result);
    }

    private static int floorLog2(int x) {
        return Integer.SIZE - 1 - Integer.numberOfLeadingZeros(x);
    }

    private static final class FastScanner {
        private final InputStream in;
        private final byte[] buffer;
        private int ptr;
        private int len;

        FastScanner(InputStream input) {
            this.in = new BufferedInputStream(input, BUFFER_SIZE);
            this.buffer = new byte[BUFFER_SIZE];
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
            int c;
            do { 
                c = read();
                if (c == -1) {
                    return -1;
                }
            } while (c <= 32);

            int sign = 1;
            if (c == '-') {
                sign = -1;
                c = read();
            }

            int value = 0;
            while (c > 32) {
                value = value * 10 + (c - 48);
                c = read();
            }

            return value * sign;
        }
    }
}