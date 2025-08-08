import java.io.IOException;
import java.io.InputStream;

public class Main {
    private static final int BUFFER_SIZE = 1 << 16;
    private static final char ZERO_CHAR = '0';

    private static final class FastScanner {
        private final InputStream in;
        private final byte[] buffer = new byte[BUFFER_SIZE];
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

            return buffer[ptr++] & 0xFF;
        }

        private boolean isSpace(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t';
        }

        String next() throws IOException {
            StringBuilder sb = new StringBuilder();
            int c;
            do { 
                c = read();
                if (c == -1) {
                    return sb.length() == 0 ? null : sb.toString();
                }
            } while (isSpace(c));
            while (c != -1 && !isSpace(c)) {
                sb.append((char) c);
                c = read();
            }

            return sb.toString();
        }

        int nextInt() throws IOException {
            int c;
            do { 
                c = read();
            } while (c != -1 && isSpace(c));

            int sign = 1;
            if (c == '-') {
                sign = -1;
                c = read();
            }

            int val = 0;
            while (c != -1 && !isSpace(c)) {
                val = val * 10 + (c - '0');
                c = read();
            }

            return val * sign;
        }
    }

    public static void main(String[] args) throws IOException {
        FastScanner fs = new FastScanner(System.in);
        int rows = fs.nextInt();
        int cols = fs.nextInt();

        char[][] digits = new char[rows][];
        for (int i = 0; i < rows; i++) {
            String s = fs.next();
            digits[i] = s.toCharArray();
        }

        int[] f = new int[rows];
        int[] nextF = new int[rows];
        int[] out = new int[rows];
        int bestStored = 0;

        for (int col = 0; col < cols; col++) {
            for (int row = 0; row < rows; row++) {
                int stored = f[row];
                int weight = digits[row][col] - ZERO_CHAR;
                out[row] = stored + weight;
                if (stored > bestStored) {
                    bestStored = stored;
                }
            }
            for (int row = 0; row < rows; row++) {
                int val = f[row];
                int currentOut = out[row];
                if (currentOut > val) {
                    val = currentOut;
                }
                if (row > 0 && out[row - 1] > val) {
                    val = out[row - 1];
                }
                if (row + 1 < rows && out[row + 1] > val) {
                    val = out[row + 1];
                }
                nextF[row] = val;
            }

            int[] tmp = f;
            f = nextF;
            nextF = tmp;
        }
        System.out.println(bestStored);
    }
}