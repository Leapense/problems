import java.io.BufferedInputStream;
import java.io.PrintWriter;

public class Main
{
    private static final int BUF_SIZE = 1 << 16;
    static final class FastScanner {
        private final byte[] buf = new byte[BUF_SIZE];
        private int len, ptr;
        private final BufferedInputStream in = new BufferedInputStream(System.in, BUF_SIZE);
        private int readByte() {
            if (ptr >= len) {
                try {
                    len = in.read(buf);
                    ptr = 0;
                } catch (Exception ignored) {

                }
                if (len <= 0) {
                    return -1;
                }
            }

            return buf[ptr++];
        }

        int nextInt() {
            int c, sign = 1, val = 0;
            do {
                c = readByte();
            } while (c <= ' ');
            if (c == '-') {
                sign = -1;
                c = readByte();
            }

            while (c > ' ') {
                val = val * 10 + c - '0';
                c = readByte();
            }

            return val * sign;
        }
    }

    public static void main(String[] args) {
        FastScanner fs = new FastScanner();
        int n = fs.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = fs.nextInt();
        }

        int[] prefix = new int[n];
        int max = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] > max) {
                max = a[i];
            }
            prefix[i] = max;
        }

        int[] suffix = new int[n + 1];
        max = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (a[i] > max) {
                max = a[i];
            }
            suffix[i] = max;
        }

        long red = 0;
        long blue = 0;
        for (int i = 0; i < n - 1; i++) {
            int leftMax = prefix[i];
            int rightMax = suffix[i + 1];
            if (leftMax > rightMax) {
                red++;
            } else if (leftMax < rightMax) {
                blue++;
            }
        }

        try (PrintWriter out = new PrintWriter(System.out)) {
            if (red > blue) {
                out.println('R');
            } else if (blue > red) {
                out.println('B');
            } else {
                out.println('X');
            }
        }
    }
}