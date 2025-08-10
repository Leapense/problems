import java.io.IOException;
import java.util.ArrayDeque;

public class Main {
    private static final class FastScanner {
        private final byte[] buffer = new byte[1 << 16];
        private int ptr = 0;
        private int len = 0;

        private int read() throws IOException {
            if (ptr >= len) {
                len = System.in.read(buffer);
                ptr = 0;
                if (len <= 0) {
                    return -1;
                }
            }
            return buffer[ptr++];
        }

        int nextInt() throws IOException {
            int c, sgn = 1, x = 0;
            do { 
                c = read();
            } while (c <= 32);

            if (c == '-') {
                sgn = -1;
                c = read();
            }
            while (c > 32) {
                x = x * 10 + (c - '0');
                c = read();
            }
            return x * sgn;
        }
    }

    public static void main(String[] args) throws Exception {
        FastScanner fs = new FastScanner();
        int n = fs.nextInt();
        int[] a = new int[n];
        int minA = Integer.MAX_VALUE;
        int maxA = Integer.MIN_VALUE;
        for (int i = 0; i < n; i++) {
            a[i] = fs.nextInt();
            if (a[i] < minA) {
                minA = a[i];
            }
            if (a[i] > maxA) {
                maxA = a[i];
            }
        }

        long low = 0L;
        long high = (long)(n - 1) * (1L + (long)maxA - (long)minA);
        while (low < high) {
            long mid = (low + high) >>> 1;
            if (canReach(a, mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        System.out.println(low);
    }

    private static boolean canReach(int[] a, long k) {
        int n = a.length;
        boolean[] visited = new boolean[n];
        ArrayDeque<Integer> q = new ArrayDeque<>();
        visited[0] = true;
        q.add(0);
        while (!q.isEmpty()) {
            int i = q.pollFirst();
            if (i == n - 1) {
                return true;
            }

            long maxD = Math.min(k, (long)(n - 1 - i));
            if (maxD <= 0) {
                continue;
            }
            for (int d = 1; d <= maxD; d++) {
                int j = i + d;
                if (visited[j]) {
                    continue;
                }
                long diff = Math.abs((long) a[i] - (long) a[j]);
                long cost = (long) d * (1L + diff);
                if (cost <= k) {
                    visited[j] = true;
                    q.addLast(j);
                    if (j == n - 1) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
}