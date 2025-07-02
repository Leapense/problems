import java.io.BufferedInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.TreeSet;

public class Main {
    private static final int NOT_FOUND = -1;

    public static void main(String[] args) throws IOException {
        FastScanner scanner = new FastScanner(System.in);
        StringBuilder outputBuilder = new StringBuilder();

        int nodeCount = scanner.nextInt();
        int queryCount = scanner.nextInt();

        for (int i = 2; i <= nodeCount; i++) {
            scanner.nextInt();
        }

        TreeSet<Integer> violinTimelines = new TreeSet<>();

        for (int i = 0; i < queryCount; i++) {
            int queryType = scanner.nextInt();
            int index = scanner.nextInt();

            if (queryType == 1) {
                violinTimelines.add(index);
            } else {
                if (violinTimelines.isEmpty()) {
                    outputBuilder.append(NOT_FOUND).append('\n');
                } else {
                    Integer ceilingValue = violinTimelines.ceiling(index);
                    Integer floorValue = violinTimelines.floor(index);
                    int bestDistance = Integer.MAX_VALUE;

                    if (ceilingValue != null) {
                        bestDistance = Math.min(bestDistance, Math.abs(ceilingValue - index));
                    }
                    if (floorValue != null) {
                        bestDistance = Math.min(bestDistance, Math.abs(index - floorValue));
                    }
                    outputBuilder.append(bestDistance).append('\n');
                }
            }
        }

        System.out.print(outputBuilder.toString());
    }

    private static final class FastScanner {
        private static final int BUFFER_SIZE = 1 << 16;
        private final byte[] buffer = new byte[BUFFER_SIZE];
        private int bufferPointer;
        private int bytesRead;
        private final InputStream stream;

        FastScanner(InputStream stream) {
            this.stream = new BufferedInputStream(stream, BUFFER_SIZE);
        }

        int nextInt() throws IOException {
            int character;
            do {
                character = read();
            } while (character <= ' ');

            boolean negative = false;
            if (character == '-') {
                negative = true;
                character = read();
            }

            int value = 0;
            while (character > ' ') {
                value = value * 10 + character - '0';
                character = read();
            }
            return negative ? -value : value;
        }

        private int read() throws IOException {
            if (bufferPointer >= bytesRead) {
                bytesRead = stream.read(buffer);
                bufferPointer = 0;
                if (bytesRead <= 0) {
                    return -1;
                }
            }
            return buffer[bufferPointer++];
        }
    }
}