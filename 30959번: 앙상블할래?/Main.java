import java.io.*;

public class Main {
    static class FastScanner {
        private final InputStream in;
        private final byte[] buffer = new byte[1 << 16];
        private int ptr = 0, len = 0;

        FastScanner(InputStream is) {
            in = is;
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
            do {
                c = read();
                if (c == -1) return Integer.MIN_VALUE;
            } while (c <= ' ');

            if (c == '-') {
                sign = -1;
                c = read();
            }
            while (c > ' ') {
                val = val * 10 + (c - '0');
                c = read();
            }

            return val * sign;
        }
    }

    public static void main(String[] args) throws Exception {
        FastScanner fs = new FastScanner(System.in);
        int N = fs.nextInt();
        int M = fs.nextInt();
        if (N == Integer.MIN_VALUE || M == Integer.MIN_VALUE) return;

        int[] truth = new int[M];
        for (int j = 0; j < M; j++) truth[j] = fs.nextInt();

        int[][] preds = new int[N][M];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                preds[i][j] = fs.nextInt();
            }
        }

        int bestSingleMatches = 0;
        for (int i = 0; i < N; i++) {
            int matches = 0;
            for (int j = 0; j < M; j++) {
                if (preds[i][j] == truth[j]) matches++;
            }
            if (matches > bestSingleMatches) bestSingleMatches = matches;
        }

        if (bestSingleMatches == M) {
            System.out.println(0);
            return;
        }

        if (N < 3) {
            System.out.println(0);
            return;
        }

        int[] onesMask = new int[M];

        for (int j = 0; j < M; j++) {
            int mask = 0;
            for (int i = 0; i < N; i++) {
                if (preds[i][j] == 1) mask |= (1 << i);
            }

            onesMask[j] = mask;
        }

        int totalMasks = 1 << N;
        int[] popcount = new int[totalMasks];
        for (int mask = 1; mask < totalMasks; mask++) {
            popcount[mask] = popcount[mask & (mask - 1)] + 1;
        }

        for (int mask = 0; mask < totalMasks; mask++) {
            int k = popcount[mask];
            if ((k & 1) == 0 || k < 3) continue;

            int threshold = k >> 1;
            int matches = 0;
            
            for (int j = 0; j < M; j++) {
                int ones = Integer.bitCount(onesMask[j] & mask);
                int pred = (ones > threshold) ? 1 : 0;
                if (pred == truth[j]) matches++;
            }

            if (matches > bestSingleMatches) {
                System.out.println(1);
                return;
            }
        }

        System.out.println(0);
    }
}