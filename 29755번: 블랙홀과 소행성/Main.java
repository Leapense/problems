import java.io.*;
import java.util.*;

public class Main {
    static class FastScanner {
        private final InputStream in;
        private final byte[] buffer = new byte[1 << 16];
        private int ptr = 0, len = 0;
        FastScanner(InputStream is) { in = is; }
        private int read() throws IOException {
            if (ptr >= len) {
                len = in.read(buffer);
                ptr = 0;
                if (len <= 0) return -1;
            }

            return buffer[ptr++];
        }
        int nextInt() throws IOException {
            int c, sgn = 1, x = 0;
            do { c = read(); } while (c <= ' ');
            if (c == '-') { sgn = -1; c = read(); }
            while (c > ' ') { x = x * 10 + (c - '0'); c = read(); }
            return x * sgn;
        }
    }

    public static void main(String[] args) throws Exception {
        FastScanner fs = new FastScanner(System.in);
        int N = fs.nextInt();
        int M = fs.nextInt();

        int[] B = new int[N];
        for (int i = 0; i < N; i++) B[i] = fs.nextInt();
        Arrays.sort(B);

        long answer = 0L;
        for (int j = 0; j < M; j++) {
            int a = fs.nextInt();
            int w = fs.nextInt();

            int idx = Arrays.binarySearch(B, a);
            long bestDist;
            if (idx >= 0) {
                bestDist = 0;
            } else {
                int ip = -idx - 1;
                long distRight = (ip < N) ? Math.abs((long)B[ip] - a) : Long.MAX_VALUE;
                long distLeft = (ip > 0) ? Math.abs((long)B[ip - 1] - a) : Long.MAX_VALUE;
                bestDist = Math.min(distLeft, distRight);
            }

            long need = bestDist * (long) w;
            if (need > answer) answer = need;
        }

        System.out.println(answer);
    }
}