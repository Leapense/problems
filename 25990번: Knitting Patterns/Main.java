import java.io.BufferedInputStream;
import java.io.IOException;
import java.util.Arrays;

public class Main {
    private static final int ALPHABET = 26;
    public static void main(String[] args) throws Exception {
        FastScanner fs = new FastScanner();
        int a = fs.nextInt();
        int b = fs.nextInt();
        int c = fs.nextInt();
        String w = fs.next();
        String p = fs.next();

        int m = w.length();
        int[] idxMap = new int[ALPHABET];
        Arrays.fill(idxMap, -1);
        for (int i = 0; i < m; i++) {
            idxMap[w.charAt(i) - 'a'] = i;
        }
        long[] occ = new long[m];
        int[] lastPos = new int[m];
        Arrays.fill(lastPos, -1);
        long[] gapCostSum = new long[m];

        int n = p.length();
        for (int i = 0; i < n; i++) {
            char ch = p.charAt(i);
            int ci = ch - 'a';
            if (ci < 0 || ci >= ALPHABET) {
                continue;
            }
            int mapIdx = idxMap[ci];
            if (mapIdx < 0) {
                continue;
            }
            occ[mapIdx]++;
            if (lastPos[mapIdx] != -1) {
                int gap = i - lastPos[mapIdx] - 1;
                if (gap > 0) {
                    long keepCost = (long) a * gap;
                    long splitCost = 2L * c;
                    gapCostSum[mapIdx] += Math.min(keepCost, splitCost);
                }
            }
            lastPos[mapIdx] = i;
        }

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < m; i++) {
            if (occ[i] == 0) {
                sb.append(0).append('\n');
            } else {
                long cost = occ[i] * b + 2L * c + gapCostSum[i];
                sb.append(cost).append('\n');
            }
        }

        System.out.print(sb.toString());
    }

    private static final class FastScanner {
        private final BufferedInputStream in;
        private final byte[] buffer;
        private int ptr;
        private int len;

        FastScanner() {
            this.in = new BufferedInputStream(System.in);
            this.buffer = new byte[1 << 16];
            this.ptr = 0;
            this.len = 0;
        }

        private int read() throws IOException {
            if (ptr >= len) {
                len = in.read(buffer);
                ptr = 0;
                if (len <= 0) {
                    return -1;
                }
            }

            return buffer[ptr++];
        }

        String next() throws IOException {
            StringBuilder sb = new StringBuilder();
            int c = read();
            while (c <= 32 && c != -1) {
                c = read();
            }
            while (c > 32 && c != -1) {
                sb.append((char) c);
                c = read();
            }
            return sb.toString();
        }

        int nextInt() throws IOException {
            int c = read();
            while (c <= 32) {
                c = read();
            }
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            int val = 0;
            while (c > 32) {
                val = val * 10 + (c - '0');
                c = read();
            }
            return val * sgn;
        }
    }
}