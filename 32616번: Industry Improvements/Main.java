import java.io.*;
import java.util.*;

public class Main {
    private static int n, k;
    private static long[] w;

    private static boolean feasible(long cap) {
        int runs = 1;
        long load = 0;
        for (long box : w) {
            if (box > cap)
                return false;
            if (load + box > cap) {
                runs++;
                load = 0;
            }
            load += box;
        }

        return runs <= k;
    }

    public static void main(String[] args) throws IOException { // throws Exception -> throws IOException
        FastScanner fs = new FastScanner(System.in);

        n = fs.nextInt();
        k = fs.nextInt();

        w = new long[n];
        long low = 0;
        long high = 0;

        for (int i = 0; i < n; i++) {
            w[i] = fs.nextLong();
            low = Math.max(low, w[i]);
            high += w[i];
        }

        long left = low, right = high, ans = high;
        while (left <= right) {
            long mid = left + (right - left) / 2;
            if (feasible(mid)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        System.out.println(ans);
    }

    private static final class FastScanner {
        private final byte[] buffer = new byte[1 << 16];
        private int len = 0, ptr = 0;
        private final InputStream in;

        FastScanner(InputStream inputStream) { // Proper constructor
            this.in = inputStream;
        }

        private int readByte() throws IOException { // Method to read a single byte
            if (ptr >= len) {
                ptr = 0;
                len = this.in.read(buffer);
                if (len <= 0) { // Handle EOF or error (0 bytes read)
                    return -1; // Signal EOF
                }
            }
            return buffer[ptr++];
        }

        long nextLong() throws IOException {
            int c = readByte();
            // Skip leading whitespace and check for EOF
            while (c != -1 && c <= ' ') {
                c = readByte();
            }
            if (c == -1) {
                throw new EOFException("End of file reached before reading number.");
            }

            boolean neg = false;
            if (c == '-') {
                neg = true;
                c = readByte();
                if (c == -1) {
                    throw new EOFException("End of file reached after reading sign '-' for a number.");
                }
            }

            if (c < '0' || c > '9') { // Check if the first char is a digit
                throw new InputMismatchException("Current character is not a digit: " + (char) c);
            }

            long val = 0;
            while (c >= '0' && c <= '9') { // Read digits
                val = val * 10 + (c - '0');
                c = readByte();
            }
            return neg ? -val : val;
        }

        int nextInt() throws IOException {
            return (int) nextLong();
        }
    }
}