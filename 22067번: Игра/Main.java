import java.io.IOException;
import java.io.InputStream;

public final class Main
{
    private Main() { }
    public static void main(String[] args) throws IOException {
        FastScanner scanner = new FastScanner(System.in);
        int testCases = scanner.nextInt();
        StringBuilder output = new StringBuilder();

        while (testCases-- > 0) {
            int levelCount = scanner.nextInt();
            long[][] length = new long[levelCount + 1][];
            for (int level = 1; level <= levelCount; level++) {
                int size = level << 1;
                length[level] = new long[size];
                for (int idx = 0; idx < size; idx++) {
                    length[level][idx] = scanner.nextLong();
                }
            }

            double[] nextExp = new double[levelCount + 2];
            for (int level = levelCount; level >= 1; level--) {
                double[] current = new double[level + 1];
                long[] row = length[level];
                for (int room = 1; room <= level; room++) {
                    long left = row[(room - 1) << 1];
                    long right = row[((room - 1) << 1) + 1];
                    if (left < right) {
                        current[room] = left + nextExp[room];
                    } else if (left > right) {
                        current[room] = right + nextExp[room + 1];
                    } else {
                        current[room] = 0.5 * (left + nextExp[room]) + 0.5 * (right + nextExp[room + 1]);
                    }
                }

                nextExp = current;
            }
            output.append(String.format("%.10f%n", nextExp[1]));
        }

        System.out.print(output.toString());
    }

    private static final class FastScanner {
        private final byte[] buffer = new byte[1 << 16];
        private final InputStream in;
        private int length;
        private int ptr;

        FastScanner(InputStream in) {
            this.in = in;
        }

        int nextInt() throws IOException {
            return (int) nextLong();
        }

        long nextLong() throws IOException {
            int c;
            do { 
                c = read();
            } while (c <= 32);

            boolean negative = c == '-';
            if (negative) {
                c = read();
            }
            long value = 0;
            while (c > 32) {
                value = (value * 10) + (c - 48);
                c = read();
            }

            return negative ? -value : value;
        }

        private int read() throws IOException {
            if (ptr >= length) {
                length = in.read(buffer);
                ptr = 0;
                if (length == -1) {
                    return -1;
                }
            }

            return buffer[ptr++] & 0xFF;
        }
    }
}