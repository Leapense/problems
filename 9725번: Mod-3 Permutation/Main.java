import java.io.BufferedInputStream;
import java.io.IOException;
import java.util.StringTokenizer;

public final class Main
{
    private static final int MOD_CLASS_COUNT = 3;
    private static final String PREFIX = "Case #";
    private static final String SEPARATOR = ": ";

    private Main() {

    }

    public static void main(String[] args) throws IOException {
        FastScanner scanner = new FastScanner(System.in);
        StringBuilder outputBuilder = new StringBuilder();

        int testCount = scanner.nextInt();

        for (int caseIdx = 1; caseIdx <= testCount; caseIdx++) {
            int n = scanner.nextInt();
            int[][] matrix = new int[MOD_CLASS_COUNT][MOD_CLASS_COUNT];

            for (int index = 0; index < n; index++)
            {
                int value = scanner.nextInt();
                int row = index % MOD_CLASS_COUNT;
                int col = value % MOD_CLASS_COUNT;
                matrix[row][col]++;
            }

            int swapCount = computeMinimumSwaps(matrix);
            outputBuilder.append(PREFIX).append(caseIdx).append(SEPARATOR).append(swapCount).append("\n");
        }

        System.out.print(outputBuilder.toString());
    }

    private static int computeMinimumSwaps(int[][] countMatrix) {
        int swaps = 0;

        for (int a = 0; a < MOD_CLASS_COUNT; a++)
        {
            for (int b = a + 1; b < MOD_CLASS_COUNT; b++)
            {
                int exchangeable = Math.min(countMatrix[a][b], countMatrix[b][a]);
                swaps += exchangeable;
                countMatrix[a][b] -= exchangeable;
                countMatrix[b][a] -= exchangeable;
            }
        }

        int remainingMisplaced = 0;
        for (int row = 0; row < MOD_CLASS_COUNT; row++) {
            for (int col = 0; col < MOD_CLASS_COUNT; col++) {
                if (row != col) {
                    remainingMisplaced += countMatrix[row][col];
                }
            }
        }

        swaps += (remainingMisplaced / MOD_CLASS_COUNT) * 2;

        return swaps;
    }

    private static final class FastScanner {
        private static final int BUFFER_SIZE = 1 << 16;
        private final byte[] buffer = new byte[BUFFER_SIZE];
        private int bufferPtr;
        private int bytesRead;
        private final BufferedInputStream input;

        FastScanner(java.io.InputStream source) {
            this.input = new BufferedInputStream(source, BUFFER_SIZE);
        }

        int nextInt() throws IOException {
            int number = 0;
            int sign = 1;
            int ch = read();
            while (isWhitespace(ch)) {
                ch = read();
            }
            if (ch == '-') {
                sign = -1;
                ch = read();
            }

            while (!isWhitespace(ch) && ch != -1) {
                number = number * 10 + (ch - '0');
                ch = read();
            }

            return number * sign;
        }

        private int read() throws IOException {
            if (bufferPtr >= bytesRead) {
                bytesRead = input.read(buffer);
                bufferPtr = 0;
                if (bytesRead == -1) {
                    return -1;
                }
            }

            return buffer[bufferPtr++];
        }

        private static boolean isWhitespace(int ch) {
            return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
        }
    }
}