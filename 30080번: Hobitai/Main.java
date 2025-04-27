import java.io.BufferedInputStream;
import java.io.IOException;
import java.io.InputStream;

public class Main {
    public static void main(String[] args) throws Exception {
        FastScanner fs = new FastScanner(System.in);

        int n = fs.nextInt();
        byte[] s = fs.nextBytes(n);

        int[] lastEnd = new int[256];
        int[] cnt = new int[256];

        initializeLastEnd(lastEnd);

        int mask = computeInitialMask(s);

        cnt[mask] = 1;
        lastEnd[mask] = 7;

        updateMaskAndCount(s, n, lastEnd, cnt, mask);

        int best = 0, bestServed = 0;
        bestServed = findBestServed(cnt, best);

        StringBuilder pattern = createPattern(best);

        System.out.println(bestServed);
        System.out.println(pattern.toString());
    }

    private static void initializeLastEnd(int[] lastEnd) {
        for (int i = 0; i < 256; i++) {
            lastEnd[i] = -8;
        }
    }

    private static int computeInitialMask(byte[] s) {
        int mask = 0;
        for (int i = 0; i < 8; i++) {
            mask = (mask << 1) | (s[i] == '0' ? 1 : 0);
        }
        return mask;
    }

    private static void updateMaskAndCount(byte[] s, int n, int[] lastEnd, int[] cnt, int mask) {
        for (int i = 1; i + 7 < n; i++) {
            mask = ((mask << 1) & 0xFF) | (s[i + 7] == 'O' ? 1 : 0);
            if (i >= lastEnd[mask] - 7) {
                cnt[mask]++;
                lastEnd[mask] = i + 7;
            }
        }
    }

    private static int findBestServed(int[] cnt, int best) {
        int bestServed = 0;
        for (int p = 0; p < 256; p++) {
            int served = cnt[p] << 3;
            if (served > bestServed) {
                bestServed = served;
                best = p;
            }
        }
        return bestServed;
    }

    private static StringBuilder createPattern(int best) {
        StringBuilder pattern = new StringBuilder(8);
        for (int bit = 7; bit >= 0; bit--) {
            pattern.append(((best >> bit) & 1) == 1 ? 'O' : 'H');
        }
        return pattern;
    }

    private static class FastScanner {
        private final byte[] buf = new byte[1 << 16];
        private int len, ptr;
        private final InputStream in;

        FastScanner(InputStream in) {
            this.in = in;
        }

        private int readByte() throws IOException {
            if (ptr >= len) {
                len = in.read(buf);
                ptr = 0;
                if (len <= 0) {
                    return -1;
                }
            }
            return buf[ptr++];
        }

        int nextInt() throws IOException {
            int c, sign = 1, val = 0;
            while ((c = readByte()) <= ' ')
                ;

            if (c == '-') {
                sign = -1;
                c = readByte();
            }
            while (c > ' ') {
                val = val * 10 + (c - '0');
                c = readByte();
            }
            return val * sign;
        }

        byte[] nextBytes(int n) throws IOException {
            byte[] out = new byte[n];
            int idx = 0, c;
            while ((c = readByte()) <= ' ')
                ;
            while (idx < n && shouldContinueReading(c)) {
                out[idx++] = (byte) c;
                c = readByte();
            }

            return out;
        }

        private boolean shouldContinueReading(int c) {
            return c != -1 && c != '\n' && c != '\r';
        }
    }
}