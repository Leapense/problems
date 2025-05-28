import java.io.*;

public final class Main
{
    private Main() {}

    public static void main(String[] args) throws IOException {
        FastReader reader = new FastReader();
        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

        int testCount = reader.nextInt();
        while (testCount-- > 0) {
            int n = reader.nextInt();
            long tail1 = 0L;
            long tail2 = 0L;
            boolean possible = true;

            for (int i = 0; i < n; i++) {
                int train = reader.nextInt();
                if (!possible) {
                    continue;
                }
                boolean fit1 = tail1 < train;
                boolean fit2 = tail2 < train;

                if (fit1 && fit2) {
                    if (tail1 > tail2) {
                        tail1 = train;
                    } else {
                        tail2 = train;
                    }
                } else if (fit1) {
                    tail1 = train;
                } else if (fit2) {
                    tail2 = train;
                } else {
                    possible = false;
                }
            }

            writer.write(possible ? "TAK\n" : "NIE\n");
        }
        writer.flush();
    }

    private static class FastReader {
        private static final int BUFFER_SIZE = 1 << 16;
        private final DataInputStream dis;
        private final byte[] buffer;
        private int bufferPointer;
        private int bytesRead;

        FastReader() {
            dis = new DataInputStream(System.in);
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = 0;
            bytesRead = 0;
        }

        int nextInt() throws IOException {
            int result = 0;
            byte c = read();
            while (c <= ' ') {
                c = read();
            }

            boolean negative = false;
            if (c == '-') {
                negative = true;
                c = read();
            }
            do {
                result = result * 10 + (c - '0');
                c = read();
            } while (c >= '0' && c <= '9');

            return negative ? -result : result;
        }

        private byte read() throws IOException {
            if (bufferPointer == bytesRead) {
                bytesRead = dis.read(buffer, 0, BUFFER_SIZE);
                bufferPointer = 0;
                if (bytesRead == -1) {
                    return -1;
                }
            }

            return buffer[bufferPointer++];
        }
    }
}