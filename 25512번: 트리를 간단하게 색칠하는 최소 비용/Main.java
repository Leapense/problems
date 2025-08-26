import java.io.BufferedInputStream;
import java.io.IOException;
import java.io.InputStream;

public final class Main {
    private static final int BUFFER_SIZE = 1 << 16;
    private static final int ROOT_INDEX = 0;

    private static final class FastScanner {
        private final BufferedInputStream in;
        private final byte[] buffer = new byte[BUFFER_SIZE];
        private int bufferPointer = 0;
        private int bytesRead = 0;

        FastScanner(InputStream is) {
            this.in = new BufferedInputStream(is, BUFFER_SIZE);
        }

        private int read() throws IOException {
            if (bufferPointer >= bytesRead) {
                bytesRead = in.read(buffer);
                bufferPointer = 0;
                if (bytesRead <= 0) {
                    return -1;
                }
            }

            return buffer[bufferPointer++];
        }

        int nextInt() throws IOException {
            int ch = read();
            while (ch <= ' ') {
                if (ch == -1) {
                    return Integer.MIN_VALUE;
                }
                ch = read();
            }
            int sign = 1;
            if (ch == '-') {
                sign = -1;
                ch = read();
            }
            int val = 0;
            while (ch > ' ') {
                val = val * 10 + (ch - '0');
                ch = read();
            }

            return val * sign;
        }
    }

    public static void main(String[] args) throws IOException {
        FastScanner scanner = new FastScanner(System.in);
        int n = scanner.nextInt();
        if (n <= 0) {
            return;
        }

        int edgeCount = n - 1;
        int[] edgesParent = new int[edgeCount];
        int[] edgesChild = new int[edgeCount];
        int[] outDegree = new int[n];

        for (int i = 0; i < edgeCount; i++) {
            int p = scanner.nextInt();
            int c = scanner.nextInt();
            edgesParent[i] = p;
            edgesChild[i] = c;
            outDegree[p]++;
        }

        long[] whiteCost = new long[n];
        long[] blackCost = new long[n];
        for (int i = 0; i < n; i++) {
            whiteCost[i] = scanner.nextInt();
            blackCost[i] = scanner.nextInt();
        }
        int[] childrenStart = new int[n];
        int total = 0;
        for (int i = 0; i < n; i++) {
            childrenStart[i] = total;
            total += outDegree[i];
        }

        int[] writeIndex = new int[n];
        System.arraycopy(childrenStart, 0, writeIndex, 0, n);
        int[] childrenFlat = new int[edgeCount];
        for (int i = 0; i < edgeCount; i++) {
            int p = edgesParent[i];
            int c = edgesChild[i];
            childrenFlat[writeIndex[p]++] = c;
        }

        long[] dpWhite = new long[n];
        long[] dpBlack = new long[n];
        int[] stack = new int[n];
        int sp = 0;
        stack[sp++] = ROOT_INDEX;
        int[] order = new int[n];
        int oi = 0;
        while (sp > 0) {
            int u = stack[--sp];
            order[oi++] = u;
            int begin = childrenStart[u];
            int end = begin + outDegree[u];
            for (int idx = begin; idx < end; idx++) {
                int v = childrenFlat[idx];
                stack[sp++] = v;
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            int u = order[i];
            long sumWhite = whiteCost[u];
            long sumBlack = blackCost[u];
            int begin = childrenStart[u];
            int end = begin + outDegree[u];
            for (int idx = begin; idx < end; idx++) {
                int v = childrenFlat[idx];
                sumWhite += dpBlack[v];
                sumBlack += dpWhite[v];
            }

            dpWhite[u] = sumWhite;
            dpBlack[u] = sumBlack;
        }

        long answer = Math.min(dpWhite[ROOT_INDEX], dpBlack[ROOT_INDEX]);
        StringBuilder sb = new StringBuilder();
        sb.append(answer);
        System.out.print(sb.toString());
    }
}