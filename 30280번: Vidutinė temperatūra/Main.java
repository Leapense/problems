import java.io.BufferedInputStream;
import java.util.Arrays;

public class Main {
    private static final int BUFFER_SIZE = 1 << 20;

    public static void main(String[] args) throws Exception {
        FastScanner fs = new FastScanner();
        int N = fs.nextInt();

        byte[] line = fs.nextLineBytes(N);

        int offset = N;
        int[] first = new int[2 * N + 1];
        Arrays.fill(first, -2);
        first[offset] = 0;

        int sum = 0, answer = 0;
        for (int i = 0; i < N; i++) {
            sum += (line[i] == '+') ? 1 : -1;
            int idx = sum + offset;
            if (first[idx] == -2) {
                first[idx] = i + 1;
            } else {
                int len = (i + 1) - first[idx];
                if (len > answer)
                    answer = len;
            }
        }

        System.out.println(answer);
    }

    private static class FastScanner {
        private final byte[] buf = new byte[BUFFER_SIZE];
        private int len = 0, ptr = 0;

        private int readByte() throws Exception {
            if (ptr >= len) {
                len = System.in.read(buf);
                ptr = 0;
                if (len <= 0)
                    return -1;
            }
            return buf[ptr++];
        }

        int nextInt() throws Exception {
            int c, sign = 1, num = 0;
            while ((c = readByte()) <= ' ')
                ;
            if (c == '-' || c == '+') {
                sign = (c == '-') ? -1 : 1;
                c = readByte();
            }
            for (; c > ' '; c = readByte())
                num = num * 10 + (c & 15);
            return num * sign;
        }

        // 읽어야 할 길이를 아는 경우 바로 byte[] 반환
        byte[] nextLineBytes(int expectedLen) throws Exception {
            byte[] out = new byte[expectedLen];
            int read = 0, c;
            while (read < expectedLen && (c = readByte()) != -1) {
                if (c == '\n' || c == '\r')
                    continue; // skip LF/CR
                out[read++] = (byte) c;
            }
            return out;
        }
    }
}