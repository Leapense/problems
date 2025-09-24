import java.io.*;

public class Main {
    static final String FIRST_WIN = "mnx";
    static final String SECOND_WIN = "alsdkffhgk";

    public static void main(String[] args) throws Exception {
        FastScanner fs = new FastScanner(System.in);

        int N = fs.nextInt();
        int[] A = new int[N + 1];
        for (int i = 1; i <= N; i++) {
            A[i] = fs.nextInt();
        }

        int k = 0;
        int idx = 2;
        while (idx <= N && A[idx] == 1) {
            k++;
            idx++;
        }

        if (k % 2 == 0) {
            System.out.println(FIRST_WIN);
        } else {
            System.out.println(SECOND_WIN);
        }
    }

    static class FastScanner {
        private final InputStream in;
        private final byte[] buffer = new byte[1 << 16];
        private int ptr = 0, len = 0;

        FastScanner(InputStream is) {
            this.in = is;
        }

        private int read() throws IOException {
            if (ptr >= len) {
                len = in.read(buffer);
                ptr = 0;
                if (len <= 0) return -1;
            }

            return buffer[ptr++];
        }

        int nextInt() throws IOException {
            int c, sign = 1, val = 0;
            do c = read(); while (c <= ' ');
            if (c == '-') { sign = -1; c = read(); }
            for (; c > ' '; c = read()) {
                val = val * 10 + (c - '0');
            }

            return val * sign;
        }
    }
}